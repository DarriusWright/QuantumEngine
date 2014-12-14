#include <windows.h>
#include <iostream>
#include <sstream>
#include "..\\LuaPlusLib\\LuaPlus.h"
#include <glm.hpp>
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

LuaPlus::LuaState* pState = LuaPlus::LuaState::Create(true);

static float delta()
{
	return 1.0f / 60.0f;
}

struct GameObject
{

};


struct Ninja
{
private:
	glm::vec3 position;
public:
	void SetPosition(float x, float y, float z)
	{
		position = glm::vec3(x, y, z);
	}


	Ninja * GetNinja()
	{
		return this;
	}

	void DoSomething(LuaObject ninja)
	{
		std::cout << "Worked" << std::endl;
		LuaObject nObject = ninja.Lookup("__object");
		Ninja * ninjaInstance;
		if (!nObject.IsNil())
		{
			ninjaInstance = (Ninja*)nObject.GetLightUserData();
		}
	}


	static LuaObject createFromScript()
	{
		Ninja * cppInstance = new Ninja();
		LuaObject luaInstance;
		luaInstance.AssignNewTable(pState);
		luaInstance.SetLightUserData("__object", cppInstance);
		LuaObject metaTable = pState->GetGlobals().GetByName("NinjaMetaTable");
		luaInstance.SetMetaTable(metaTable);

		return luaInstance;

	}

};

int main()
{
	

	// Create a new lua state and load all default lua libraries

	// Get the global object of our state so that we can register global functions
	LuaPlus::LuaObject globals = pState->GetGlobals();

	// Register our HelloWorld() function directly to lua
	globals.RegisterDirect("HelloWorld", HelloWorld);
	globals.RegisterDirect("CreateNinja", &Ninja::createFromScript);
	globals.RegisterDirect("delta", delta);

	LuaObject metaTable = pState->GetGlobals().CreateTable("NinjaMetaTable");
	metaTable.SetObject("__index", metaTable); // it is it's own metatable
	metaTable.RegisterObjectDirect("SetPosition", (Ninja*)0, &Ninja::SetPosition);
	metaTable.RegisterObjectDirect("GetNinja", (Ninja*)0, &Ninja::GetNinja);
	metaTable.RegisterObjectDirect("DoSomething", (Ninja*)0, &Ninja::DoSomething);
	// Register our Print() function to lua
	globals.Register("printMessage", Print);

	if (pState->DoFile("LuaScripts/test.lua"))
	{
		// An error occured
		if (pState->GetTop() == 1)
			std::cout << "An error occured: " << pState->CheckString(1) << std::endl;
	}





	// Clean-up
	LuaPlus::LuaState::Destroy(pState);
	pState = nullptr;

	getchar();
	return 0;
}