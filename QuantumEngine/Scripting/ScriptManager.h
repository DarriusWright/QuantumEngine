#pragma once

#include <Manager.h>


class ScriptManager : public Manager
{
	RTTI_DECLARATIONS(ScriptManager, Manager);

public:

	ENGINE_SHARED ScriptManager();
	virtual ~ScriptManager() ;
	virtual bool startUp() ;
	virtual bool shutDown() ;
	virtual void update();
};

