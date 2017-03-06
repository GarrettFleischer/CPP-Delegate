# C++ Delegate
***

Perhaps the most simple implementation of a dynamic callback function in C++.
Currently supports callback functions that take up to 4 arguments, but can easily be extended to support more.

To use:
	Include "Callback.h"
	Write a function that takes a templated "callback" argument: FuncWithCallBack(T callback)
	From within that function you can use "callback(arg1, arg2, ...)" where arg1, etc. can be anything.
	Call your function as such: FuncWithCallback(invoke(instance, &InstanceType::method))

See Delegate.cpp for an example.