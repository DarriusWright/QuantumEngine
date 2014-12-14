#include "LuaScriptComponent.h"


LuaScriptComponent::LuaScriptComponent(GameObject * gameObject, std::string filePath, std::string className) : ScriptComponent(gameObject, filePath),
luaClassName(className)
{
	

	LUA->registerInstance<GameObject>(gameObject, scriptObject, className);

}


LuaScriptComponent::~LuaScriptComponent()
{
}
