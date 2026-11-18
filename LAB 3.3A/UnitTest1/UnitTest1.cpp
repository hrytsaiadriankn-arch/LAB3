
#include "pch.h"
#include "CppUnitTest.h"
#include "MoneyA.h"
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // 1. Перевірка базового класу BaseMoney
        TEST_METHOD(TestBaseMoneyConstructor)
        {
            BaseMoney m(100, 50);

            Assert::AreEqual(100L, m.GetHryvnias());
            Assert::AreEqual(50, m.GetKopecks());
        }

        // 2. Перевірка конструктора MoneyAOpen
        TEST_METHOD(TestMoneyAOpenConstructor)
        {
            MoneyAOpen m(150, 75);

            Assert::AreEqual(150L, m.GetHryvnias());
            Assert::AreEqual(75, m.GetKopecks());
        }

        // 3. Перевірка віднімання
        TEST_METHOD(TestMoneyAOpenSubtract)
        {
            MoneyAOpen a(100, 50);
            MoneyAOpen b(30, 25);

            MoneyAOpen result = a - b;

            Assert::AreEqual(70L, result.GetHryvnias());
            Assert::AreEqual(25, result.GetKopecks());
        }

        // 4. Перевірка множення
        TEST_METHOD(TestMoneyAOpenMultiply)
        {
            MoneyAOpen a(100, 50);

            MoneyAOpen result = a * 2.0;

            Assert::AreEqual(201L, result.GetHryvnias());
            Assert::AreEqual(0, result.GetKopecks());
        }

        // 5. Перевірка рівності
        TEST_METHOD(TestMoneyAOpenEqual)
        {
            MoneyAOpen a(100, 50);
            MoneyAOpen b(100, 50);

            Assert::IsTrue(a == b);
        }

        // 6. Перевірка нерівності
        TEST_METHOD(TestMoneyAOpenNotEqual)
        {
            MoneyAOpen a(100, 50);
            MoneyAOpen b(50, 50);

            Assert::IsTrue(a != b);
        }

        // 7. Перевірка оператора більше
        TEST_METHOD(TestMoneyAOpenGreater)
        {
            MoneyAOpen a(100, 50);
            MoneyAOpen b(50, 50);

            Assert::IsTrue(a > b);
        }

        // 8. Перевірка оператора менше
        TEST_METHOD(TestMoneyAOpenLess)
        {
            MoneyAOpen a(20, 50);
            MoneyAOpen b(50, 50);

            Assert::IsTrue(a < b);
        }

        // 9. Перевірка конструктора копіювання
        TEST_METHOD(TestMoneyAOpenCopy)
        {
            MoneyAOpen a(100, 50);
            MoneyAOpen b(a);

            Assert::AreEqual(100L, b.GetHryvnias());
            Assert::AreEqual(50, b.GetKopecks());
        }

        // 10. Перевірка оператора присвоювання
        TEST_METHOD(TestMoneyAOpenAssignment)
        {
            MoneyAOpen a(100, 50);
            MoneyAOpen b;

            b = a;

            Assert::AreEqual(100L, b.GetHryvnias());
            Assert::AreEqual(50, b.GetKopecks());
        }

        // 11. Перевірка перетворення в string
        TEST_METHOD(TestMoneyAOpenString)
        {
            MoneyAOpen a(100, 5);

            string result = (string)a;

            Assert::IsTrue(result == "100,05 UAH");
        }

        // 12. Перевірка закритого успадкування
        TEST_METHOD(TestMoneyAClosedConstructor)
        {
            MoneyAClosed a(200, 75);

            Assert::AreEqual(200L, a.GetHryvnias());
            Assert::AreEqual(75, a.GetKopecks());
        }

        // 13. Перевірка віднімання MoneyAClosed
        TEST_METHOD(TestMoneyAClosedSubtract)
        {
            MoneyAClosed a(200, 75);
            MoneyAClosed b(50, 25);

            MoneyAClosed result = a - b;

            Assert::AreEqual(150L, result.GetHryvnias());
            Assert::AreEqual(50, result.GetKopecks());
        }

        // 14. Перевірка множення MoneyAClosed
        TEST_METHOD(TestMoneyAClosedMultiply)
        {
            MoneyAClosed a(100, 50);

            MoneyAClosed result = a * 2.0;

            Assert::AreEqual(201L, result.GetHryvnias());
            Assert::AreEqual(0, result.GetKopecks());
        }

        // 15. Перевірка порівняння MoneyAClosed
        TEST_METHOD(TestMoneyAClosedComparison)
        {
            MoneyAClosed a(200, 50);
            MoneyAClosed b(100, 50);

            Assert::IsTrue(a > b);
            Assert::IsFalse(a == b);
        }
            };
}