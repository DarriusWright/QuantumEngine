#include "GameEditor.h"
#include <lua.hpp>


GameEditor::GameEditor(LuaPlus::LuaState * luaState) : luaState(luaState)
{
	setUpMenu();
}


void GameEditor::setUpMenu()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	gameObjectMenu = menuBar()->addMenu(tr("&File"));

	QAction * action = new QAction(tr("Add GameObject"), this);


}

GameEditor::~GameEditor()
{
	LUA->shutDown();
	GAMEOBJECT->shutDown();
	

	delete LUA;
	delete GAMEOBJECT;

}
