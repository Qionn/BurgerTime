#ifndef __BT_ENGINE_FAMILY_H__
#define __BT_ENGINE_FAMILY_H__

#include <cstdint>

#include "engine/core/common.h"

namespace bt::engine
{
	// Family --------------------------------------------------------------------
	// ===========================================================================

	template<typename T>
	class Family final
	{
		BT_ENGINE_DISALLOW_IMPLICIT_CONSTRUCTOR(Family)

	public:
		/**
		 * Returns the Id of type U in group T.
		 * 
		 * @tparam U The type to get the id of
		 * @returns The id of U in group T
		 */
		template<typename U> static uint32_t GetTypeId()
		{
			static uint32_t id = s_Count++;
			return id;
		}

		/**
		 * Checks if the id equals to the type id of U
		 * 
		 * @param id The id to check
		 */
		template<typename U> static bool IsTypeId(uint32_t id)
		{
			return id == GetTypeId<U>();
		}

	private:
		inline static uint32_t s_Count = 0;
	};
}

#endif // !__BT_ENGINE_FAMILY_H__
