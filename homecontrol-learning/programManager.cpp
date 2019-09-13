#include <thread>
#include <chrono>
#include <atomic>
#include "programManager.h"
#include "consoleLogger.h"
#include "logger.h"
#include "logging.h"
#include "seriealizeFunctions.h"
#include "thread.h"
#include "iTread.h"
#include "SimpleLogger.h"
#include "queuedLogger.h"


class programManagerImpl {

public:
	programManagerImpl() :
		m_Run(true),
		m_SimpleLogger(),
		m_ConsoleLogger(),
		m_QueuedLogger(),
		m_MyLogger(m_SimpleLogger),
		manyThreads()
	{
		_logg(m_MyLogger, L"Startup");

		for (unsigned int threadcount = 0; threadcount < 10; threadcount++) {
			manyThreads.emplace_back([this]() {
				_logg(m_MyLogger, "From Thread ID : " << std::this_thread::get_id());
			});
		}
	}

	~programManagerImpl() {
		for (auto& thread : manyThreads) {
			if (thread.joinable())
				thread.join();
		}
	}

	void run()
	{
		auto startupTime = std::chrono::system_clock::now();

		while (m_Run) {
			auto runningSince = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startupTime);
			_logg(m_MyLogger, L"Running since: " << runningSince.count() << L" milliseconds");

			std::this_thread::sleep_for(std::chrono::seconds(2));

			if (runningSince >= std::chrono::seconds(12))
				stop();
		}
	}

	void stop()
	{
		_logg(m_MyLogger, L"Stopping");
		m_Run = false;
	}

private:
	std::atomic<bool>   m_Run;
	simpleLogger        m_SimpleLogger;
	consoleLogger		m_ConsoleLogger;
	queuedLogger        m_QueuedLogger;
	ilogger&            m_MyLogger;
	std::vector<std::thread> manyThreads;
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
