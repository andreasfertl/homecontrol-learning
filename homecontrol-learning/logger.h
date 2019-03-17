#pragma once
#include "ilogger.h"

class logger: public ilogger {

public:
	logger(struct iRun& IRun);

	//implementation of ilogger
	void logg(const std::wstring& str) override;

private:
	struct iRun& m_SerializeFunctionCalls;

};
