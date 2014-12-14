#include <windows.h>
#include <iostream>
#include <sstream>
#include <QtWidgets\qapplication.h>

#include "GameEditor.h"

#include <Scripting\LuaStateManager.h>
#include <Entities\GameObjectManager.h>

#include <iostream>


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
	QApplication app(argc, argv);
	GameEditor editor(pState);

	GAMEOBJECT->startUp();
	

	LUA->startUp();
	LUA->executeScript("LuaScripts/test.lua");


	return app.exec();
}
