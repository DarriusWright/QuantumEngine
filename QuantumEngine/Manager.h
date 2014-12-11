#pragma once
#include "RTTI.h"
#include "ExportHeader.h"

class Manager : public RTTI
{

	RTTI_DECLARATIONS(Manager, RTTI);

public:

	ENGINE_SHARED Manager();
	ENGINE_SHARED ~Manager();
	ENGINE_SHARED virtual bool startUp() = 0;
	ENGINE_SHARED virtual bool shutDown() = 0;
	ENGINE_SHARED virtual void update() = 0;


protected:
	
};

