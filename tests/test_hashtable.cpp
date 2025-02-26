#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/HashTable.hpp"

using namespace std;
using namespace DataStrcture;
void TestHashTableWithLinkedList()
{
    HashTableWithLinkedList<int> ha(10000);
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000000; i++)
    {

        ha.Insert(i);
    }
    cout << ha.CalculateStandardDeviation() << "\n";
    ha.Clear();
    for (int i = 1; i <= 1000000; i++)
    {

        ha.Insert(i);
    }
    for (int i = 1; i <= 1000000; i++)
    {
        ha.Delete(i);
    }
    for (int i = 1; i <= 10; i++)
    {

        ha.Insert(i);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";
    ha.Display();

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << *ha.SelectItem(search_val) << "\n";


    cout << "What the old item:" << "\n";
    int old_val;
    cin >> old_val;
    cout << "What the new item:" << "\n";
    int new_val;
    cin >> new_val;
    ha.Update(old_val, new_val);

    cout << ha.CalculateStandardDeviation() << "\n";

    ha.Display();

}
void TestHashTableWithBPlusTree()
{
    HashTableWithBPlusTree<int> ha(10000, 3);
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000000; i++)
    {

        ha.Insert(i);
    }
    cout << ha.CalculateStandardDeviation() << "\n";
    ha.Clear();
    for (int i = 1; i <= 3000000; i++)
    {

        ha.Insert(i);
    }
    for (int i = 1; i <= 3000000; i++)
    {
        ha.Delete(i);
    }
    for (int i = 1; i <= 10; i++)
    {

        ha.Insert(i);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";
    ha.Display();

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << *ha.SelectItem(search_val) << "\n";


    cout << "What the old item:" << "\n";
    int old_val;
    cin >> old_val;
    cout << "What the new item:" << "\n";
    int new_val;
    cin >> new_val;
    ha.Update(old_val, new_val);

    cout << ha.CalculateStandardDeviation() << "\n";

    ha.Display();
}
void TestHashTableWithAnyDataStrc()
{
    HashTableWithAnyDataStrc<DoublyLinkedList<int>, int> ha(10000);
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000000; i++)
    {
        ha.SelectDataStrcByItem(i).InsertFirst(i);
    }
    for (int i = 1; i <= 1000000; i++)
    {
        ha.SelectDataStrcByItem(i).DeleteByValue(i);
    }
    for (int i = 1; i <= 10; i++)
    {
        ha.SelectDataStrcByItem(i).InsertFirst(i);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";

    for (int i = 0; i < 10000; i++)
    {
        DoublyLinkedList<int>* sel = &ha.SelectDataStrcByIndex(i);
        if (!sel->Isembty())
        {
            cout << "LinkedList at index: " << i << " ";
            sel->DisplayForward();
        }
    }
}

int main()
{
   
    try
    {
        cout << "Start Hash Table With Linked List Test:" << "\n";
        TestHashTableWithLinkedList();
        cout << "Start Hash Table With BPluseTree Test:" << "\n";
        TestHashTableWithBPlusTree();
        cout << "Start Hash Table With Any DataStrc Test:" << "\n";
        TestHashTableWithAnyDataStrc();
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