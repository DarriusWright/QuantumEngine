#pragma once

#include <Components\Component.h>

class GameObject;
class ScriptComponent : public Component
{
	RTTI_DECLARATIONS(ScriptComponent, Component)

public:
	ENGINE_SHARED ScriptComponent(GameObject * gameObject, std::string filePath);
	ENGINE_SHARED virtual ~ScriptComponent();
	ENGINE_SHARED virtual void  initialize() override;
	ENGINE_SHARED virtual void update() override;
//	ENGINE_SHARED void setPath(std::string path);
	ENGINE_SHARED std::string getPath();

protected:
	std::string filePath;
};

