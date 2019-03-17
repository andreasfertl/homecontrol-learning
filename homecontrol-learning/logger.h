#pragma once
#include "ilogger.h"
#include "seriealizeFunctions.h"

class logger: public ilogger {

public:
	logger();

	//implementation of ilogger
	void logg(const std::wstring& str) override;

private:
	seriealizeFunctions m_SerializeFunctionCalls;

};
