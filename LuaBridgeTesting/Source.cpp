#include <windows.h>
#include <sstream>


#include <glm.hpp>
#include <iostream>

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

#include <LuaBridge.h>

using namespace luabridge;




lua_State * luaState = luaL_newstate();


void  Print(const std::string & s)
{
	std::cout << "LUA : " << s << std::endl;
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void checkForErrors(int state)
{
	if (state != 0)
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "Error : " << lua_tostring(luaState, state) << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
}

void executeScript(const char * filename)
{
	int state = luaL_dofile(luaState, filename);
	checkForErrors(state);
	if (state == 0) lua_pcall(luaState, 0, 0, 0);

}


struct Vec3Helper
{
	template <unsigned int index> static float get(glm::vec3 const * vec)
	{
		return vec->x; // [index];//[index];
	}

	template <unsigned int index> static void set(glm::vec3 * vec, float value)
	{
		vec->x = value;
	}
};


void main()
{

	luaL_openlibs(luaState);
	getGlobalNamespace(luaState).addFunction("printMessage", Print);
	getGlobalNamespace(luaState).beginNamespace("math").beginClass<glm::vec3>("vec3").addProperty("x", &Vec3Helper::get<0>, &Vec3Helper::set<0>).endClass().endNamespace();//.addProperty("x", &Vec3Helper::get<0>, &Vec3Helper::set<0>)
	executeScript("LuaScripts/test.lua");
	system("pause");
}