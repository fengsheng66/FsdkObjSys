#ifndef IMPLCLASS_H_FSDKOBJ
#define IMPLCLASS_H_FSDKOBJ

#include <string>
#include <map>
#include <vector>
#include "../FsdkObjDef.h"
#include "../MetaContext.h"
#include "../MetaDef.h"
#include "./MetaItem.h"
#include "./ConstructItem.h"
#include "./InvokerItem.h"
#include "./SuperItem.h"

namespace FsdkObj
{
	template<class OBJ>
	class ImplClass : public IMetaClass
	{
	public:
		typedef std::pair<std::string, std::string> SuperPair;
		ImplClass()
		{
			MetaContext::getSingleton().registerClass(this);
		}
		virtual ~ImplClass()
		{
			MetaContext::getSingleton().writeoffClass(this);
		}

		virtual const char* spacename() const
		{
			return _implSpaceName.c_str();
		}

		virtual const char* classname() const
		{
			return _implClassName.c_str();
		}
		virtual Releasable* construct(const VarList &argList, int index)
		{
			if (index >= 0 && index < (int)_constructors.size())
			{
				if (_constructors[index])
				{
					return (_constructors[index])(argList);
				}
				else
				{
					return NULL;
				}
			}
			else
			{
				return NULL;
			}
		}
		virtual bool invoke(const std::string& funcName, Releasable* obj, const VarList &argList, VarProxy& out)
		{
			std::map<std::string, IInvoker*>::iterator iter
				= _invokers.find(funcName);
			if (iter != _invokers.end())
			{
				if (iter->second)
				{
					out = iter->second->invoke(obj, argList);
					return true;
				}
					
			}
			for (int i = 0; i < _supers.size(); i++)
			{
				const MetaSpace* _space =
					MetaContext::getSingleton().space(_supers[i].second);
				if (!_space) continue;
				IMetaClass* mc = _space->getClass(_supers[i].first);
				if (!mc) continue;
				if (mc->invoke(funcName, obj, argList, out)) return true;
			}
			return false;
		}
		virtual bool destroy(Releasable* obj)
		{
			OBJ*  _impl = dynamic_cast<OBJ*>(obj);
			if (!_impl) return false;
			delete _impl;
			return true;
		}
		static bool InitStaticMetas(const MetaItem* items)
		{
			for (; items && items->type() != InvlidMeta; items++)
			{
				if (items->type() == ConstructorMeta)
				{
					const ConstructItem* member =
						dynamic_cast<const ConstructItem*>(items->impl());
					_constructors.push_back(member->constructor());
					continue;
				}	
				if (items->type() == SuperMeta)
				{
					const SuperItem* member = 
						dynamic_cast<const SuperItem*>(items->impl());
					_supers.push_back(std::make_pair(member->super(), member->space()));
					continue;
				}
				if (items->type() == InvokerMeta)
				{
					const InvokerItem* member = 
						dynamic_cast<const InvokerItem*>(items->impl());
					_invokers[member->name()] = member->invoker();
					continue;
				}
			}
			return true;
		}

	private:
		static std::string							_implSpaceName;
		static std::string							_implClassName;
		static std::vector<LPCONSTRUCTFUNC>			_constructors;
		static std::vector<SuperPair>				_supers;
		static std::map<std::string, IInvoker*>		_invokers;
		
	};
}

#endif