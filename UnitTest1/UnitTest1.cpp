#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(Test_N3_K2)
        {
            const int k = 2;
            const int N = 3;
            const double expected = 2.7777777777777772;
            const double delta = 1e-7; // припустима похибка

            Assert::AreEqual(expected, P0(k, N), delta);
            Assert::AreEqual(expected, P1(k, N, k), delta);
            Assert::AreEqual(expected, P2(k, N, N), delta);
            Assert::AreEqual(expected, P3(k, N, k, 1.0), delta);
            Assert::AreEqual(expected, P4(k, N, N, 1.0), delta);
        }
        TEST_METHOD(Test_N5_K3)
        {
            const int k = 3;
            const int N = 5;
            const double delta = 1e-7;

            double res0 = P0(k, N);

            Assert::AreEqual(res0, P1(k, N, k), delta);
            Assert::AreEqual(res0, P2(k, N, N), delta);
            Assert::AreEqual(res0, P3(k, N, k, 1.0), delta);
            Assert::AreEqual(res0, P4(k, N, N, 1.0), delta);
        }
	};
}
