#include <functional>
#include <chrono>
#include "thread.h"
#include "iTread.h"


thread::thread(struct iThread& iThread) :
	m_IThread(iThread),
	m_Run(true),
	m_Thread(std::bind(&thread::threadHandler, this))
{
}

thread::~thread()
{
	m_Run = false;
	m_Thread.join();
}

void thread::threadHandler()
{
	while (m_Run)
	{
		m_IThread.ThreadCallback();
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}
