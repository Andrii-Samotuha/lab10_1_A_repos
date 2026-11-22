
#include "pch.h"
#include "CppUnitTest.h"

#define main Lab101AMain
#include "../Lab_10_1_A/Lab_10_1_A.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab101A
{
    TEST_CLASS(UnitTestLab101A)
    {
    public:

        TEST_METHOD(TestPercentExcellent)
        {
            Student p[4] = {};

            p[0].fiz = 5;
            p[0].mat = 5;
            p[0].inf = 5;

            p[1].fiz = 4;
            p[1].mat = 5;
            p[1].inf = 5;

            p[2].fiz = 5;
            p[2].mat = 5;
            p[2].inf = 5;

            p[3].fiz = 3;
            p[3].mat = 4;
            p[3].inf = 5;

            Assert::AreEqual(50.0, PercentExcellent(p, 4));
        }
    };
}
