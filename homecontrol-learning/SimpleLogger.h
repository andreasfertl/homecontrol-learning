#pragma once
#include <iostream>
#include <string>
#include "ilogger.h"

class simpleLogger : public ilogger {
public:
	//implementation of ilogger
	void logg(const std::wstring& str) override {
		std::wcout << str;
	};

};
