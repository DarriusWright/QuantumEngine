#include "LuaStateManager.h"

RTTI_DEFINITIONS(LuaStateManager)
/*
+ -------------- + ---- - +
| BLACK | 0 |
| BLUE | 1 |
| GREEN | 2 |
| CYAN | 3 |
| RED | 4 |
| MAGENTA | 5 |
| BROWN | 6 |
| LIGHTGREY | 7 |
| DARKGREY | 8 |
| LIGHTBLUE | 9 |
| LIGHTGREEN | 10 |
| LIGHTCYAN | 11 |
| LIGHTRED | 12 |
| LIGHTMAGENTA | 13 |
| YELLOW | 14 |
| WHITE | 15 |
| BLINK | 128 |
+-------------- + ---- - +
*/

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
	
	if (luaL_loadfile(luaState, filename) || lua_pcall(luaState, 0, 0, 0))
	{
		system("COLOR 4");
		std::cout << "Error : " << filename << ", script does not exist. " << std::endl;
		system("COLOR 0");
	}
	
}
void LuaStateManager::executeScript(const char * filename, const char * errorMessage)
{
	if (luaL_loadfile(luaState, filename) || lua_pcall(luaState, 0, 0, 0))
	{
		system("COLOR 4");
		std::cout << errorMessage << std::endl;
		system("COLOR 0");
	}
}
void LuaStateManager::executeSource(const char * filename, const char * errorMessage)
{
	if (luaL_loadstring(luaState, filename) || lua_pcall(luaState, 0, 0, 0))
	{
		system("COLOR 4");
		std::cout << errorMessage << std::endl;
		system("COLOR 0");
	}
}
void LuaStateManager::executeSource(const char * filename)
{
	if (luaL_loadstring(luaState, filename) || lua_pcall(luaState, 0, 0, 0))
	{
		system("COLOR 4");
		std::cout << "Error : " << "source failed to execute " << std::endl;
		system("COLOR 0");
	}
}

bool LuaStateManager::startUp()
{
	luaState = nullptr;
	luaState = luaL_newstate();
	luaL_openlibs(luaState);
	Namespace ref = getGlobalNamespace(luaState);
	
	getGlobalNamespace(luaState).addFunction("printMessage", &LuaStateManager::Print);
	return true;
}

bool LuaStateManager::shutDown()
{
	//LuaPlus::LuaState::Destroy(luaState);
	//luaState = nullptr;

	return true;
}
