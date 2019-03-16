#pragma once
#include "ilogger.h"

class logger: public ilogger {

public:
	logger();

	//implementation of ilogger
	void logg(const std::wstring& str) override;
};
