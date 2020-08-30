#include <FsdkObj/ObjPath.h>

using namespace FsdkObj;

ObjPath::ObjPath(const std::string& _path) : m_path(_path)
{

}

ObjPath::~ObjPath()
{

}

const std::string& ObjPath::path() const
{
	return m_path;
}

bool ObjPath::registerObj(IObject* obj)
{
	ObjectMap::iterator iter =
		m_objects.find(obj->name());
	if (iter != m_objects.end())
	{
		return false;
	}
	else
	{
		m_objects[obj->name()] = obj;
		return true;
	}
}

bool ObjPath::writeoffObj(const std::string& name)
{
	ObjectMap::iterator iter = m_objects.find(name);
	if (iter != m_objects.end())
	{
		m_objects.erase(iter);
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<IObject*> ObjPath::allObj() const
{
	std::vector<IObject*> objectVec;
	objectVec.resize(m_objects.size(), 0);
	ObjectMap::const_iterator iter = m_objects.begin();
	for (int i = 0; iter != m_objects.end(); iter++, i++)
	{
		objectVec[i] = iter->second;
	}
	return objectVec;
}

int ObjPath::getObjectNum() const
{
	return m_objects.size();
}

IObject* ObjPath::getObj(const std::string& name) const
{
	ObjectMap::const_iterator iter = m_objects.find(name);
	if (iter != m_objects.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}