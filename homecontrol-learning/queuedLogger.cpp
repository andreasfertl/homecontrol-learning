#pragma once
#include <iostream>
#include "seriealizeFunctions.h"
#include "queuedLogger.h"

class queuedLoggerImpl : public ilogger {

public:
	queuedLoggerImpl() :
		m_SerializeFunctions() {
	}

	~queuedLoggerImpl() {
	}

	//implementation of ilogger
	void logg(const std::wstring& str) override {
		m_SerializeFunctions.run([str]() {
			std::wcout << str;
		});
	};

private:
	seriealizeFunctions	m_SerializeFunctions;
};



queuedLogger::queuedLogger() :
	m_ImplQueuedLogger(std::make_unique<queuedLoggerImpl>())
{
}

queuedLogger::~queuedLogger()
{
}

void queuedLogger::logg(const std::wstring& str) {
	m_ImplQueuedLogger->logg(str);
}







