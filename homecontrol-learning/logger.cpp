#include <iostream>
#include <string>
#include "logger.h"
#include "iRun.h"
#include <sstream>
#include <thread>

namespace {
	std::wstring getThreadId() {
		std::wstringstream wss;
		std::this_thread::get_id()._To_text(wss);

		return wss.str();
	}
}

logger::logger(struct iRun& IRun) :
	m_SerializeFunctionCalls(IRun)
{
}

void logger::logg(const std::wstring& str)
{
	m_SerializeFunctionCalls.run([str]() {
		std::wcout << L"called from threadId: " << getThreadId() << L" " << str;
	});
}
