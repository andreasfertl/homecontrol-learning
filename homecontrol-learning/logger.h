#pragma once
#include "ilogger.h"
#include "seriealizeFunctions.h"

class logger : public ilogger {

public:
	logger(struct ilogger& iLogger);

	//implementation of ilogger
	void logg(const std::wstring& str) override;

private:
	struct ilogger&		 m_ILogger;
	seriealizeFunctions  m_Context;

};
