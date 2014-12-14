#pragma once

#include "Component.h"
#include <glm.hpp>

class GameObject;
class TransformComponent : public Component
{
	RTTI_DECLARATIONS(TransformComponent , Component);

public:
	ENGINE_SHARED TransformComponent(GameObject * gameObject);
	ENGINE_SHARED ~TransformComponent();
	ENGINE_SHARED virtual void update() override;
	ENGINE_SHARED virtual void initialize()override;
	glm::vec3 postion;
	glm::vec3 rotation;
	glm::vec3 scale;


protected:
	ENGINE_SHARED virtual void registerClass()override;




};

