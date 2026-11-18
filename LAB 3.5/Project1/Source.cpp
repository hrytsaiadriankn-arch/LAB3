
#include "PriceList.h"
#include <iostream>
#include <limits>

using namespace std;

void PrintModels(const vector<Model>& models)
{
    if (models.empty())
    {
        cout << "No models found!\n";
        return;
    }

    for (const Model& model : models)
    {
        cout << "\n";
        model.Display();
    }
}

int main()
{
    try
    {
        // Creating two price lists
        PriceList first("18.11.2026", 41.50);
        PriceList second("18.11.2026", 41.50);

        // Creating an array of Model objects
        Model sampleModels[2] =
        {
            Model("Dell", "Intel Core i5", 3.2, 16, 512, 4, 750, 5),
            Model("HP", "Intel Core i7", 3.8, 32, 1000, 8, 1200, 3)
        };

        // Adding models to the first price list
        first.AddModel(sampleModels[0]);
        first.AddModel(sampleModels[1]);

        // Adding models to the second price list
        second.AddModel(
            Model("Dell", "Intel Core i5", 3.2, 16, 512, 4, 750, 2));

        second.AddModel(
            Model("Lenovo", "AMD Ryzen 7", 4.0, 16, 1000, 6, 950, 4));

        int choice;

        do
        {
            cout << "\n========== COMPUTER PRICE LIST ==========\n";
            cout << "1. Add model\n";
            cout << "2. Change model\n";
            cout << "3. Delete model\n";
            cout << "4. Search model by brand\n";
            cout << "5. Search by RAM\n";
            cout << "6. Search by hard disk\n";
            cout << "7. Search by video memory\n";
            cout << "8. Display price lists\n";
            cout << "9. Calculate total sum\n";
            cout << "10. Union of price lists\n";
            cout << "11. Intersection of price lists\n";
            cout << "12. Difference of price lists\n";
            cout << "0. Exit\n";

            cout << "\nChoose an option: ";

            if (!(cin >> choice))
                throw invalid_argument("Invalid menu choice!");

            int listNumber;
            string brand;

            switch (choice)
            {
            case 1:
            {
                cout << "Choose price list (1 or 2): ";
                cin >> listNumber;

                Model model;
                model.Read();

                if (listNumber == 1)
                    first.AddModel(model);
                else if (listNumber == 2)
                    second.AddModel(model);
                else
                    throw invalid_argument("Invalid price list!");

                cout << "Model added successfully!\n";
                break;
            }

            case 2:
            {
                cout << "Choose price list (1 or 2): ";
                cin >> listNumber;

                cout << "Enter old brand: ";
                getline(cin >> ws, brand);

                Model model;
                model.Read();

                if (listNumber == 1)
                    first.ChangeModel(brand, model);
                else if (listNumber == 2)
                    second.ChangeModel(brand, model);
                else
                    throw invalid_argument("Invalid price list!");

                cout << "Model changed successfully!\n";
                break;
            }

            case 3:
            {
                cout << "Choose price list (1 or 2): ";
                cin >> listNumber;

                cout << "Enter brand to delete: ";
                getline(cin >> ws, brand);

                if (listNumber == 1)
                    first.DeleteModel(brand);
                else if (listNumber == 2)
                    second.DeleteModel(brand);
                else
                    throw invalid_argument("Invalid price list!");

                cout << "Model deleted successfully!\n";
                break;
            }

            case 4:
            {
                cout << "Choose price list (1 or 2): ";
                cin >> listNumber;

                cout << "Enter brand: ";
                getline(cin >> ws, brand);

                Model result;

                if (listNumber == 1)
                    result = first.FindByBrand(brand);
                else if (listNumber == 2)
                    result = second.FindByBrand(brand);
                else
                    throw invalid_argument("Invalid price list!");

                cout << "\nFound model:\n";
                result.Display();
                break;
            }

            case 5:
            case 6:
            case 7:
            {
                cout << "Choose price list (1 or 2): ";
                cin >> listNumber;

                int value;
                int mode;

                cout << "Enter required value: ";
                cin >> value;

                cout << "1 - Exactly this value\n";
                cout << "2 - This value or greater\n";
                cout << "Choose search mode: ";
                cin >> mode;

                if (mode != 1 && mode != 2)
                    throw invalid_argument("Invalid search mode!");

                bool exact = (mode == 1);
                vector<Model> result;

                if (listNumber == 1)
                {
                    if (choice == 5)
                        result = first.SearchByRAM(value, exact);
                    else if (choice == 6)
                        result = first.SearchByHardDisk(value, exact);
                    else
                        result = first.SearchByVideoMemory(value, exact);
                }
                else if (listNumber == 2)
                {
                    if (choice == 5)
                        result = second.SearchByRAM(value, exact);
                    else if (choice == 6)
                        result = second.SearchByHardDisk(value, exact);
                    else
                        result = second.SearchByVideoMemory(value, exact);
                }
                else
                {
                    throw invalid_argument("Invalid price list!");
                }

                cout << "\nSearch results:\n";
                PrintModels(result);
                break;
            }

            case 8:
            {
                cout << "\nFIRST PRICE LIST:\n";
                first.Display();

                cout << "\nSECOND PRICE LIST:\n";
                second.Display();
                break;
            }

            case 9:
            {
                cout << "\nFirst price list:\n";
                cout << "Total: " << first.CalculateTotal()
                    << " conditional units\n";
                cout << "Total in UAH: " << first.CalculateTotalUAH()
                    << " UAH\n";

                cout << "\nSecond price list:\n";
                cout << "Total: " << second.CalculateTotal()
                    << " conditional units\n";
                cout << "Total in UAH: " << second.CalculateTotalUAH()
                    << " UAH\n";
                break;
            }

            case 10:
            {
                PriceList result = first + second;

                cout << "\nUNION OF PRICE LISTS:\n";
                result.Display();
                break;
            }

            case 11:
            {
                PriceList result = first & second;

                cout << "\nINTERSECTION OF PRICE LISTS:\n";
                result.Display();
                break;
            }

            case 12:
            {
                PriceList result = first - second;

                cout << "\nDIFFERENCE OF PRICE LISTS:\n";
                result.Display();
                break;
            }

            case 0:
                cout << "Program finished.\n";
                break;

            default:
                cout << "Invalid menu option!\n";
            }

        } while (choice != 0);
    }
    catch (const exception& error)
    {
        cout << "\nERROR: " << error.what() << endl;
        return 1;
    }

    return 0;
}
