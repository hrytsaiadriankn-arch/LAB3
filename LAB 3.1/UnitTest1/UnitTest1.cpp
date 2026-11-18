
#include "pch.h"
#include "CppUnitTest.h"
#include "Number.h"
#include "Real.h"
#include <cmath>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Перевірка конструктора Number
        TEST_METHOD(TestNumberConstructor)
        {
            Number n(10.0);

            Assert::AreEqual(10.0, n.GetValue(), 0.0001);
        }

        // Перевірка методу SetValue
        TEST_METHOD(TestSetValue)
        {
            Number n;

            n.SetValue(25.5);

            Assert::AreEqual(25.5, n.GetValue(), 0.0001);
        }

        // Перевірка множення
        TEST_METHOD(TestMultiply)
        {
            Number n(10.0);

            n.Multiply(3.0);

            Assert::AreEqual(30.0, n.GetValue(), 0.0001);
        }

        // Перевірка віднімання
        TEST_METHOD(TestSubtract)
        {
            Number n(10.0);

            n.Subtract(3.0);

            Assert::AreEqual(7.0, n.GetValue(), 0.0001);
        }

        // Перевірка перетворення числа в рядок
        TEST_METHOD(TestStringConversion)
        {
            Number n(15.0);

            string result = (string)n;

            Assert::AreEqual(string("15"), result);
        }

        // Перевірка конструктора класу Real
        TEST_METHOD(TestRealConstructor)
        {
            Real r(27.0);

            Assert::AreEqual(27.0, r.GetValue(), 0.0001);
        }

        // Перевірка обчислення кубічного кореня
        TEST_METHOD(TestRoot)
        {
            Real r(27.0);

            double result = r.Root(3);

            Assert::AreEqual(3.0, result, 0.0001);
        }

        // Перевірка обчислення квадратного кореня
        TEST_METHOD(TestSquareRoot)
        {
            Real r(16.0);

            double result = r.Root(2);

            Assert::AreEqual(4.0, result, 0.0001);
        }

        // Перевірка кореня з від'ємного числа непарного степеня
        TEST_METHOD(TestNegativeRoot)
        {
            Real r(-8.0);

            double result = r.Root(3);

            Assert::AreEqual(-2.0, result, 0.0001);
        }

        // Перевірка піднесення числа PI до квадрату
        TEST_METHOD(TestPowerOfPi)
        {
            Real r(0.0);

            double result = r.PowerOfPi(2);

            Assert::AreEqual(9.8696044, result, 0.0001);
        }

        // Перевірка піднесення PI до першого степеня
        TEST_METHOD(TestPowerOfPiOne)
        {
            Real r(0.0);

            double result = r.PowerOfPi(1);

            Assert::AreEqual(3.1415926, result, 0.0001);
        }

        // Перевірка копіювання об'єкта
        TEST_METHOD(TestCopyConstructor)
        {
            Number n1(50.0);
            Number n2(n1);

            Assert::AreEqual(50.0, n2.GetValue(), 0.0001);
        }

        // Перевірка передачі похідного класу в базовий
        TEST_METHOD(TestSubstitution)
        {
            Real r(5.5);

            Number n = r;

            Assert::AreEqual(5.5, n.GetValue(), 0.0001);
        }
    };
}
