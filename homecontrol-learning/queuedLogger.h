#pragma once
#include <memory>
#include <string>
#include "ilogger.h"

class queuedLogger : public ilogger {

public:
	queuedLogger();
	~queuedLogger();

	//implementation of ilogger
	void logg(const std::wstring& str) override;

private:
	std::unique_ptr<class queuedLoggerImpl>	m_ImplQueuedLogger;
};



