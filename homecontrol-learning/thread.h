#pragma once
#include <thread>
#include <atomic>

class thread
{
public:
	thread(struct iThread& iThread);
	~thread();

private:
	void threadHandler();

	struct iThread&		m_IThread;
	std::atomic<bool>   m_Run;
	//queue<message>		m_ReceiveQueue;
	//queue<message>		m_SendQueue;
	std::thread			m_Thread;
};

