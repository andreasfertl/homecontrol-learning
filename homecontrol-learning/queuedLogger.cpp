#include <iostream>
#include "seriealizeFunctions.h"
#include "queuedLogger.h"

namespace {
	//[1] one specific function
	//void printme(const std::wstring& str) {
	//	std::wcout << str;
	//}

	//[3] functor
	//class testPrinter {
	//	public:
	//		testPrinter() = default;
	//		~testPrinter() = default;

	//		void operator()(const std::wstring& str) {
	//			std::wcout << str;
	//		};
	//};
}


class queuedLoggerImpl : public ilogger {

public:
	queuedLoggerImpl() :
		m_SerializeFunctions() {
	}

	~queuedLoggerImpl() {
	}

	//[2] one specific class function
	//void print(const std::wstring& str) {
	//	std::wcout << str;
	//}

	//implementation of ilogger
	void logg(const std::wstring& str) override {
		//[1] one specific function
		//m_SerializeFunctions.run(std::bind(printme, str));

		//[2] one specific class function
		//m_SerializeFunctions.run(std::bind(&queuedLoggerImpl::print, this, str));

		//[3] functor
		//{
		//	testPrinter testPrinterClassInstance;
		//	testPrinterClassInstance(str);
		//	m_SerializeFunctions.run(std::bind(&testPrinter::operator(), testPrinterClassInstance, str));
		//}

		//[4] lambda
		//auto functionToPrintString = [str]() {
		//	std::wcout << str; 
		//};
		//m_SerializeFunctions.run(functionToPrintString);

		m_SerializeFunctions.run([str]() {
			std::wcout << str;
		});

	};

private:
	seriealizeFunctions	m_SerializeFunctions;
};



queuedLogger::queuedLogger() :
	m_ImplQueuedLogger(std::make_unique<queuedLoggerImpl>())
{
}

queuedLogger::~queuedLogger()
{
}

void queuedLogger::logg(const std::wstring& str) {
	m_ImplQueuedLogger->logg(str);
}







