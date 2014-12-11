#pragma once

#include <Manager.h>
class PhysicsManager  : public Manager
{
public:
	PhysicsManager();
	~PhysicsManager();
	void update()override;
	bool startUp()override;
	bool shutDown()override;
};

