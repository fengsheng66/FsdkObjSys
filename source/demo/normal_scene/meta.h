#ifndef FSDK_DEMO_META_H
#define FSDK_DEMO_META_H

#include <string>
#include <FsdkObj/Releasable.h>

namespace md
{
	class MetaDemo : public FsdkObj::Releasable
	{
	public:
		MetaDemo(const char* out_str) : m_outStr(out_str){ }
		~MetaDemo() { }

		void print();
		int output(const char* tag);
	private:
		std::string m_outStr;
	};

} //namespace md

#endif