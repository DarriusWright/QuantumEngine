#pragma once

#include <RTTI.h>
#include <ExportHeader.h>
#include <Manager.h>
#include <vector>
#include <map>
#include "GameObject.h"

#define GAMEOBJECT GameObjectManager::getInstance()

class GameObjectManager : public Manager
{
	RTTI_DECLARATIONS(GameObjectManager, RTTI);
public:
	ENGINE_SHARED ~GameObjectManager();
	ENGINE_SHARED GameObject * createGameObject(TransformComponent * transform = nullptr);

	ENGINE_SHARED void update()override;
	ENGINE_SHARED bool startUp()override;
	ENGINE_SHARED bool shutDown()override;

	static GameObjectManager * getInstance()
	{
		static GameObjectManager * gameObjectManager = new GameObjectManager();
		return gameObjectManager;
	}

protected: 
	ENGINE_SHARED GameObjectManager();

	std::map<int, GameObject*> gameObjects;
	static int numGameObjects;
};

