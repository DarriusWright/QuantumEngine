#pragma once

#include <Manager.h>


class ScriptManager : public Manager
{
	RTTI_DECLARATIONS(ScriptManager, Manager);

public:

	ENGINE_SHARED ScriptManager();
	ENGINE_SHARED virtual ~ScriptManager() = 0;
};

