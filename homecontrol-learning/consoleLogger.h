#pragma once
#include <iostream>
#include <string>
#include "ilogger.h"
#include <vector>
#include <thread>
#include <functional>
#include <atomic>

struct consoleLogger : public ilogger {

	consoleLogger() : 
		m_StringsToPrint(),
		m_Run(true),
		m_PrintThread(std::bind(&consoleLogger::PrintThread, this)) {
	}

	~consoleLogger() {
		m_Run = false;
		if (m_PrintThread.joinable())
			m_PrintThread.join();
	}

	//implementation of ilogger
	void logg(const std::wstring& str) override {
		m_StringsToPrint.push_back(str);  
	};

private:
	void PrintThread() {
		while (m_Run) {
			for (auto& str : m_StringsToPrint) {
				std::wcout << str;
			}
			m_StringsToPrint.clear();

			std::this_thread::yield();
		}
	}

	std::vector<std::wstring> m_StringsToPrint;
	std::atomic<bool>         m_Run;
	std::thread				  m_PrintThread;

};
