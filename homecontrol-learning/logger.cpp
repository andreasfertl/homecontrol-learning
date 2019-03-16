#include <iostream>
#include <string>
#include "logger.h"

logger::logger()
{
}

void logger::logg(const std::wstring& str)
{
	std::wcout << str;
}
