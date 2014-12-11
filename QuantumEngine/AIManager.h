#pragma once
#include <Manager.h>
class AIManager : public Manager
{
public:
	AIManager();
	~AIManager();


	void update()override;
	bool startUp()override;
	bool shutDown()override;

private:

};

