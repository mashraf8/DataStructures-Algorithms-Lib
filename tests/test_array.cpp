#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/Array.hpp"

using namespace std;
using namespace DataStrcture;
void TestArray()
{
    int size;
    cout << "Enter Size Of Array\n";
    cin >> size;
    Array<int> myarry(size);

    myarry.Fill();
    cout << "The Item In Index 2 Is: " << myarry[2] << "\n";
    myarry.Display();

    cout << "Array Of Size = " << myarry.GetSize() << " Array Of Lenght = " << myarry.GetLenght() << "\n";

    cout << "Append New Item" << "\n";
    int item_app;
    cin >> item_app;
    myarry.Append(item_app);
    myarry.Display();

    int newitem;
    int index;
    cout << "Insert New Item\n";
    cin >> newitem;
    cout << "What Is The Index\n";
    cin >> index;
    myarry.Insert(newitem, index);
    myarry.Display();

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << "Index Is " << myarry.SelectIndex(search_val) << "\n";

    int delet_index;
    cout << "Enter Index Will Delete\n";
    cin >> delet_index;
    myarry.DeleteByIndex(delet_index);
    myarry.Display();

    int newsize;
    cout << "How Many New Size\n ";
    cin >> newsize;
    myarry.Enlarge(newsize);
    cout << "Array Of Size = " << myarry.GetSize() << " Array Of Lenght = " << myarry.GetLenght() << "\n";
    myarry.Display();

    int size2;
    cout << "Enter Size Of Array\n";
    cin >> size2;
    Array<int> myarry2(size2);
    myarry2.Fill();
    myarry.Merge(myarry2);
    cout << "Array Of Size = " << myarry.GetSize() << " Array Of Lenght = " << myarry.GetLenght() << "\n";
    myarry.Display();

}

int main() 
{
    try
    {
        TestArray();
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