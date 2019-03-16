#pragma once
#include <memory>

class programManager
{
public:
	programManager();
	~programManager();

	void run();
	void stop();

private:
	std::unique_ptr<class programManagerImpl> m_ProgramManager;
};

