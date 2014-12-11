#include "LuaStateManager.h"

RTTI_DEFINITIONS(LuaStateManager)

LuaStateManager::LuaStateManager()
{
}


LuaStateManager::~LuaStateManager()
{
}

void LuaStateManager::update()
{

}

void LuaStateManager::executeScript(const char * filename)
{
	if (luaState->DoFile(filename))
	{
		// An error occured
		if (luaState->GetTop() == 1)
			std::cout << "An error occured: " << luaState->CheckString(1) << std::endl;
	}
}
void LuaStateManager::executeScript(const char * filename, const char * errorMessage)
{
	if (luaState->DoFile(filename))
	{
		// An error occured
		if (luaState->GetTop() == 1)
			std::cout << errorMessage << luaState->CheckString(1) << std::endl;
	}
}
void LuaStateManager::executeSource(const char * filename, const char * errorMessage)
{
	if (luaState->DoString(filename))
	{
		// An error occured
		if (luaState->GetTop() == 1)
			std::cout << errorMessage << luaState->CheckString(1) << std::endl;
	}
}
void LuaStateManager::executeSource(const char * filename)
{
	if (luaState->DoString(filename))
	{
		// An error occured
		if (luaState->GetTop() == 1)
			std::cout << "An error occured: " << luaState->CheckString(1) << std::endl;
	}
}

bool LuaStateManager::startUp()
{
	luaState = LuaPlus::LuaState::Create(true);
	globals = luaState->GetGlobals();
	globals.Register("Print", *this, &LuaStateManager::Print);
	return true;
}

bool LuaStateManager::shutDown()
{
	LuaPlus::LuaState::Destroy(luaState);
	luaState = nullptr;

	return true;
}

LuaObject LuaStateManager::getLuaObject(const char * name)
{
	return luaState->GetGlobal(name);
}
