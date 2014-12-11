#include <windows.h>
#include <iostream>
#include <sstream>
#include <QtWidgets\qapplication.h>

#include "GameEditor.h"
#include <Scripting\LuaStateManager.h>



// Direct registered function
void HelloWorld()
{
	std::cout <<"LUA : " << "Hello world!" << std::endl;
}



int main(int argc, char * argv [])
{
	// Create a new lua state and load all default lua libraries
	
	QApplication app(argc, argv);
	GameEditor editor;

	LUA->startUp();
	LUA->registerFunctionDirect("HelloWorld", HelloWorld);
	LUA->executeScript("LuaScripts/test.lua");
	LuaPlus::LuaFunction<float> LuaSquare = LUA->getLuaObject("Square");
	LUA->executeScript("LuaScripts/script.lua");

	editor.show();

	return app.exec();
}


//#include <QtWidgets\qwidget.h>
//#include <QtWidgets\qapplication.h>
//#include <Entities\GameObject.h>
//#include <Components\TransformComponent.h>
//#include <vector>
//#include <iostream>
//
//#include <luacppinterface.h>
//
//
//Lua lua;
//bool LUALOADER() {
//	lua.LoadStandardLibraries();
//	return true;
//}
//bool loaded = LUALOADER();
//
//void runLua(std::string toRun) {
//	std::string ret = lua.RunScript(toRun);
//	if (ret != Lua::NO_ERRORS) {
//		std::cout << ret << std::endl;
//	}
//}
//
//int main()
//{
//
//	//lua.GetGlobalEnvironment().Set("print",
//	//	lua.CreateFunction<void(std::string)>)
//	runLua("print('potato')");
//}

/*
#pragma comment(lib, "lua5.1.lib")

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

using namespace luabridge;


int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	QWidget widget;
	widget.show();
	
	lua_State * L = luaL_newstate();
	luaL_dofile(L, "script.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	LuaRef s = getGlobal(L, "testString");
	LuaRef n = getGlobal(L, "number");
	std::string luaString = s.cast<std::string>();
	int answer = n.cast<int>();
	//std::cout << luaString << std::endl;
	//std::cout << "And here's our number:" << answer << std::endl;

	return app.exec();
}*/