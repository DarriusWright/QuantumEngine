#pragma once

#include <Components\ScriptComponent.h>
#include <LuaObject.h>
#include <Scripting\LuaStateManager.h>


class LuaScriptComponent : public ScriptComponent
{
public:
	ENGINE_SHARED LuaScriptComponent(GameObject * gameObject, std::string filePath,std::string className);
	ENGINE_SHARED ~LuaScriptComponent() override;

protected:
	LuaObject scriptObject;
	std::string luaClassName;
};

