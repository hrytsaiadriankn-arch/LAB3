
#include "SymString.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<SymString*> objects;

    int choice;

    cout << "===== LABORATORY WORK 3.4 =====" << endl;
    cout << "Variant 14" << endl;

    do
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Create SymString" << endl;
        cout << "2. Create DecString" << endl;
        cout << "3. Show all objects" << endl;
        cout << "4. Show binary value" << endl;
        cout << "5. Subtract objects" << endl;
        cout << "6. Delete object" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";

        cin >> choice;

        if (!cin)
        {
            cout << "Input error!" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
        {
            string id, value;

            cout << "Enter ID: ";
            getline(cin >> ws, id);

            cout << "Enter string: ";
            getline(cin, value);

            objects.push_back(
                Factory::CreateSymString(id, value)
            );

            cout << "SymString created!" << endl;
            break;
        }

        case 2:
        {
            string id, value;

            cout << "Enter ID: ";
            getline(cin >> ws, id);

            cout << "Enter decimal number: ";
            getline(cin, value);

            objects.push_back(
                Factory::CreateDecString(id, value)
            );

            cout << "DecString created!" << endl;
            break;
        }

        case 3:
        {
            if (objects.empty())
            {
                cout << "No objects!" << endl;
                break;
            }

            for (size_t i = 0; i < objects.size(); i++)
            {
                cout << "\nObject " << i << ":" << endl;
                objects[i]->Show();
            }

            break;
        }

        case 4:
        {
            int index;

            cout << "Enter object index: ";
            cin >> index;

            if (index < 0 ||
                index >= static_cast<int>(objects.size()))
            {
                cout << "Invalid index!" << endl;
                break;
            }

            DecString* decimal =
                dynamic_cast<DecString*>(objects[index]);

            if (decimal == nullptr)
            {
                cout << "This object is not DecString!" << endl;
            }
            else
            {
                decimal->ShowBin();
            }

            break;
        }

        case 5:
        {
            int first, second;

            cout << "Enter first object index: ";
            cin >> first;

            cout << "Enter second object index: ";
            cin >> second;

            if (first < 0 || second < 0 ||
                first >= static_cast<int>(objects.size()) ||
                second >= static_cast<int>(objects.size()))
            {
                cout << "Invalid index!" << endl;
                break;
            }

            DecString* d1 =
                dynamic_cast<DecString*>(objects[first]);

            DecString* d2 =
                dynamic_cast<DecString*>(objects[second]);

            if (d1 != nullptr && d2 != nullptr)
            {
                DecString result = *d1 - *d2;

                cout << "Subtraction result:" << endl;
                result.Show();
            }
            else
            {
                SymString result = *objects[first] - *objects[second];

                cout << "String subtraction result:" << endl;
                result.Show();
            }

            break;
        }

        case 6:
        {
            int index;

            cout << "Enter object index to delete: ";
            cin >> index;

            if (index < 0 ||
                index >= static_cast<int>(objects.size()))
            {
                cout << "Invalid index!" << endl;
                break;
            }

            Factory::Delete(objects[index]);

            objects.erase(objects.begin() + index);

            cout << "Object deleted!" << endl;
            break;
        }

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid menu option!" << endl;
        }

    } while (choice != 0);

    // Видалення всіх об'єктів, що залишилися
    for (SymString* obj : objects)
    {
        Factory::Delete(obj);
    }

    objects.clear();

    cout << "All objects deleted." << endl;
    cout << "Program finished!" << endl;

    return 0;
}
