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


void LuaStateManager::checkForErrors(int state)
{
	/*if (state != 0)
	{
		system("COLOR 4");
		std::cout << "Error : " << lua_tostring(luaState,state) << std::endl;
		system("COLOR 0");
	}*/
}

void LuaStateManager::executeScript(const char * filename)
{
	if (luaState->DoFile(filename))
	{
		// An error occured
		if (luaState->GetTop() == 1)
			std::cout << "An error occured: " << luaState->CheckString(1) << std::endl;
	}
	/*int state = luaL_dofile(luaState, filename);
	checkForErrors(state);
	if (state == 0) lua_pcall(luaState, 0, 0, 0);
	*/
}
void LuaStateManager::executeScript(const char * filename, const char * errorMessage)
{
	/*int state = luaL_dofile(luaState, filename);
	checkForErrors(state);
	if (state == 0) lua_pcall(luaState, 0, 0, 0);*/
}
void LuaStateManager::executeSource(const char * source, const char * errorMessage)
{
	//int state = luaL_dostring(luaState, source);
	//checkForErrors(state);
	//if (state == 0) lua_pcall(luaState, 0, 0, 0);
	if (luaState->DoString(source))
	{
		// An error occured
		if (luaState->GetTop() == 1)
			std::cout << "An error occured: " << luaState->CheckString(1) << std::endl;
	}
}
void LuaStateManager::executeSource(const char * source)
{
	/*int state = luaL_dostring(luaState, source);
	checkForErrors(state);
	if (state == 0) lua_pcall(luaState, 0, 0, 0);*/
}

bool LuaStateManager::startUp()
{
	//luaState = nullptr;
	//luaState = luaL_newstate();
	//luaL_openlibs(luaState);
	////Namespace ref = getGlobalNamespace(luaState);
	//getGlobalNamespace(luaState).addFunction("printMessage", &LuaStateManager::Print);
	//getGlobalNamespace(luaState).beginNamespace("math").beginClass<glm::vec3>("vec3").addProperty("x", &Vec3Helper::get<0>, &Vec3Helper::set<0>).endClass();//.addProperty("x", &Vec3Helper::get<0>, &Vec3Helper::set<0>)
	luaState = LuaState::Create(true);
	globals = luaState->GetGlobals();
	globals.Register("printMessage", &LuaStateManager::Print);


	return true;
}

bool LuaStateManager::shutDown()
{
	//LuaPlus::LuaState::Destroy(luaState);
	//luaState = nullptr;

	// Clean-up
	LuaPlus::LuaState::Destroy(luaState);
	luaState = nullptr;

	return true;
}
