#include "pch.h"
#include <cassert>
#include "CppUnitTest.h"
#include "../Project2/TFrac.h"
#include "../Project2/TFrac.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Teststl
{
	TEST_CLASS(Teststl)
	{
	public:
		
		TEST_METHOD(Create)
		{
			std::string n = "1/2";
			TFrac m(n);
			Assert::AreEqual(n, m.getStringDrob());
		};

		TEST_METHOD(Add)
		{
			TFrac a("1/2");
			TFrac b("1/2");
			TFrac c = a + b;
			std::string d = "1/1";
			Assert::AreEqual(d, c.getStringDrob());
		};

		TEST_METHOD(Equal)
		{
			TFrac a("1/2");
			TFrac b("2/4");						
			Assert::AreEqual(true, a== b);
		};

		TEST_METHOD(More)
		{
			TFrac a("4/5");
			TFrac b("2/5");
			Assert::AreEqual(true, a > b);
		};

		TEST_METHOD(Less)
		{
			TFrac a("4/5");
			TFrac b("2/5");
			Assert::AreEqual(true, b < a);
		};
	};
}
