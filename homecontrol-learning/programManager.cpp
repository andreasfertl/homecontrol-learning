#include <thread>
#include <chrono>
#include <atomic>
#include "programManager.h"
#include "consoleLogger.h"
#include "logger.h"
#include "logging.h"
#include "seriealizeFunctions.h"

class programManagerImpl {

public:
	programManagerImpl() :
		m_Run(true),
		m_SerializeFunctionCalls(),
		m_ConsoleLogger(),
		m_LoggManager(m_ConsoleLogger, m_SerializeFunctionCalls)
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
	std::atomic<bool>   m_Run;
	seriealizeFunctions m_SerializeFunctionCalls;
	consoleLogger		m_ConsoleLogger;
	logger              m_LoggManager;

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
