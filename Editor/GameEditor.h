#pragma once

#include <QtWidgets\qmainwindow.h>
//#include <LuaPlus.h>
#include <Scripting\LuaStateManager.h>
#include <Entities\GameObjectManager.h>
#include <QtWidgets\qaction.h>
#include <QtWidgets\qmenu.h>
#include <QtWidgets\qmenubar.h>


class GameEditor : public QMainWindow
{
public:
	GameEditor();//(LuaPlus::LuaState* luaState);
	~GameEditor();
	QMenu * fileMenu;
	QMenu * gameObjectMenu;

private:
	void setUpMenu();

	//LuaPlus::LuaState * luaState;
};

