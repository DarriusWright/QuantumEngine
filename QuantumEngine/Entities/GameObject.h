#pragma once


#include <RTTI.h>
#include <vector>
#include <Components\Component.h>
class TransformComponent;

class GameObject : public RTTI
{
	RTTI_DECLARATIONS(Component, RTTI);
public:
	ENGINE_SHARED ~GameObject();
	ENGINE_SHARED virtual void update();
	ENGINE_SHARED TransformComponent * getTransform();
	ENGINE_SHARED void addComponent(Component * component);
	ENGINE_SHARED void initialize();
	template<typename T> T * getComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
		for (size_t i = 0; i < components.size(); i++)
		{
			
			if (components[i]->is(T::typeIdClass()))
			{
				return components[i]->as<T>();
			}
		}

		return nullptr;
	}
	template<typename T> std::vector<T*> getComponents()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
		//T * t ;
		///Component * c = (Component)t;
		std::vector<T*> foundComponents;
		for (size_t i = 0; i < components.size(); i++)
		{
			if (components[i]->is(T::typeIdClass()))
			{
				foundComponents.push_back(components[i]->as<T>());
			}	
		}

		return foundComponents;
	}


	int getId();
	const std::vector<Component*> & getComponents();
	const TransformComponent * getTranform();
	void setTrasform(TransformComponent * transform);

	std::string name;
	GameObject * parent;

private:
	ENGINE_SHARED GameObject(int id,TransformComponent * transform = nullptr);
	TransformComponent * transform;

	friend class GameObjectManager;
	int id;
	std::vector<Component * > components;
};

