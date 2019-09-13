#pragma once
#include <iostream>
#include <string>
#include "ilogger.h"

struct simpleLogger : public ilogger {

	//implementation of ilogger
	void logg(const std::wstring& str) override {
		std::wcout << str;
	};


};
