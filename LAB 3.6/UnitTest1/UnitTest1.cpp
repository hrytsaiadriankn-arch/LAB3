
#include "pch.h"
#include "CppUnitTest.h"

#include "B1.h"
#include "D1.h"
#include "D2.h"
#include "B2.h"
#include "D3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InheritanceUnitTests
{
    TEST_CLASS(InheritanceTests)
    {
    public:

        // Test 1: Create object B1
        TEST_METHOD(TestB1Constructor)
        {
            B1 obj(10);

            Assert::AreEqual(sizeof(int), sizeof(B1));
            obj.show();
        }

        // Test 2: Create object D1
        TEST_METHOD(TestD1Constructor)
        {
            D1 obj(20, 21);

            Assert::AreEqual(2 * sizeof(int), sizeof(D1));
            obj.show();
        }

        // Test 3: Create object D2
        TEST_METHOD(TestD2Constructor)
        {
            D2 obj(30, 31);

            Assert::AreEqual(2 * sizeof(int), sizeof(D2));
            obj.show();
        }

        // Test 4: Create object B2
        TEST_METHOD(TestB2Constructor)
        {
            B2 obj(40);

            Assert::AreEqual(sizeof(int), sizeof(B2));
            obj.show();
        }

        // Test 5: Create object D3
        TEST_METHOD(TestD3Constructor)
        {
            D3 obj(50, 60, 61, 70, 71, 80);

            Assert::AreEqual(6 * sizeof(int), sizeof(D3));
            obj.show();
        }

        // Test 6: Public inheritance D1 from B1
        TEST_METHOD(TestPublicInheritance)
        {
            D1 obj(100, 200);

            B1* base = &obj;

            Assert::IsNotNull(base);
            obj.show();
        }

        // Test 7: Multiple inheritance
        TEST_METHOD(TestMultipleInheritance)
        {
            D3 obj(1, 2, 3, 4, 5, 6);

            D1* firstBase = &obj;
            D2* secondBase = &obj;

            Assert::IsNotNull(firstBase);
            Assert::IsNotNull(secondBase);

            obj.show();
        }

        // Test 8: Object sizes
        TEST_METHOD(TestAllObjectSizes)
        {
            Assert::AreEqual(sizeof(int), sizeof(B1));
            Assert::AreEqual(2 * sizeof(int), sizeof(D1));
            Assert::AreEqual(2 * sizeof(int), sizeof(D2));
            Assert::AreEqual(sizeof(int), sizeof(B2));
            Assert::AreEqual(6 * sizeof(int), sizeof(D3));
        }

        // Test 9: Destructors
        TEST_METHOD(TestDestructors)
        {
            {
                B1 obj1(10);
                D1 obj2(20, 30);
                D2 obj3(40, 50);
                B2 obj4(60);
                D3 obj5(1, 2, 3, 4, 5, 6);

                Assert::IsTrue(sizeof(obj5) > sizeof(obj1));
            }
        }
    };
}
