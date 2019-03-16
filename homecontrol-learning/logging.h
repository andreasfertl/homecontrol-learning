#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include "ilogger.h"

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)


#define _logg(_ilogger, _message) {                                                                                         \
							std::wostringstream messageStream, printStream;                                                 \
							messageStream << _message;                                                                      \
							printStream << __FILENAME__ << L" Line:" << __LINE__ << L" " << messageStream.str() << L"\r\n"; \
							_ilogger.logg(printStream.str());                                                               \
					   }


