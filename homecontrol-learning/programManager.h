#pragma once
#include <atomic>
#include "logger.h"

class programManager
{
public:
	programManager();

	void run();
	void stop();

private:
	std::atomic<bool> m_Run;
	logger            m_LoggManager;
};

