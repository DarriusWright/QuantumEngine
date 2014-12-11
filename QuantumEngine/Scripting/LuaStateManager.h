#pragma once
#include "ScriptManager.h"
#include <LuaPlus.h>
#include <LuaObject.h>
#include <windows.h>
#include <iostream>
#include <sstream>
using namespace LuaPlus;

#ifdef _DEBUG
#pragma comment( lib, "..\\Debug\\LUAPlus.lib")
#else
#pragma comment( lib, "..\\Release\\LUAPlus.lib")
#endif
#include <LuaPlus.h>
using namespace LuaPlus;

#define LUA LuaStateManager::getInstance();




class LuaStateManager  : public ScriptManager
{



public:
	~LuaStateManager();
	static LuaStateManager * getInstance()
	{
		static LuaStateManager * luaManager = new LuaStateManager();
		return luaManager;
	}

	template <typename Func>
	void registerFunctionDirect(const char * name, Func function)
	{
		globals.RegisterDirect(name, function);
	}

	template <typename Func>
	void registerFunction(const char * name, Func function)
	{
		globals.Register(name, function);
	}

	void executeScript(const char * filename);
	void executeScript(const char * filename, const char * errorMessage);
	void executeSource(const char * filename);
	void executeSource(const char * filename, const char * errorMessage);
	void update()override;
	bool startUp()override;
	bool shutDown()override;
	

protected :
	LuaStateManager();
	LuaObject globals;
	LuaState * luaState;
	// Registered function MUST always have this signature (int (funcName) (LuaPlus::LuaState*))
private:
	int Print(LuaPlus::LuaState* luaState)
	{
		// Get the argument count
		int top = pState->GetTop();

		std::stringstream output;
		for (int i = 1; i <= top; ++i)
		{
			// Retrieve all arguments, if possible they will be converted to strings
			output << "LUA : " << pState->CheckString(i) << std::endl;
		}
		std::cout << output.str();

		// We don't return any values to the script
		return 0;
	}
	


};

