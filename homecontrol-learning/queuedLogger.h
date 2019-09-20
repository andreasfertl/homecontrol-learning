#pragma once
#include <iostream>
#include <string>
#include "ilogger.h"
#include <functional>
#include "seriealizeFunctions.h"

struct queuedLogger : public ilogger {

	queuedLogger() :
		m_SerializeFunctions() {
	}

	~queuedLogger() {
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



