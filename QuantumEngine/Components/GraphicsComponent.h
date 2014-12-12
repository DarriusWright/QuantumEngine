#pragma once


#include "Component.h"
class GameObject;
class GraphicsComponent : public Component
{
	RTTI_DECLARATIONS(GraphicsComponent, Component);
public:
	ENGINE_SHARED GraphicsComponent(GameObject * gameObject);
	ENGINE_SHARED ~GraphicsComponent();
	ENGINE_SHARED virtual void update()override;
	ENGINE_SHARED virtual void draw();
	ENGINE_SHARED virtual void initialize()override;
protected:
	ENGINE_SHARED virtual void registerClass()override;

};

