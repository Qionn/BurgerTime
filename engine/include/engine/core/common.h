#ifndef __BT_ENGINE_COMMON_H__
#define __BT_ENGINE_COMMON_H__

#if defined(_WIN32) || defined(WIN32)
#	define BT_ENGINE_WIN32
#else
#	error "Only Windows is supported!"
#endif

#define BT_ENGINE_DISALLOW_COPY(type)					\
	type(const type&) = delete;							\
	type& operator=(const type&) = delete;

#define BT_ENGINE_DISALLOW_MOVE(type)					\
	type(type&&) = delete;								\
	type& operator=(type&&) = delete;

#define BT_ENGINE_DISALLOW_COPY_AND_MOVE(type)			\
	BT_ENGINE_DISALLOW_COPY(type)						\
	BT_ENGINE_DISALLOW_MOVE(type)

#define BT_ENGINE_DISALLOW_IMPLICIT_CONSTRUCTOR(type)	\
	type() = delete;									\
	BT_ENGINE_DISALLOW_COPY_AND_MOVE(type)

#define BT_ENGINE_APP(type)												\
	std::unique_ptr<bt::engine::Application> bt::engine::AppFactory() {	\
		return std::make_unique<type>();								\
	}

#endif // !__BT_ENGINE_COMMON_H__
