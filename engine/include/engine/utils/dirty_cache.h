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
		/**
		 * Constructs a new DirtyCache object.
		 *
		 * The default constructor is only available if T is default constructible.
		 */
		DirtyCache()
		{
			static_assert(std::is_default_constructible_v<T>, "Type T must be default constructibe");
		}

		/**
		 * Constructs a new DirtyCache object with a copy of the provided value.
		 *
		 * The provided value is copied into the cache data member. Copy construction
		 * is only available if T is copy constructible.
		 *
		 * @param value The value to copy into the cache.
		 */
		DirtyCache(const T& value)
			: m_Data{ value }
		{
			static_assert(std::is_copy_constructible_v<T>, "Type T must be copy constructibe");
		}

		/**
		 * Constructs a new DirtyCache object with a moved value.
		 *
		 * The provided value is moved into the cache data member. Move construction
		 * is only available if T is move constructible.
		 *
		 * @param value The value to move into the cache.
		 */
		DirtyCache(T&& value)
			: m_Data{ std::move(value) }
		{
			static_assert(std::is_move_constructible_v<T>, "Type T must be move constructibe");
		}

		~DirtyCache() = default;

		/**
		 * Sets the dirty flag.
		 *
		 * This function sets the dirty flag to true.
		 */
		void SetDirty()
		{
			m_IsDirty = true;
		}

		/**
		 * Return the dirty flag
		 * 
		 * @returns True if the dirty flag is set, otherwise false.
		 */
		bool IsDirty() const
		{
			return m_IsDirty;
		}

		/**
		 * Calls the provided callback function if the cache is dirty.
		 *
		 * If the dirty flag is true, the provided callback function is called with
		 * no arguments. Afterwards the dirty flag is set to false.
		 *
		 * @param functor The callback function to call if the cache is dirty.
		 */
		void WhenDirty(const std::function<void(T&)>& functor)
		{
			if (m_IsDirty)
			{
				functor(m_Data);
				m_IsDirty = false;
			}
		}

		/**
		 * Copy assigns a new value to the cache.
		 *
		 * The provided value is copied into the cache data member. Copy assignment
		 * is only available if T is copy assignable.
		 *
		 * @param rhs The value to copy into the cache.
		 * @return A reference to the DirtyCache object.
		 */
		DirtyCache& operator=(const T& rhs)
		{
			static_assert(std::is_copy_assignable_v<T>, "Type T must be copy assignable");
			m_Data = rhs;
			return *this;
		}
		/**
		 * Move assigns a new value to the cache.
		 *
		 * The provided value is moved into the cache data member. Move assignment
		 * is only available if T is move assignable
		 *
		 * @param rhs The value to move into the cache.
		 * @return A reference to the DirtyCache object.
		 */
		DirtyCache& operator=(T&& rhs) noexcept
		{
			static_assert(std::is_move_assignable_v<T>, "Type T must be move assignable");
			m_Data = std::move(rhs);
			return *this;
		}

		/**
		 * Returns a pointer to the cached data.
		 *
		 * This function returns a pointer to the cached data member. This allows
		 * the cached data to be accessed directly.
		 *
		 * @return A pointer to the cached data member.
		 */
		T* operator->()
		{
			return &m_Data;
		}

		/**
		 * Returns a const pointer to the cached data.
		 *
		 * This function returns a const pointer to the cached data member. This allows
		 * the cached data to be accessed directly but not modified.
		 *
		 * @return A const pointer to the cached data member.
		 */
		const T* operator->() const
		{
			return &m_Data;
		}

		/**
		 * Returns a reference to the cached data.
		 *
		 * This function returns a reference to the cached data member. This allows
		 * the cached data to be accessed directly.
		 *
		 * @return A reference to the cached data member.
		 */
		T& operator*()
		{
			return m_Data;
		}

		/**
		 * Returns a const reference to the cached data.
		 *
		 * This function returns a const reference to the cached data member. This allows
		 * the cached data to be accessed directly but not modified.
		 *
		 * @return A const reference to the cached data member.
		 */
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
