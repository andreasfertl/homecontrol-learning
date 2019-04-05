#pragma once
#include "ilogger.h"

class logger : public ilogger {

public:
	logger(struct ilogger& iLogger, struct iRun& IRun);

	//implementation of ilogger
	void logg(const std::wstring& str) override;

private:
	struct ilogger& m_ILogger;
	struct iRun&    m_Context;

};
