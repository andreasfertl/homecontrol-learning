#pragma once
#include <string>

struct ilogger {
	virtual void logg(const std::wstring& str) = 0;
};
