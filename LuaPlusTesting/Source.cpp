#include <windows.h>
#include <iostream>
#include <sstream>
#include "..\\LuaPlusLib\\LuaPlus.h"
#ifdef _DEBUG
#pragma comment( lib, "..\\Debug\\LUAPlus.lib")
#else
#pragma comment( lib, "..\\Release\\LUAPlus.lib")
#endif
#include <LuaObject.h>

using namespace LuaPlus;

// Direct registered function
void HelloWorld()
{
	std::cout << "Hello world!" << std::endl;
}

// Registered function MUST always have this signature (int(funcName) (LuaPlus::LuaState*))
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

int main()
{
	// Create a new lua state and load all default lua libraries
	LuaPlus::LuaState* pState = LuaPlus::LuaState::Create(true);

	// Get the global object of our state so that we can register global functions
	LuaPlus::LuaObject globals = pState->GetGlobals();

	// Register our HelloWorld() function directly to lua
	globals.RegisterDirect("HelloWorld", HelloWorld);

	// Register our Print() function to lua
	globals.Register("printMessage", Print);

	if (pState->DoFile("LuaScripts/test.lua"))
	{
		// An error occured
		if (pState->GetTop() == 1)
			std::cout << "An error occured: " << pState->CheckString(1) << std::endl;
	}
	
	LuaObject positionTable = globals.GetByName("positionVec");
	LuaObject x = positionTable["x"];
	float value;
	if (x.IsNumber())
	{
		value = x.GetFloat();
	}

	x.AssignNumber(pState, 5.0f);

	if (pState->DoFile("LuaScripts/test.lua"))
	{
		// An error occured
		if (pState->GetTop() == 1)
			std::cout << "An error occured: " << pState->CheckString(1) << std::endl;
	}

	positionTable = globals.GetByName("positionVec");
	x = positionTable["x"];
	float value;
	if (x.IsNumber())
	{
		value = x.GetFloat();
	}


	// Clean-up
	LuaPlus::LuaState::Destroy(pState);
	pState = nullptr;

	getchar();
	return 0;
}