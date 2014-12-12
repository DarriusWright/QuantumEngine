#pragma once
#include "ScriptManager.h"
#include <windows.h>
#include <sstream>
#include <ExportHeader.h>


#include <LuaBridge.h>
#include <iostream>

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

#define LUA LuaStateManager::getInstance()

using namespace luabridge;





class LuaStateManager  : public ScriptManager
{
	RTTI_DECLARATIONS(LuaStateManager, ScriptManager)

public:

	static void  Print(const std::string & s)
	{
		std::cout << "LUA : " << s << std::endl;
	}
	~LuaStateManager();
	static LuaStateManager * getInstance()
	{
		static LuaStateManager * luaManager = new LuaStateManager();
		return luaManager;
	}

	template <typename Func>
	void registerFunction(const char * name, Func function)
	{
		//globals.Register(name, function);
		getGlobalNamespace(luaState).addFunction(name,function);

	}

	template<class T>
	T getMember()
	{

	}

	//template <class Caller>
	//void registerFunction(const char * name, Caller & caller, int (Caller::*func)(LuaState*))
	//{
	//	globals.Register(name, caller, func);
	//}

	ENGINE_SHARED void executeScript(const char * filename);
	ENGINE_SHARED void executeScript(const char * filename, const char * errorMessage);
	ENGINE_SHARED void executeSource(const char * filename);
	ENGINE_SHARED void executeSource(const char * filename, const char * errorMessage);
	//ENGINE_SHARED LuaObject getLuaObject(const char * name);
	ENGINE_SHARED void update()override;
	ENGINE_SHARED bool startUp()override;
	ENGINE_SHARED bool shutDown()override;
	

protected :
	ENGINE_SHARED LuaStateManager();
	lua_State * luaState;
	//LuaObject globals;
	//LuaState * luaState;
	// Registered function MUST always have this signature (int (funcName) (LuaPlus::LuaState*))
private:



};

