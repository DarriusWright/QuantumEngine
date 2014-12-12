#pragma once

#include <Components\Component.h>
#include <Scripting\LuaStateManager.h>

class GameObject;
class ScriptComponent : public Component
{
	RTTI_DECLARATIONS(ScriptComponent, Component)

public:
	ENGINE_SHARED ScriptComponent(GameObject * gameObject, std::string filePath);
	ENGINE_SHARED ~ScriptComponent();
	ENGINE_SHARED virtual void update();
	ENGINE_SHARED void setPath(std::string path);
	ENGINE_SHARED std::string getPath();

private:
	std::string filePath;
};

