#include "GameEditor.h"


GameEditor::GameEditor(LuaPlus::LuaState * luaState) : luaState(luaState)
{
	
}


GameEditor::~GameEditor()
{
	LuaPlus::LuaState::Destroy(luaState);
	luaState = nullptr;
}
