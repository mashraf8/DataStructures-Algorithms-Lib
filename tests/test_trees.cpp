#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/Trees.hpp"

using namespace std;
using namespace DataStrcture;
void TestBinarySearchTree()
{
    BinarySearchTree<int> bin;
    bin.Fill();
    bin.DisplayTree();

    int delet_item;
    cout << "Enter Item Will Delete\n";
    cin >> delet_item;
    bin.Delete(delet_item);
    bin.DisplayTree();

    cout << "What is the item search it" << "\n";
    int item;
    cin >> item;
    cout << bin.SearchBool(item) << "\n";

    cout << "The Small Item In The Tree" << "\n";
    cout << bin.MinItem() << "\n";
    cout << "The Big Item In The Tree" << "\n";
    cout << bin.MaxItem() << "\n";

    cout << "The Height Of Tree Is: " << bin.Height() << "\n";

    cout << "Is Red Black Balanced: " << bin.IsRedBlackTreeBalance() << "\n";

    bin.Clear();
    bin.Fill();
    bin.DisplayTree();
}
void TestRedBlackTree()
{
    RedBlackTree<int> rebl;
    rebl.Fill();
    rebl.DisplayTree();

    int delet_item;
    cout << "Enter Item Will Delete\n";
    cin >> delet_item;
    rebl.Delete(delet_item);
    rebl.DisplayTree();
}
void TestAVLTree()
{
    AVLTree<char> avt;
    avt.Fill();
    avt.Fill();
    avt.DisplayTree();

    char delet_item;
    cout << "Enter Item Will Delete\n";
    cin >> delet_item;
    avt.Delete(delet_item);
    avt.DisplayTree();
}
void TestBTree()
{
    BTree<int> tree(2);

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000000; i++)
    {

        tree.Insert(i);
    }
    for (int i = 4; i <= 1000000; i++)
    {
        tree.Delete(i);

    }
    for (int i = 4; i <= 100; i++)
    {

        tree.Insert(i);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";

    cout << tree.MinItem() << "\n";
    cout << tree.MaxItem() << "\n";
    tree.Display();

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << *tree.SelectItem(search_val) << "\n";

    cout << "What the old item:" << "\n";
    int old_val;
    cin >> old_val;
    cout << "What the new item:" << "\n";
    int new_val;
    cin >> new_val;
    tree.Update(old_val, new_val);
    tree.Display();
    cout << "\n";
    tree.Clear();
    for (int i = 4; i <= 7; i++)
    {

        tree.Insert(i);
    }
    tree.Display();



}
void TestBPlusTree()
{
    BPlusTree<int> tree(2);

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 3000000; i++)
    {

        tree.Insert(i);
    }
    for (int i = 4; i <= 3000000; i++)
    {
        tree.Delete(i);

    }
    for (int i = 4; i <= 7; i++)
    {

        tree.Insert(i);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";

    cout << tree.MinItem() << "\n";
    cout << tree.MaxItem() << "\n";
    tree.Display();

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << *tree.SelectItem(search_val) << "\n";

    cout << "What the old item:" << "\n";
    int old_val;
    cin >> old_val;
    cout << "What the new item:" << "\n";
    int new_val;
    cin >> new_val;
    tree.Update(old_val, new_val);
    tree.Display();
    cout << "\n";
    tree.Clear();
    for (int i = 4; i <= 7; i++)
    {

        tree.Insert(i);
    }
    tree.Display();



}

int main()
{
    
    try
    {
        cout << "Start Binary Search Tree Test:\n";
        TestBinarySearchTree();
        cout << "Start Red Black Tree Test:\n";
        TestRedBlackTree();
        cout << "Start Avl Tree Test:\n";
        TestAVLTree();
        cout << "Start B-Tree Test:\n";
        TestBTree();
        cout << "Start BPluseTree Test:\n";
        TestBPlusTree();
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