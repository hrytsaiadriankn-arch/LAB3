
#include "pch.h"
#include "CppUnitTest.h"
#include "ObjectC.h"
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // 35. Перевірка конструктора Object
        TEST_METHOD(TestObjectConstructor)
        {
            int initial = Object::GetObjectCount();

            {
                Object obj;

                Assert::AreEqual(
                    initial + 1,
                    Object::GetObjectCount()
                );
            }

            Assert::AreEqual(
                initial,
                Object::GetObjectCount()
            );
        }

        // 36. Перевірка конструктора копіювання Object
        TEST_METHOD(TestObjectCopyConstructor)
        {
            int initial = Object::GetObjectCount();

            {
                Object obj1;
                Object obj2(obj1);

                Assert::AreEqual(
                    initial + 2,
                    Object::GetObjectCount()
                );
            }

            Assert::AreEqual(
                initial,
                Object::GetObjectCount()
            );
        }

        // 37. Перевірка конструктора MoneyC
        TEST_METHOD(TestMoneyCConstructor)
        {
            MoneyC m(100, 50);

            Assert::AreEqual(100L, m.GetHryvnias());
            Assert::AreEqual(50, m.GetKopecks());
        }

        // 38. Перевірка SetHryvnias
        TEST_METHOD(TestMoneyCSetHryvnias)
        {
            MoneyC m;

            m.SetHryvnias(200);

            Assert::AreEqual(200L, m.GetHryvnias());
        }

        // 39. Перевірка SetKopecks
        TEST_METHOD(TestMoneyCSetKopecks)
        {
            MoneyC m;

            m.SetKopecks(75);

            Assert::AreEqual(75, m.GetKopecks());
        }

        // 40. Перевірка перетворення в копійки
        TEST_METHOD(TestMoneyCToKopecks)
        {
            MoneyC m(100, 50);

            Assert::AreEqual(10050LL, m.ToKopecks());
        }

        // 41. Перевірка віднімання MoneyC
        TEST_METHOD(TestMoneyCSubtract)
        {
            MoneyC a(100, 50);
            MoneyC b(30, 25);

            MoneyC result = a - b;

            Assert::AreEqual(70L, result.GetHryvnias());
            Assert::AreEqual(25, result.GetKopecks());
        }

        // 42. Перевірка множення MoneyC
        TEST_METHOD(TestMoneyCMultiply)
        {
            MoneyC a(100, 50);

            MoneyC result = a * 2.0;

            Assert::AreEqual(201L, result.GetHryvnias());
            Assert::AreEqual(0, result.GetKopecks());
        }

        // 43. Перевірка рівності MoneyC
        TEST_METHOD(TestMoneyCEqual)
        {
            MoneyC a(100, 50);
            MoneyC b(100, 50);

            Assert::IsTrue(a == b);
        }

        // 44. Перевірка нерівності MoneyC
        TEST_METHOD(TestMoneyCNotEqual)
        {
            MoneyC a(100, 50);
            MoneyC b(50, 50);

            Assert::IsTrue(a != b);
        }

        // 45. Перевірка оператора більше MoneyC
        TEST_METHOD(TestMoneyCGreater)
        {
            MoneyC a(200, 50);
            MoneyC b(100, 50);

            Assert::IsTrue(a > b);
        }

        // 46. Перевірка оператора менше MoneyC
        TEST_METHOD(TestMoneyCLess)
        {
            MoneyC a(50, 50);
            MoneyC b(100, 50);

            Assert::IsTrue(a < b);
        }

        // 47. Перевірка префіксного ++
        TEST_METHOD(TestMoneyCPrefixIncrement)
        {
            MoneyC a(100, 50);

            ++a;

            Assert::AreEqual(100L, a.GetHryvnias());
            Assert::AreEqual(51, a.GetKopecks());
        }

        // 48. Перевірка постфіксного ++
        TEST_METHOD(TestMoneyCPostfixIncrement)
        {
            MoneyC a(100, 50);

            MoneyC old = a++;

            Assert::AreEqual(100L, old.GetHryvnias());
            Assert::AreEqual(50, old.GetKopecks());

            Assert::AreEqual(100L, a.GetHryvnias());
            Assert::AreEqual(51, a.GetKopecks());
        }

        // 49. Перевірка префіксного --
        TEST_METHOD(TestMoneyCPrefixDecrement)
        {
            MoneyC a(100, 50);

            --a;

            Assert::AreEqual(100L, a.GetHryvnias());
            Assert::AreEqual(49, a.GetKopecks());
        }

        // 50. Перевірка постфіксного --
        TEST_METHOD(TestMoneyCPostfixDecrement)
        {
            MoneyC a(100, 50);

            MoneyC old = a--;

            Assert::AreEqual(100L, old.GetHryvnias());
            Assert::AreEqual(50, old.GetKopecks());

            Assert::AreEqual(100L, a.GetHryvnias());
            Assert::AreEqual(49, a.GetKopecks());
        }

        // 51. Перевірка конструктора копіювання MoneyC
        TEST_METHOD(TestMoneyCCopy)
        {
            MoneyC a(100, 50);
            MoneyC b(a);

            Assert::AreEqual(100L, b.GetHryvnias());
            Assert::AreEqual(50, b.GetKopecks());
        }

        // 52. Перевірка оператора присвоювання MoneyC
        TEST_METHOD(TestMoneyCAssignment)
        {
            MoneyC a(100, 50);
            MoneyC b;

            b = a;

            Assert::AreEqual(100L, b.GetHryvnias());
            Assert::AreEqual(50, b.GetKopecks());
        }

        // 53. Перевірка перетворення MoneyC у string
        TEST_METHOD(TestMoneyCString)
        {
            MoneyC a(100, 5);

            string result = (string)a;

            Assert::IsTrue(result == "100,05 UAH");
        }

        // 54. Перевірка введення та виведення MoneyC
        TEST_METHOD(TestMoneyCInputOutput)
        {
            MoneyC a;

            std::istringstream input("100 50");
            input >> a;

            Assert::AreEqual(100L, a.GetHryvnias());
            Assert::AreEqual(50, a.GetKopecks());

            std::ostringstream output;
            output << a;

            Assert::IsTrue(output.str() == "100,50 UAH");
        }
    };
}