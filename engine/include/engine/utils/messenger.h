#ifndef __BT_ENGINE_MESSENGER_H__
#define __BT_ENGINE_MESSENGER_H__

#include <functional>
#include <type_traits>

#include "engine/core/common.h"

namespace bt::engine
{
	// Messenger -----------------------------------------------------------------
	// ===========================================================================

	template<typename T>
	class Messenger
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Messenger)

	public:
		using value_t = std::add_lvalue_reference_t<T>;

		void SetRecipient(const std::function<void(value_t)>& recipient)
		{
			m_Recipient = recipient;
		}

	protected:
		Messenger() = default;

		void Message(value_t param) const
		{
			if (m_Recipient != nullptr)
			{
				m_Recipient(param);
			}
		}

	private:
		std::function<void(value_t)> m_Recipient;
	};

	// Messenger <void> ----------------------------------------------------------
	// ===========================================================================

	template<>
	class Messenger<void>
	{
	public:
		using value_t = void;

		void SetRecipient(const std::function<void()>& recipient)
		{
			m_Recipient = recipient;
		}

	protected:
		Messenger() = default;

		void Message() const
		{
			if (m_Recipient != nullptr)
			{
				m_Recipient();
			}
		}

	private:
		std::function<void()> m_Recipient;
	};
}

#endif // !__BT_ENGINE_MESSENGER_H__
