#pragma once
#include "ScriptManager.h"
#include <LuaPlus.h>
#include <LuaObject.h>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <ExportHeader.h>
using namespace LuaPlus;

#ifdef _DEBUG
#pragma comment( lib, "..\\Debug\\LUAPlus.lib")
#else
#pragma comment( lib, "..\\Release\\LUAPlus.lib")
#endif
#include <LuaPlus.h>
using namespace LuaPlus;

#define LUA LuaStateManager::getInstance()




class LuaStateManager  : public ScriptManager
{
	RTTI_DECLARATIONS(LuaStateManager, ScriptManager)

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

	template <class Caller>
	void registerFunction(const char * name, Caller & caller, int (Caller::*func)(LuaState*))
	{
		globals.Register(name, caller, func);
	}

	ENGINE_SHARED void executeScript(const char * filename);
	ENGINE_SHARED void executeScript(const char * filename, const char * errorMessage);
	ENGINE_SHARED void executeSource(const char * filename);
	ENGINE_SHARED void executeSource(const char * filename, const char * errorMessage);
	ENGINE_SHARED LuaObject getLuaObject(const char * name);
	ENGINE_SHARED void update()override;
	ENGINE_SHARED bool startUp()override;
	ENGINE_SHARED bool shutDown()override;
	

protected :
	ENGINE_SHARED LuaStateManager();
	LuaObject globals;
	LuaState * luaState;
	// Registered function MUST always have this signature (int (funcName) (LuaPlus::LuaState*))
private:
	int Print(LuaPlus::LuaState* luaState)
	{
		// Get the argument count
		int top = luaState->GetTop();

		std::stringstream output;
		for (int i = 1; i <= top; ++i)
		{
			// Retrieve all arguments, if possible they will be converted to strings
			output << "LUA : " << luaState->CheckString(i) << std::endl;
		}
		std::cout << output.str();

		// We don't return any values to the script
		return 0;
	}
	


};

