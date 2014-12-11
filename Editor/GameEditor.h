#pragma once

#include <QtWidgets\qmainwindow.h>
#include <LuaPlus.h>
#include <Scripting\LuaStateManager.h>


class GameEditor : public QMainWindow
{
public:
	GameEditor();//(LuaPlus::LuaState* luaState);
	~GameEditor();
	

private:
	//LuaPlus::LuaState * luaState;
};

