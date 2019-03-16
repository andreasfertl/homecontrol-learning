#include "programManager.h"
#include <thread>
#include <chrono>
#include "logging.h"

programManager::programManager() :
	m_Run(true),
	m_LoggManager()
{
	_logg(m_LoggManager, L"Startup");
}

void programManager::run()
{
	auto startupTime = std::chrono::system_clock::now();

	while (m_Run) {
		auto runningSince = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startupTime);
		_logg(m_LoggManager, L"Running since: " << runningSince.count() << L" milliseconds");

		std::this_thread::sleep_for(std::chrono::seconds(10));
	}
}

void programManager::stop()
{
	_logg(m_LoggManager, L"Stop");
	m_Run = false;
}

