
#include "pch.h"
#include "CppUnitTest.h"
#include "PriceList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriceListUnitTests
{
    TEST_CLASS(PriceListTests)
    {
    public:

        // Test 1: Default Model constructor
        TEST_METHOD(TestModelDefaultConstructor)
        {
            Model model;

            Assert::IsTrue(model.GetRAM() == 1);
            Assert::IsTrue(model.GetHardDisk() == 1);
            Assert::IsTrue(model.GetQuantity() == 0);
        }

        // Test 2: Model constructor with parameters
        TEST_METHOD(TestModelParameterizedConstructor)
        {
            Model model("Dell", "Intel Core i5",
                3.2, 16, 512, 4, 750, 5);

            Assert::IsTrue(model.GetBrand() == "Dell");
            Assert::IsTrue(model.GetRAM() == 16);
            Assert::IsTrue(model.GetHardDisk() == 512);
            Assert::IsTrue(model.GetPrice() == 750);
        }

        // Test 3: Model validation
        TEST_METHOD(TestModelValidation)
        {
            Assert::ExpectException<std::invalid_argument>([]()
                {
                    Model model("Dell", "Intel", -1, 16, 512, 4, 750, 5);
                });
        }

        // Test 4: Add model
        TEST_METHOD(TestAddModel)
        {
            PriceList list("18.11.2026", 41.50);

            Model model("Dell", "Intel Core i5",
                3.2, 16, 512, 4, 750, 5);

            list.AddModel(model);

            Assert::AreEqual(1, list.GetCount());
        }

        // Test 5: Prevent duplicate brands
        TEST_METHOD(TestDuplicateModel)
        {
            PriceList list("18.11.2026", 41.50);

            Model first("Dell", "Intel Core i5",
                3.2, 16, 512, 4, 750, 5);

            Model second("Dell", "Intel Core i7",
                3.8, 32, 1000, 8, 1200, 3);

            list.AddModel(first);

            Assert::ExpectException<std::invalid_argument>([&]()
                {
                    list.AddModel(second);
                });
        }

        // Test 6: Find model by brand
        TEST_METHOD(TestFindByBrand)
        {
            PriceList list("18.11.2026", 41.50);

            Model model("HP", "Intel Core i7",
                3.8, 32, 1000, 8, 1200, 3);

            list.AddModel(model);

            Model result = list.FindByBrand("HP");

            Assert::IsTrue(result.GetBrand() == "HP");
            Assert::IsTrue(result.GetRAM() == 32);
        }

        // Test 7: Delete model
        TEST_METHOD(TestDeleteModel)
        {
            PriceList list("18.11.2026", 41.50);

            list.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            list.DeleteModel("Dell");

            Assert::AreEqual(0, list.GetCount());
        }

        // Test 8: Change model
        TEST_METHOD(TestChangeModel)
        {
            PriceList list("18.11.2026", 41.50);

            list.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            Model newModel("HP", "Intel i7",
                3.8, 32, 1000, 8, 1200, 3);

            list.ChangeModel("Dell", newModel);

            Assert::IsTrue(list[0].GetBrand() == "HP");
            Assert::AreEqual(32, list[0].GetRAM());
        }

        // Test 9: Search by RAM
        TEST_METHOD(TestSearchByRAM)
        {
            PriceList list("18.11.2026", 41.50);

            list.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            list.AddModel(Model("HP", "Intel i7",
                3.8, 32, 1000, 8, 1200, 3));

            vector<Model> result = list.SearchByRAM(16, true);

            Assert::AreEqual(1, (int)result.size());
            Assert::IsTrue(result[0].GetBrand() == "Dell");
        }

        // Test 10: Search by hard disk
        TEST_METHOD(TestSearchByHardDisk)
        {
            PriceList list("18.11.2026", 41.50);

            list.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            list.AddModel(Model("HP", "Intel i7",
                3.8, 32, 1000, 8, 1200, 3));

            vector<Model> result = list.SearchByHardDisk(512, false);

            Assert::AreEqual(2, (int)result.size());
        }

        // Test 11: Search by video memory
        TEST_METHOD(TestSearchByVideoMemory)
        {
            PriceList list("18.11.2026", 41.50);

            list.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            list.AddModel(Model("HP", "Intel i7",
                3.8, 32, 1000, 8, 1200, 3));

            vector<Model> result = list.SearchByVideoMemory(8, true);

            Assert::AreEqual(1, (int)result.size());
            Assert::IsTrue(result[0].GetBrand() == "HP");
        }

        // Test 12: Calculate total price
        TEST_METHOD(TestCalculateTotal)
        {
            PriceList list("18.11.2026", 41.50);

            list.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            double total = list.CalculateTotal();

            Assert::AreEqual(3750.0, total, 0.001);
        }

        // Test 13: Calculate total in UAH
        TEST_METHOD(TestCalculateTotalUAH)
        {
            PriceList list("18.11.2026", 41.50);

            list.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            double total = list.CalculateTotalUAH();

            Assert::AreEqual(155625.0, total, 0.001);
        }

        // Test 14: Union of price lists
        TEST_METHOD(TestUnion)
        {
            PriceList first("18.11.2026", 41.50);
            PriceList second("18.11.2026", 41.50);

            first.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            first.AddModel(Model("HP", "Intel i7",
                3.8, 32, 1000, 8, 1200, 3));

            second.AddModel(Model("Lenovo", "AMD Ryzen 7",
                4.0, 16, 1000, 6, 950, 4));

            PriceList result = first + second;

            Assert::AreEqual(3, result.GetCount());
            Assert::AreEqual(2, first.GetCount());
            Assert::AreEqual(1, second.GetCount());
        }

        // Test 15: Intersection of price lists
        TEST_METHOD(TestIntersection)
        {
            PriceList first("18.11.2026", 41.50);
            PriceList second("18.11.2026", 41.50);

            first.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            first.AddModel(Model("HP", "Intel i7",
                3.8, 32, 1000, 8, 1200, 3));

            second.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 2));

            second.AddModel(Model("Lenovo", "AMD Ryzen 7",
                4.0, 16, 1000, 6, 950, 4));

            PriceList result = first & second;

            Assert::AreEqual(1, result.GetCount());
            Assert::IsTrue(result[0].GetBrand() == "Dell");
        }

        // Test 16: Difference of price lists
        TEST_METHOD(TestDifference)
        {
            PriceList first("18.11.2026", 41.50);
            PriceList second("18.11.2026", 41.50);

            first.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 5));

            first.AddModel(Model("HP", "Intel i7",
                3.8, 32, 1000, 8, 1200, 3));

            second.AddModel(Model("Dell", "Intel i5",
                3.2, 16, 512, 4, 750, 2));

            PriceList result = first - second;

            Assert::AreEqual(1, result.GetCount());
            Assert::IsTrue(result[0].GetBrand() == "HP");
        }
    };
}
