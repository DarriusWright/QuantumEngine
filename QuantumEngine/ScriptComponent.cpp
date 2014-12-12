#include "ScriptComponent.h"
#include <Entities\GameObject.h>

RTTI_DEFINITIONS(ScriptComponent)

ScriptComponent::ScriptComponent(GameObject * gameObject,std::string filePath) : Component(gameObject),filePath(filePath)
{
}


ScriptComponent::~ScriptComponent()
{
}


void ScriptComponent::update()
{
	LUA->executeScript(filePath.c_str());
	
}

void ScriptComponent::setPath(std::string path)
{
	filePath = path;
}
std::string ScriptComponent::getPath()
{
	return filePath;
}