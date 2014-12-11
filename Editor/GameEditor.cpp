#include "GameEditor.h"


GameEditor::GameEditor()//(LuaPlus::LuaState * luaState) : luaState(luaState)
{
	
}


GameEditor::~GameEditor()
{
	LUA->shutDown();
}
