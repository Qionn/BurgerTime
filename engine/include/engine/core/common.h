#ifndef __BT_ENGINE_COMMON_H__
#define __BT_ENGINE_COMMON_H__

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

#endif // !__BT_ENGINE_COMMON_H__
