
#include "pch.h"
#include "CppUnitTest.h"
#include "Person.h"
#include "Employee.h"
#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // 1. Перевірка конструктора Person
        TEST_METHOD(TestPersonConstructor)
        {
            Person p("Adrian", 20);

            Assert::IsTrue(p.GetName() == "Adrian");
            Assert::AreEqual(20, p.GetAge());
        }

        // 2. Перевірка конструктора без параметрів
        TEST_METHOD(TestPersonDefaultConstructor)
        {
            Person p;

            Assert::IsTrue(p.GetName() == "Unknown");
            Assert::AreEqual(0, p.GetAge());
        }

        // 3. Перевірка SetName
        TEST_METHOD(TestSetName)
        {
            Person p;

            p.SetName("John");

            Assert::IsTrue(p.GetName() == "John");
        }

        // 4. Перевірка SetAge
        TEST_METHOD(TestSetAge)
        {
            Person p;

            p.SetAge(25);

            Assert::AreEqual(25, p.GetAge());
        }

        // 5. Перевірка конструктора копіювання Person
        TEST_METHOD(TestPersonCopyConstructor)
        {
            Person p1("Adrian", 20);
            Person p2(p1);

            Assert::IsTrue(p2.GetName() == "Adrian");
            Assert::AreEqual(20, p2.GetAge());
        }

        // 6. Перевірка оператора присвоювання Person
        TEST_METHOD(TestPersonAssignment)
        {
            Person p1("John", 30);
            Person p2;

            p2 = p1;

            Assert::IsTrue(p2.GetName() == "John");
            Assert::AreEqual(30, p2.GetAge());
        }

        // 7. Перевірка введення Person
        TEST_METHOD(TestPersonInput)
        {
            Person p;

            std::istringstream input("Adrian\n20\n");

            input >> p;

            Assert::IsTrue(p.GetName() == "Adrian");
            Assert::AreEqual(20, p.GetAge());
        }

        // 8. Перевірка виведення Person
        TEST_METHOD(TestPersonOutput)
        {
            Person p("Adrian", 20);

            std::ostringstream output;
            output << p;

            std::string expected =
                "Name: Adrian\n"
                "Age: 20\n";

            Assert::IsTrue(output.str() == expected);
        }

        // 9. Перевірка конструктора Employee
        TEST_METHOD(TestEmployeeConstructor)
        {
            Employee e("John", 30, "Programmer", 20000.0);

            Assert::IsTrue(e.GetName() == "John");
            Assert::AreEqual(30, e.GetAge());
            Assert::IsTrue(e.GetPosition() == "Programmer");
            Assert::AreEqual(20000.0, e.GetSalary(), 0.0001);
        }

        // 10. Перевірка конструктора без параметрів Employee
        TEST_METHOD(TestEmployeeDefaultConstructor)
        {
            Employee e;

            Assert::IsTrue(e.GetName() == "Unknown");
            Assert::AreEqual(0, e.GetAge());
            Assert::IsTrue(e.GetPosition() == "Unknown");
            Assert::AreEqual(0.0, e.GetSalary(), 0.0001);
        }

        // 11. Перевірка SetPosition
        TEST_METHOD(TestSetPosition)
        {
            Employee e;

            e.SetPosition("Manager");

            Assert::IsTrue(e.GetPosition() == "Manager");
        }

        // 12. Перевірка SetSalary
        TEST_METHOD(TestSetSalary)
        {
            Employee e;

            e.SetSalary(15000.0);

            Assert::AreEqual(15000.0, e.GetSalary(), 0.0001);
        }

        // 13. Перевірка конструктора копіювання Employee
        TEST_METHOD(TestEmployeeCopyConstructor)
        {
            Employee e1("John", 30, "Programmer", 20000.0);
            Employee e2(e1);

            Assert::IsTrue(e2.GetName() == "John");
            Assert::AreEqual(30, e2.GetAge());
            Assert::IsTrue(e2.GetPosition() == "Programmer");
            Assert::AreEqual(20000.0, e2.GetSalary(), 0.0001);
        }

        // 14. Перевірка оператора присвоювання Employee
        TEST_METHOD(TestEmployeeAssignment)
        {
            Employee e1("Michael", 35, "Director", 30000.0);
            Employee e2;

            e2 = e1;

            Assert::IsTrue(e2.GetName() == "Michael");
            Assert::AreEqual(35, e2.GetAge());
            Assert::IsTrue(e2.GetPosition() == "Director");
            Assert::AreEqual(30000.0, e2.GetSalary(), 0.0001);
        }

        // 15. Перевірка введення Employee
        TEST_METHOD(TestEmployeeInput)
        {
            Employee e;

            std::istringstream input(
                "Adrian\n20\nProgrammer\n20000\n"
            );

            input >> e;

            Assert::IsTrue(e.GetName() == "Adrian");
            Assert::AreEqual(20, e.GetAge());
            Assert::IsTrue(e.GetPosition() == "Programmer");
            Assert::AreEqual(20000.0, e.GetSalary(), 0.0001);
        }

        // 16. Перевірка виведення Employee
        TEST_METHOD(TestEmployeeOutput)
        {
            Employee e("John", 30, "Programmer", 20000.0);

            std::ostringstream output;
            output << e;

            std::string expected =
                "Name: John\n"
                "Age: 30\n"
                "Position: Programmer\n"
                "Salary: 20000\n";

            Assert::IsTrue(output.str() == expected);
        }

        // 17. Перевірка принципу підстановки
        TEST_METHOD(TestSubstitution)
        {
            Employee e("David", 40, "Manager", 25000.0);

            Person p = e;

            Assert::IsTrue(p.GetName() == "David");
            Assert::AreEqual(40, p.GetAge());
        }
    };
}
