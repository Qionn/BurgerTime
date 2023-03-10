#ifndef __BT_ENGINE_FIRTY_CACHE_H__
#define __BT_ENGINE_FIRTY_CACHE_H__

#include <utility>
#include <functional>
#include <type_traits>

namespace bt::engine
{
	// DirtyCache ----------------------------------------------------------------
	// ===========================================================================

	template<typename T>
	class DirtyCache final
	{
	public:
		DirtyCache()
		{
			static_assert(std::is_default_constructible_v<T>, "Type T must be default constructibe");
		}
		DirtyCache(const T& value)
			: m_Data{ value }
		{
			static_assert(std::is_copy_constructible_v<T>, "Type T must be copy constructibe");
		}
		DirtyCache(T&& value)
			: m_Data{ std::move(value) }
		{
			static_assert(std::is_move_constructible_v<T>, "Type T must be move constructibe");
		}
		~DirtyCache() = default;

		void SetDirty()
		{
			m_IsDirty = true;
		}
		bool IsDirty() const
		{
			return m_IsDirty;
		}
		void WhenDirty(const std::function<void(T&)>& functor)
		{
			if (m_IsDirty)
			{
				functor(m_Data);
				m_IsDirty = false;
			}
		}

		DirtyCache& operator=(const T& rhs)
		{
			static_assert(std::is_copy_assignable_v<T>, "Type T must be copy assignable");
			m_Data = rhs;
			return *this;
		}
		DirtyCache& operator=(T&& rhs) noexcept
		{
			static_assert(std::is_move_assignable_v<T>, "Type T must be move assignable");
			m_Data = std::move(rhs);
			return *this;
		}

		T* operator->()
		{
			return &m_Data;
		}
		const T* operator->() const
		{
			return &m_Data;
		}
		T& operator*()
		{
			return m_Data;
		}
		const T& operator*() const
		{
			return m_Data;
		}

	private:
		bool m_IsDirty = true;
		T m_Data;
	};
}

#endif // !__BT_ENGINE_FIRTY_CACHE_H__
