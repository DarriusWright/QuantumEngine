#pragma once
#include "ScriptManager.h"
#include <windows.h>
#include <sstream>

#include <ExportHeader.h>
using namespace LuaPlus;


#include <iostream>
//
//extern "C" {
//# include "lua.h"
//# include "lauxlib.h"
//# include "lualib.h"
//}
//
//#include <LuaBridge.h>
//
//
//#include <glm.hpp>
//using namespace glm;


//#include <LuaPlus.h>
#include <LuaPlus.h>
#include <glm.hpp>
#include <LuaObject.h>

#define LUA LuaStateManager::getInstance();

//using namespace luabridge;
using namespace LuaPlus;

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


class LuaStateManager  : public ScriptManager
{



public:

	//static void  Print(const std::string & s)
	//{
	//	std::cout << "LUA : " << s << std::endl;
	//}

	static int Print(LuaState * state)
	{
		int top = state->GetTop();
		std::stringstream output;
		for (int i = 1; i <= top; ++i) {
			output << state->CheckString(i) << std::endl;
		}
		std::cout << output.str() << std::endl;
		return 0; // We don't return any values to the script
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
		globals.Register(name, function);
		//getGlobalNamespace(luaState).addFunction(name,function);

	}

	template <class T,typename Func>
	void registerFunction( char * name,LuaObject metaTable, Func function )
	{
		metaTable.RegisterObjectDirect(name, (T*)0, function);
	}

	template<class T>
	void registerInstance(T * instance,LuaObject luaInstance, std::string className, std::string userData = "__object")
	{
		luaInstance.AssignNewTable(luaState);
		luaInstance.SetLightUserData(userData.c_str(), instance);
		LuaObject metaTable = luaState->GetGlobals().GetByName((className + "MetaTable").c_str());
		luaInstance.SetMetaTable(metaTable);

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
	ENGINE_SHARED virtual void update()override;
	ENGINE_SHARED virtual bool startUp()override;
	ENGINE_SHARED virtual bool shutDown()override;
	

protected :
	ENGINE_SHARED LuaStateManager();
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

