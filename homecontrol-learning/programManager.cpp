#include <thread>
#include <chrono>
#include <atomic>
#include "programManager.h"
#include "logger.h"
#include "logging.h"


class programManagerImpl {

public:
	programManagerImpl() :
		m_LoggManager(),
		m_Run(true)
	{
		_logg(m_LoggManager, L"Startup");
	}

	void run()
	{
		auto startupTime = std::chrono::system_clock::now();

		while (m_Run) {
			auto runningSince = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startupTime);
			_logg(m_LoggManager, L"Running since: " << runningSince.count() << L" milliseconds");

			std::this_thread::sleep_for(std::chrono::seconds(2));

			if (runningSince >= std::chrono::seconds(12))
				stop();
		}
	}

	void stop()
	{
		_logg(m_LoggManager, L"Stopping");
		m_Run = false;
	}

private:
	logger            m_LoggManager;
	std::atomic<bool> m_Run;
};


//------------------------------------------------------------------------------------------------------------------------

programManager::programManager() :
	m_ProgramManager(std::make_unique<programManagerImpl>())
{
}

programManager::~programManager()
{
}

void programManager::run()
{
	m_ProgramManager->run();
}

void programManager::stop()
{
	m_ProgramManager->stop();
}
