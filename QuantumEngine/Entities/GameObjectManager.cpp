#include "GameObjectManager.h"

RTTI_DEFINITIONS(GameObjectManager)

int GameObjectManager::numGameObjects = 0;

GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
}

GameObject * GameObjectManager::createGameObject(TransformComponent * transform)
{
	int id = numGameObjects++;
	GameObject * gameObject = new GameObject(numGameObjects, transform);
	gameObjects.insert(std::pair<int, GameObject*>(id, gameObject));

	return gameObject;
}

void GameObjectManager::update()
{

	std::map<int, GameObject*>::iterator iter;
	for (iter = gameObjects.begin(); iter != gameObjects.end(); iter++)
	{
		iter->second->update();
	}
}

bool GameObjectManager::startUp()
{
	return true;
}

bool GameObjectManager::shutDown()
{

	std::map<int, GameObject*>::iterator iter;
	for (iter = gameObjects.begin();  iter != gameObjects.end(); iter++)
	{
		iter->second = nullptr;
		delete iter->second;
	}

	gameObjects.clear();

	return true;
}