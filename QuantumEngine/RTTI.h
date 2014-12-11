#pragma once

#include <string>
#include <ExportHeader.h>

class RTTI
{
public:
	ENGINE_SHARED virtual const unsigned int & typeIdInstance()const = 0;
	ENGINE_SHARED virtual RTTI * queryInterface(const unsigned int id)const
	{
		id;
		return nullptr;
	}

	ENGINE_SHARED virtual bool is(const unsigned int id)const
	{
		id;
		return false;
	}

	ENGINE_SHARED virtual bool is(const std::string & name)const
	{
		name;
		return false;
	}

	template<typename T> T* as()const
	{
		if (is(T::typeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}
};

#define RTTI_DECLARATIONS(Type, ParentType)							  					\
public:																  					\
	typedef ParentType Parent;										  					\
	ENGINE_SHARED static std::string typeName(){ return std::string(#Type); }		  					\
	ENGINE_SHARED virtual const unsigned int & typeIdInstance() const { return Type::typeIdClass(); }	\
	ENGINE_SHARED static const unsigned int & typeIdClass(){ return sRunTimeTypeId; }					\
	ENGINE_SHARED virtual RTTI * queryInterface(const unsigned int id)						\
{																					\
if (id == sRunTimeTypeId)															\
{																					\
	return (RTTI*)this;																	\
}																					\
		else																			\
{																					\
	return Parent::queryInterface(id);													\
}																				\
}																					\
	ENGINE_SHARED virtual bool is(const unsigned int id)const											\
{																					\
if (id == sRunTimeTypeId)														\
{																				\
	return true;																\
}																				\
		else																			\
{																				\
	return Parent::is(id);														\
}																				\
}																					\
	\
	ENGINE_SHARED virtual bool is(const std::string & name)const										\
{																					\
if (name == typeName())															\
{																				\
	return true;																\
}																				\
		else																			\
{																				\
	return Parent::is(name);													\
}																				\
}																					\
	\
private:																				\
	static unsigned int sRunTimeTypeId;

#define RTTI_DEFINITIONS(Type)	unsigned int Type::sRunTimeTypeId = (unsigned int)& Type::sRunTimeTypeId;					  
