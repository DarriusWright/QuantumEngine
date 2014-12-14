#include "GameObject.h"
#include <Components\TransformComponent.h>
#include <Components\GraphicsComponent.h>

RTTI_DEFINITIONS(GameObject)


GameObject::GameObject(TransformComponent * transformComponent) : transform(transformComponent)
{
	if (!transform)
	{
		transform = new TransformComponent(this);
	}
	components.push_back(transform);

}


GameObject::~GameObject()
{
	for (size_t index = 0; index < components.size(); index++)
	{

		if (components[index])
		{
			delete components[index];
			components[index] = nullptr;
		}
	}

	components.clear();
}



int GameObject::getId()
{
	return id;
}
const std::vector<Component*> & GameObject::getComponents()
{
	return components;
}
const TransformComponent * GameObject::getTranform()
{
	return transform;
}
void GameObject::setTrasform(TransformComponent * transform)
{
	//TODO copy transform components

}

void GameObject::update()
{
	for (Component * c : components)
	{
		c->update();
		if (c->is(GraphicsComponent::typeIdClass()))
		{
			GraphicsComponent * g =  c->as<GraphicsComponent>();
			g->draw();
		}

	}
}

void GameObject::initialize()
{
	for (Component * c : components)
	{
		c->initialize();
	}
}

void GameObject::addComponent(Component * component)
{
	if (component)
		components.push_back(component);
}

//template<typename T>
//T * GameObject::getComponent()
//{
//	static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
//	//T * t ;
//	///Component * c = (Component)t;
//	for (int i = 0; i < components.size(); i++)
//	{
//		if (T::typeIdClass() == components[i]->typeIdClass())
//			return components[i];
//		break;
//	}
//}
//
//template<typename T>
//std::vector<T *> GameObject::getComponents()
//{
//
//}



