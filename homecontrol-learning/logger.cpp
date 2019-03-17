#include <iostream>
#include <string>
#include "logger.h"

logger::logger()
{
}

void logger::logg(const std::wstring& str)
{
	m_SerializeFunctionCalls.run([str]() { std::wcout << str; });
}
