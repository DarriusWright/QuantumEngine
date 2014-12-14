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

}

void ScriptComponent::initialize()
{

}

std::string ScriptComponent::getPath()
{
	return filePath;
}