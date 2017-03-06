// Delegate.cpp : Defines the entry point for the console application.
//

#include <iostream>
using std::cout;

#include <string>
using std::string;

#include "Callback.h"

struct TestData
{
	int i;

	explicit TestData(int _i) { i = _i; }
};

class TestClass
{
public:
	void DoStuff(TestData data)
	{
		cout << data.i << '\n';
	}

	void DoStuff2(TestData data, float x)
	{
		cout << data.i << " " << x << '\n';
	}

	void DoStuff3(TestData data, float x, string s)
	{
		cout << data.i << " " << x << " " << s << '\n';
	}
};


template<typename C>
void TestFunc(C callback)
{
	callback(TestData(23));
}

template<typename C>
void TestFunc2(C callback)
{
	callback(TestData(23), 0.23f);
}

template<typename C>
void TestFunc3(C callback)
{
	float x = 23.0f / 100.0f;
	callback(TestData(23), x, "hello");
}

int main()
{
	TestClass tc;
	
	TestFunc(invoke(&tc, &TestClass::DoStuff));
	TestFunc2(invoke(&tc, &TestClass::DoStuff2));
	TestFunc3(invoke(&tc, &TestClass::DoStuff3));

	return 0;
}

