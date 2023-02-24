#ifndef __BT_ENGINE_APPLICATION_H__
#define __BT_ENGINE_APPLICATION_H__

#include <string>

#include "engine/core/common.h"

namespace bt::engine
{
	class Application
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Application)

	public:
		Application(const std::string_view& name);
		virtual ~Application() = default;

		void Start();
		void Stop();

		const std::string& GetName() const;

	protected:
		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;

	private:
		std::string m_Name;
		bool m_IsRunning;
	};
}

#endif // !__BT_ENGINE_APPLICATION_H__
