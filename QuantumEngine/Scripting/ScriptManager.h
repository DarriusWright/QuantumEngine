#pragma once

#include <Manager.h>

class ScriptManager : public Manager
{
public:
	ENGINE_SHARED ScriptManager();
	ENGINE_SHARED virtual ~ScriptManager() ;
	ENGINE_SHARED virtual bool startUp() ;
	ENGINE_SHARED virtual bool shutDown() ;
	ENGINE_SHARED virtual void update();

};

