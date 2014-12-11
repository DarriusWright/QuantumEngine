#pragma once

#include <Manager.h>

class MemoryManager : public Manager
{
public:
	~MemoryManager();
	static MemoryManager & getInstance()
	{
		static MemoryManager memoryManager;
		return memoryManager;
	}

	void update()override;
	bool startUp()override;
	bool shutDown()override;

private:
	MemoryManager();
};

