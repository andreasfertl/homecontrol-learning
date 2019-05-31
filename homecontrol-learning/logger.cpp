#include <iostream>
#include <string>
#include "logger.h"
#include "iRun.h"
#include "ilogger.h"

logger::logger(struct ilogger& iLogger) :
	m_ILogger(iLogger),
	m_Context()
{
}

void logger::logg(const std::wstring& str)
{
	m_Context.run([this, str]() {
		this->m_ILogger.logg(str);
	});
}
