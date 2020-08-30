#include <FsdkObj/MetaContext.h>

using namespace FsdkObj;

static volatile unsigned char bHaveInstance = 0;

MetaContext::MetaContext()
{
	bHaveInstance = 1;
}

MetaContext::~MetaContext()
{
	bHaveInstance = 0;
}

MetaContext& MetaContext::getSingleton()
{
	static MetaContext _singleton;
	return _singleton;
}

bool MetaContext::registerClass(IMetaClass* metaClass)
{
	if (NULL == metaClass)
	{
		return false;
	}
	std::string _space = metaClass->spacename();
	if ((int)_space.size() <= 0)
	{
		return false;
	}
	std::map<std::string, MetaSpace*>::iterator iter
		= m_spaces.find(_space);
	if (iter != m_spaces.end())
	{
		return iter->second->registerClass(metaClass);
	}
	else
	{
		MetaSpace* mSpace = new MetaSpace(_space);
		if (mSpace && mSpace->registerClass(metaClass))
		{
			m_spaces[_space] = mSpace;
			return true;
		}
		else
		{
			if (mSpace)
			{
				delete mSpace;
			}
			return false;
		}
	}
}

void MetaContext::writeoffClass(IMetaClass* metaClass)
{
	if (NULL == metaClass)
	{
		return;
	}
	std::string _space = metaClass->spacename();
	std::string _name = metaClass->classname();
	if (0 == bHaveInstance)
	{
		printf("this MetaContext have released!\n");
		return;
	}
	std::map<std::string, MetaSpace*>::iterator iter
		= m_spaces.find(_space);
	if (iter != m_spaces.end())
	{
		iter->second->writeoffClass(_name);
	}
}

const MetaSpace* MetaContext::space(const std::string& name) const
{
	std::map<std::string, MetaSpace*>::const_iterator iter
		= m_spaces.find(name);
	if (iter != m_spaces.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}
