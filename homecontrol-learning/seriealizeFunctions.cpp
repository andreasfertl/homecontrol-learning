#include "seriealizeFunctions.h"



seriealizeFunctions::seriealizeFunctions() :
	m_Stop(false),
	m_Queue(),
	m_Event(),
	m_RunThread(&seriealizeFunctions::handler, this)
{
}

seriealizeFunctions::~seriealizeFunctions()
{
	run([this]() { this->m_Stop = true; });
	m_RunThread.join();
}

void seriealizeFunctions::run(const std::function<void()>&& func)
{
	{
		std::lock_guard<std::mutex> lk(m_Event.m_Mutex);
		m_Queue.push(std::move(func));
	}
	m_Event.m_Condition.notify_one();
}

void seriealizeFunctions::run(const std::function<void()>& func)
{
	{
		std::lock_guard<std::mutex> lk(m_Event.m_Mutex);
		m_Queue.push(func);
	}
	m_Event.m_Condition.notify_one();
}


void seriealizeFunctions::handler()
{
	while (!m_Stop)
	{
		std::unique_lock<std::mutex> lk(m_Event.m_Mutex);
		m_Event.m_Condition.wait(lk, [this]() { return !this->m_Queue.empty(); });
		//clear the queue
		while (!m_Queue.empty())
		{
			m_Queue.front()();
			m_Queue.pop();
		}
	}
}



