#include <windows.h>
#include <iostream>
#include <sstream>
#include <QtWidgets\qapplication.h>

#include "GameEditor.h"
#ifdef _DEBUG
#pragma comment( lib, "..\\Debug\\LUAPlus.lib")
#else
#pragma comment( lib, "..\\Release\\LUAPlus.lib")
#endif
#include <LuaPlus.h>
using namespace LuaPlus;


// Direct registered function
void HelloWorld()
{
	std::cout <<"LUA : " << "Hello world!" << std::endl;
}

// Registered function MUST always have this signature (int (funcName) (LuaPlus::LuaState*))
int Print(LuaPlus::LuaState* pState)
{
	// Get the argument count
	int top = pState->GetTop();

	std::stringstream output;
	for (int i = 1; i <= top; ++i)
	{
		// Retrieve all arguments, if possible they will be converted to strings
		output <<"LUA : " << pState->CheckString(i) << std::endl;
	}
	std::cout << output.str();

	// We don't return any values to the script
	return 0;
}

int main(int argc, char * argv [])
{
	// Create a new lua state and load all default lua libraries
	LuaPlus::LuaState* pState = LuaPlus::LuaState::Create(true);
	QApplication app(argc, argv);
	GameEditor editor(pState);

	// Get the global object of our state so that we can register global functions
	LuaPlus::LuaObject globals = pState->GetGlobals();

	// Register our HelloWorld() function directly to lua
	globals.RegisterDirect("HelloWorld", HelloWorld);

	// Register our Print() function to lua
	globals.Register("Print", Print);

	
	
	if (pState->DoFile("LuaScripts/test.lua"))
	{
		// An error occured
		if (pState->GetTop() == 1)
			std::cout << "An error occured: " << pState->CheckString(1) << std::endl;
	}
	LuaPlus::LuaFunction<float> LuaSquare = pState->GetGlobal("Square");
	float result = LuaSquare(5);
	std::cout << "C++" << result << std::endl;
	//LuaPlus::LuaObject positionTable = globals.GetByName("positionVec");
	//globals.SetString("phrase", "Hi There I am a changed string");

	if (pState->DoFile("LuaScripts/script.lua"))
	{
		// An error occured
		if (pState->GetTop() == 1)
			std::cout << "An error occured: " << pState->CheckString(1) << std::endl;
	}


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