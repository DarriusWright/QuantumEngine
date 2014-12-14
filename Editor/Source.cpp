#include <windows.h>
#include <iostream>
#include <sstream>
#include <QtWidgets\qapplication.h>

#include "GameEditor.h"
#include <Scripting\LuaStateManager.h>
#include <Entities\GameObjectManager.h>

#include <iostream>



int main(int argc, char * argv [])
{

	QApplication app(argc, argv);
	GameEditor editor;

	GAMEOBJECT->startUp();
	

	LUA->startUp();
	LUA->executeScript("LuaScripts/test.lua");


	editor.show();

	return app.exec();
}
