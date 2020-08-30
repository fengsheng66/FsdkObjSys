#include <FsdkObj/VarList.h>

using namespace FsdkObj;

VarList::VarList(const VarList& other)
{
	m_vars.resize(other.m_vars.size(), 0);
	for (int i = 0; i < other.m_vars.size(); i++)
	{
		if (!other.m_vars[i]) continue;
		m_vars[i] = other.m_vars[i]->clone();
	}
}

VarList::~VarList()
{
	this->clear();
}

const VarList& VarList::operator=(const VarList& other)
{
	if (this == &other) return *this;
	this->clear();
	m_vars.resize(other.m_vars.size(), 0);
	for (int i = 0; i < other.m_vars.size(); i++)
	{
		if (!other.m_vars[i]) continue;
		m_vars[i] = other.m_vars[i]->clone();
	}
	return *this;
}

int VarList::size() const
{
	return m_vars.size();
}

void VarList::resize(int _size)
{
	if (m_vars.size() > 0) clear();
	m_vars.resize(_size, 0);
}

void VarList::clear()
{
	for (int i = 0; i < m_vars.size(); i++)
	{
		if (!m_vars[i]) continue;
		Releasable* ra =
			dynamic_cast<Releasable*>(m_vars[i]);
		if (!ra)
			throw "canot release var";
		else
			delete ra;
	}
	m_vars.clear();
}
