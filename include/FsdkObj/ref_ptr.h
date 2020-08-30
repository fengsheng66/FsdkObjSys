#ifndef REF_PTR_H_FSDKOBJ
#define REF_PTR_H_FSDKOBJ

namespace FsdkObj
{
	template<class T>
	class ref_ptr 
	{
	public:
		inline ref_ptr() : m_ptr(0){}
		ref_ptr(T* ptr) : m_ptr(ptr)
		{
			if (m_ptr)
			{
				m_ptr->ref();
			}
		}
		ref_ptr(const ref_ptr& other) : m_ptr(other.m_ptr)
		{
			if (m_ptr)
			{
				m_ptr->ref();
			}
		}
		~ref_ptr()
		{
			if (m_ptr && 0 == m_ptr->unref())
			{
				delete &(m_ptr->asReleasable());
			}
		}
		ref_ptr& operator = (const ref_ptr& other)
		{
			if (other.m_ptr == m_ptr)
			{
				return *this;
			}
			if (m_ptr && 0 == m_ptr->unref())
			{
				delete &(m_ptr->asReleasable());
			}
			m_ptr = other.m_ptr;
			if (m_ptr)
			{
				m_ptr->ref();
			}
			return *this;
		}
		ref_ptr& operator = (T* ptr)
		{
			if (ptr == m_ptr)
			{
				return *this;
			}
			if (m_ptr && 0 == m_ptr->unref())
			{
				delete &(m_ptr->asReleasable());
			}
			m_ptr = ptr;
			if (m_ptr)
			{
				m_ptr->ref();
			}
			return *this;
		}
		//
		bool operator == (const ref_ptr& other) const
		{
			return (m_ptr == other.m_ptr);
		}
		bool operator == (const T* ptr) const
		{
			return (m_ptr == ptr);
		}
		//
		bool operator != (const ref_ptr& other) const
		{
			return (m_ptr != other.m_ptr);
		}
		bool operator != (const T* ptr) const
		{
			return (m_ptr != ptr);
		}
		//
		bool operator < (const ref_ptr& other) const
		{
			return (m_ptr < other.m_ptr);
		}
		bool operator < (const T* ptr) const
		{
			return (m_ptr < ptr);
		}
		//
		T& operator*() const
		{
			return *m_ptr;
		}
		T* operator->() const
		{
			return m_ptr;
		}
		bool operator!() const
		{
			return 0 == m_ptr;
		}
		//
		bool valid() const
		{
			return 0 != m_ptr;
		}
		T* get() const
		{
			return m_ptr;
		}
		T* release()
		{
			if (m_ptr)
			{
				m_ptr->unref();
			}
			T* ptr = m_ptr;
			m_ptr = 0;
			return ptr;
		}

	private:
		T*	m_ptr;
	};
}

#endif