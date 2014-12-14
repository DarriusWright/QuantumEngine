#pragma once
class Manager
{
public:
	Manager();
	~Manager();

	virtual bool startUp() = 0;
	virtual bool shutDown() = 0;
	virtual void update() = 0;


protected:
	
};

