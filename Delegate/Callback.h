#pragma once

namespace Callback
{
	// NO ARG
	template<typename R, typename C>
	struct CallbackWrapper
	{
		R *receiver;
		void (C::*memberFun)();

		void operator()() { (receiver->*memberFun)(); }
	};

	template<typename R, typename C>
	CallbackWrapper<R, C> invoke(R *receiver, void (C::*memberFun)())
	{
		CallbackWrapper<R, C> wrapper = { receiver, memberFun };
		return wrapper;
	}

	// ONE ARG
	template<typename Arg, typename R, typename C>
	struct CallbackWrapper1
	{
		R *receiver;
		void (C::*memberFun)(Arg);

		void operator()(Arg a1) { (receiver->*memberFun)(a1); }
	};

	template<typename Arg, typename R, typename C>
	CallbackWrapper1<Arg, R, C> invoke(R *receiver, void (C::*memberFun)(Arg))
	{
		CallbackWrapper1<Arg, R, C> wrapper = { receiver, memberFun };
		return wrapper;
	}

	// TWO ARG
	template<typename Arg1, typename Arg2, typename R, typename C>
	struct CallbackWrapper2
	{
		R *receiver;
		void (C::*memberFun)(Arg1, Arg2);

		void operator()(Arg1 a1, Arg2 a2) { (receiver->*memberFun)(a1, a2); }
	};

	template<typename Arg1, typename Arg2, typename R, typename C>
	CallbackWrapper2<Arg1, Arg2, R, C> invoke(R *receiver, void (C::*memberFun)(Arg1, Arg2))
	{
		CallbackWrapper2<Arg1, Arg2, R, C> wrapper = { receiver, memberFun };
		return wrapper;
	}

	// THREE ARG
	template<typename Arg1, typename Arg2, typename Arg3, typename R, typename C>
	struct CallbackWrapper3
	{
		R *receiver;
		void (C::*memberFun)(Arg1, Arg2, Arg3);

		void operator()(Arg1 a1, Arg2 a2, Arg3 a3) { (receiver->*memberFun)(a1, a2, a3); }
	};

	template<typename Arg1, typename Arg2, typename Arg3, typename R, typename C>
	CallbackWrapper3<Arg1, Arg2, Arg3, R, C> invoke(R *receiver, void (C::*memberFun)(Arg1, Arg2, Arg3))
	{
		CallbackWrapper3<Arg1, Arg2, Arg3, R, C> wrapper = { receiver, memberFun };
		return wrapper;
	}

	// FOUR ARG
	template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename R, typename C>
	struct CallbackWrapper4
	{
		R *receiver;
		void (C::*memberFun)(Arg1, Arg2, Arg3, Arg4);

		void operator()(Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4) { (receiver->*memberFun)(a1, a2, a3, a4); }
	};

	template<typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename R, typename C>
	CallbackWrapper4<Arg1, Arg2, Arg3, Arg4, R, C> invoke(R *receiver, void (C::*memberFun)(Arg1, Arg2, Arg3, Arg4))
	{
		CallbackWrapper4<Arg1, Arg2, Arg3, Arg4, R, C> wrapper = { receiver, memberFun };
		return wrapper;
	}
}

using Callback::invoke;