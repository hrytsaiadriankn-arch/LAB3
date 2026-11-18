
#include "pch.h"
#include "CppUnitTest.h"
#include "SymString.h"

#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(SymStringTests)
    {
    public:

        // Тест конструктора SymString
        TEST_METHOD(TestSymStringConstructor)
        {
            SymString s("S1", "Hello");

            Assert::AreEqual(string("S1"), s.GetId());
            Assert::AreEqual(string("Hello"), s.GetValue());
        }

        // Тест встановлення значень
        TEST_METHOD(TestSymStringSetters)
        {
            SymString s("S1", "Hello");

            s.SetId("S2");
            s.SetValue("World");

            Assert::AreEqual(string("S2"), s.GetId());
            Assert::AreEqual(string("World"), s.GetValue());
        }

        // Тест копіювання
        TEST_METHOD(TestSymStringCopyConstructor)
        {
            SymString first("S1", "Hello");
            SymString second(first);

            Assert::AreEqual(first.GetId(), second.GetId());
            Assert::AreEqual(first.GetValue(), second.GetValue());
        }

        // Тест оператора -
        TEST_METHOD(TestSymStringMinus)
        {
            SymString first("S1", "Hello World");
            SymString second("S2", "World");

            SymString result = first - second;

            Assert::AreEqual(string("Hello "), result.GetValue());
        }

        // Тест перетворення в string
        TEST_METHOD(TestSymStringConversion)
        {
            SymString s("S1", "Hello");

            string result = (string)s;

            Assert::AreEqual(string("Hello"), result);
        }

        // Тест конструктора DecString
        TEST_METHOD(TestDecStringConstructor)
        {
            DecString d("D1", "100");

            Assert::AreEqual(string("D1"), d.GetId());
            Assert::AreEqual(string("100"), d.GetValue());
        }

        // Тест встановлення десяткового числа
        TEST_METHOD(TestDecStringSetValue)
        {
            DecString d("D1", "100");

            d.SetValue("250");

            Assert::AreEqual(string("250"), d.GetValue());
        }

        // Тест віднімання десяткових чисел
        TEST_METHOD(TestDecStringMinus)
        {
            DecString first("D1", "100");
            DecString second("D2", "40");

            DecString result = first - second;

            Assert::AreEqual(string("60"), result.GetValue());
        }

        // Тест віднімання однакових чисел
        TEST_METHOD(TestDecStringMinusEqual)
        {
            DecString first("D1", "50");
            DecString second("D2", "50");

            DecString result = first - second;

            Assert::AreEqual(string("0"), result.GetValue());
        }

        // Тест перетворення DecString у string
        TEST_METHOD(TestDecStringConversion)
        {
            DecString d("D1", "123");

            string result = (string)d;

            Assert::AreEqual(string("123"), result);
        }

        // Тест методу ShowBin
        TEST_METHOD(TestShowBin)
        {
            DecString d("D1", "100");

            ostringstream output;
            streambuf* oldBuffer = cout.rdbuf(output.rdbuf());

            d.ShowBin();

            cout.rdbuf(oldBuffer);

            Assert::AreEqual(
                string("Binary: 1100100\n"),
                output.str()
            );
        }

        // Тест Factory для SymString
        TEST_METHOD(TestFactoryCreateSymString)
        {
            SymString* s = Factory::CreateSymString("S1", "Hello");

            Assert::IsNotNull(s);
            Assert::AreEqual(string("Hello"), s->GetValue());

            Factory::Delete(s);
        }

        // Тест Factory для DecString
        TEST_METHOD(TestFactoryCreateDecString)
        {
            SymString* s = Factory::CreateDecString("D1", "100");

            Assert::IsNotNull(s);
            Assert::AreEqual(string("100"), s->GetValue());

            Assert::IsNotNull(dynamic_cast<DecString*>(s));

            Factory::Delete(s);
        }
    };
}
