
#include "pch.h"
#include "CppUnitTest.h"
#include "PairB.h"
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // 16. Перевірка конструктора Pair
        TEST_METHOD(TestPairConstructor)
        {
            Pair p(10, 20);

            Assert::AreEqual(10L, p.GetFirst());
            Assert::AreEqual(20L, p.GetSecond());
        }

        // 17. Перевірка присвоювання Pair
        TEST_METHOD(TestPairAssignment)
        {
            Pair p1(10, 20);
            Pair p2;

            p2 = p1;

            Assert::AreEqual(10L, p2.GetFirst());
            Assert::AreEqual(20L, p2.GetSecond());
        }

        // 18. Перевірка рівності Pair
        TEST_METHOD(TestPairEqual)
        {
            Pair p1(10, 20);
            Pair p2(10, 20);

            Assert::IsTrue(p1 == p2);
        }

        // 19. Перевірка нерівності Pair
        TEST_METHOD(TestPairNotEqual)
        {
            Pair p1(10, 20);
            Pair p2(10, 30);

            Assert::IsTrue(p1 != p2);
        }

        // 20. Перевірка оператора більше Pair
        TEST_METHOD(TestPairGreater)
        {
            Pair p1(20, 10);
            Pair p2(10, 20);

            Assert::IsTrue(p1 > p2);
        }

        // 21. Перевірка оператора менше Pair
        TEST_METHOD(TestPairLess)
        {
            Pair p1(10, 10);
            Pair p2(20, 20);

            Assert::IsTrue(p1 < p2);
        }

        // 22. Перевірка >= Pair
        TEST_METHOD(TestPairGreaterEqual)
        {
            Pair p1(10, 20);
            Pair p2(10, 20);

            Assert::IsTrue(p1 >= p2);
        }

        // 23. Перевірка <= Pair
        TEST_METHOD(TestPairLessEqual)
        {
            Pair p1(10, 20);
            Pair p2(10, 20);

            Assert::IsTrue(p1 <= p2);
        }

        // 24. Перевірка конструктора MoneyB
        TEST_METHOD(TestMoneyBConstructor)
        {
            MoneyB m(150, 75);

            Assert::AreEqual(150L, m.GetFirst());
            Assert::AreEqual(75L, m.GetSecond());
        }

        // 25. Перевірка перетворення в копійки
        TEST_METHOD(TestMoneyBToKopecks)
        {
            MoneyB m(100, 50);

            Assert::AreEqual(10050LL, m.ToKopecks());
        }

        // 26. Перевірка віднімання MoneyB
        TEST_METHOD(TestMoneyBSubtract)
        {
            MoneyB a(150, 75);
            MoneyB b(50, 25);

            MoneyB result = a - b;

            Assert::AreEqual(100L, result.GetFirst());
            Assert::AreEqual(50L, result.GetSecond());
        }

        // 27. Перевірка множення MoneyB
        TEST_METHOD(TestMoneyBMultiply)
        {
            MoneyB a(100, 50);

            MoneyB result = a * 2.0;

            Assert::AreEqual(201L, result.GetFirst());
            Assert::AreEqual(0L, result.GetSecond());
        }

        // 28. Перевірка рівності MoneyB
        TEST_METHOD(TestMoneyBEqual)
        {
            MoneyB a(100, 50);
            MoneyB b(100, 50);

            Assert::IsTrue(a == b);
        }

        // 29. Перевірка нерівності MoneyB
        TEST_METHOD(TestMoneyBNotEqual)
        {
            MoneyB a(100, 50);
            MoneyB b(50, 50);

            Assert::IsTrue(a != b);
        }

        // 30. Перевірка оператора більше MoneyB
        TEST_METHOD(TestMoneyBGreater)
        {
            MoneyB a(200, 50);
            MoneyB b(100, 50);

            Assert::IsTrue(a > b);
        }

        // 31. Перевірка оператора менше MoneyB
        TEST_METHOD(TestMoneyBLess)
        {
            MoneyB a(50, 50);
            MoneyB b(100, 50);

            Assert::IsTrue(a < b);
        }

        // 32. Перевірка копіювання MoneyB
        TEST_METHOD(TestMoneyBCopy)
        {
            MoneyB a(100, 50);
            MoneyB b(a);

            Assert::AreEqual(100L, b.GetFirst());
            Assert::AreEqual(50L, b.GetSecond());
        }

        // 33. Перевірка присвоювання MoneyB
        TEST_METHOD(TestMoneyBAssignment)
        {
            MoneyB a(100, 50);
            MoneyB b;

            b = a;

            Assert::AreEqual(100L, b.GetFirst());
            Assert::AreEqual(50L, b.GetSecond());
        }

        // 34. Перевірка перетворення MoneyB у string
        TEST_METHOD(TestMoneyBString)
        {
            MoneyB a(100, 5);

            string result = (string)a;

            Assert::IsTrue(result == "100,05 UAH");
        }

    };
}