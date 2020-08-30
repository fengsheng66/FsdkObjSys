#include <FsdkObj/ObjContext.h>

using namespace FsdkObj;

static volatile unsigned char bHaveInstance = 0;

ObjContext::ObjContext()
{
	bHaveInstance = 1;
}

ObjContext::~ObjContext()
{
	bHaveInstance = 0;
}

ObjContext& ObjContext::getSingleton()
{
	static ObjContext g_singleton;
	return g_singleton;
}

const ObjPath* ObjContext::path(const std::string& name) const
{
	std::map<std::string, ObjPath*>::const_iterator iter
		= m_paths.find(name);
	if (iter != m_paths.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}

bool ObjContext::registerObj(IObject* obj)
{
	if (NULL == obj)
	{
		return false;
	}
	std::string _path = obj->path();
	if ((int)_path.size() <= 0)
	{
		return false;
	}
	std::map<std::string, ObjPath*>::iterator iter
		= m_paths.find(_path);
	if (iter != m_paths.end())
	{
		bool state = iter->second->registerObj(obj);
		if (state)
		{
			std::set<IListener*>::iterator iter = m_looks.begin();
			std::set<IListener*>::iterator next = iter; 
			for ((next != m_looks.end() ? next++ : next);
				iter != m_looks.end(); 
				iter = (next != m_looks.end() ? next++ : next))
				(*iter)->registerObj(obj);
		}
		return state;
	}
	else
	{
		ObjPath* oPath = new ObjPath(_path);
		if (oPath && oPath->registerObj(obj))
		{ 
			m_paths[_path] = oPath;
			std::set<IListener*>::iterator iter = m_looks.begin();
			std::set<IListener*>::iterator next = iter; 
			for ((next != m_looks.end() ? next++ : next);
				iter != m_looks.end(); 
				iter = (next != m_looks.end() ? next++ : next))
				(*iter)->registerObj(obj);
			return true;
		}
		else
		{
			if (oPath)
			{
				delete oPath;
			}
			return false;
		}
	}
}

void ObjContext::writeoffObj(IObject* obj)
{
	if (NULL == obj)
	{
		return;
	}
	std::string _path = obj->path();
	std::string _name = obj->name();
	if (0 == bHaveInstance)
	{
		printf("this ObjContext have released!\n");
		return;
	}
	std::map<std::string, ObjPath*>::iterator iter
		= m_paths.find(_path);
	if (iter != m_paths.end() && iter->second->writeoffObj(_name))
	{
		std::set<IListener*>::iterator iter = m_looks.begin();
		std::set<IListener*>::iterator next = iter; 
		for ((next != m_looks.end() ? next++ : next); 
			iter != m_looks.end(); 
			iter = (next != m_looks.end() ? next++ : next))
			(*iter)->writeoffObj(obj);
	}
}

bool ObjContext::listen(IListener* _listenner)
{
	if (_listenner)
		m_looks.insert(_listenner);
	return _listenner;
}

void ObjContext::ignore(IListener* _listenner)
{
	std::set<IListener*>::iterator iter = m_looks.find(_listenner);
	if (iter != m_looks.end()) m_looks.erase(iter);
}