#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/Heap.hpp"

using namespace std;
using namespace DataStrcture;
void TestHeap()
{
    MaxHeap<int> heap(10);
    heap.Fill();
    heap.Print();
    cout << "how many item will delete" << "\n";
    int n;
    cin >> n;
    int newitem;
    int olditem;


    for (int i = 1; i <= n; i++)
    {
        cout << "enter olditem\n";
        cin >> olditem;
        cout << "enter newitem\n";
        cin >> newitem;

        heap.UpdateByItem(newitem, olditem);

    }
    
}

int main()
{
    try
    {
        TestHeap();
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