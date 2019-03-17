#include <iostream>
#include <string>
#include "logger.h"
#include "iRun.h"

logger::logger(struct iRun& IRun) :
	m_SerializeFunctionCalls(IRun)
{
}

void logger::logg(const std::wstring& str)
{
	m_SerializeFunctionCalls.run([str]() {
		std::wcout << str;
	});
}
