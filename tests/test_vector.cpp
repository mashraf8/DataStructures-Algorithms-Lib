#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/Vector.hpp"

using namespace std;
using namespace DataStrcture;
void TestVector()
{
    Vector<int> myarry(4);

    myarry.Fill();
    cout << "The Item In Index 2 Is: " << myarry[2] << "\n";
    myarry.Print();

    cout << "Array Of Size = " << myarry.GetCapacity() << " Array Of Lenght = " << myarry.GetLenght() << "\n";

    cout << "Append New Item" << "\n";
    int item_app;
    cin >> item_app;
    myarry.PushBack(item_app);
    myarry.Print();

    int newitem;
    int index;
    cout << "Insert New Item\n";
    cin >> newitem;
    cout << "What Is The Index\n";
    cin >> index;
    myarry.Insert(newitem, index);
    myarry.Print();

    cout << "Select Item by index" << "\n";
    int search_val;
    cin >> search_val;
    cout << "Index Is " << myarry.At(search_val) << "\n";

    int delet_index;
    cout << "Enter Index Will Delete\n";
    cin >> delet_index;
    myarry.EraseByIndex(delet_index);
    myarry.Print();
}

int main()
{
    try
    {
        TestVector();
    }
    catch (exception& e)
    {
        cout << "Exception Is: " << e.what() << endl;
    }
    cout << "Press Enter to exit...\n";
    cin.ignore();
    cin.get();
    return 0;

}