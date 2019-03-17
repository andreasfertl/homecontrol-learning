#include <thread>
#include <chrono>
#include <atomic>
#include "programManager.h"
#include "logger.h"
#include "logging.h"
#include "seriealizeFunctions.h"
#include "iRun.h"

namespace {

	class unorderdFunctionCalls : public iRun {
	public:
		//implementation of iRun
		void run(const std::function<void()>&& func) override { func(); };
		void run(const std::function<void()>& func) override { func(); };
	};

	std::wstring getThreadId() {
		std::wstringstream wss;
		std::this_thread::get_id()._To_text(wss);

		return wss.str();
	}
}


class programManagerImpl {

public:
	programManagerImpl() :
		m_Run(true),
		m_SerializeFunctionCalls(),
		m_UnorderdFunctionCalls(),
		m_LoggManager(m_UnorderdFunctionCalls)
	{
		_logg(m_LoggManager, L"Startup");


		std::vector<std::thread> threads;
		//spawn threads
		for (int i = 0; i < 10; i++)
		{
			threads.emplace_back([this]() {
				_logg(this->m_LoggManager, L"Printout from thread id: " + getThreadId());
			});
		}


		// join/wait for the end of the threads
		for (auto& t : threads)
			t.join();
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
	unorderdFunctionCalls m_UnorderdFunctionCalls;
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
