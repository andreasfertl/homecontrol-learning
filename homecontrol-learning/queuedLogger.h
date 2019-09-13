#pragma once
#include <iostream>
#include <string>
#include "ilogger.h"
#include <vector>
#include <thread>
#include <functional>
#include <atomic>
#include "seriealizeFunctions.h"

struct queuedLogger : public ilogger {

	queuedLogger() :
		m_SerializeFunctions(),
		m_StringsToPrint() {
	}

	~queuedLogger() {
	}

	//implementation of ilogger
	void logg(const std::wstring& str) override {
		m_SerializeFunctions.run([this, str]() {
				std::wcout << str;
		});
	};

private:
	seriealizeFunctions       m_SerializeFunctions;
	std::vector<std::wstring> m_StringsToPrint;

};
