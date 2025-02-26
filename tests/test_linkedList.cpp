#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/LinkedList.hpp"

using namespace std;
using namespace DataStrcture;
void TestSinglyLinkedList()
{
    SinglyLinkedList<int> lin;

    lin.Fill();

    lin.DisplayForward();

    cout << "The Count" << "\n";
    cout << lin.Count() << "\n";

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << lin.IsFound(search_val) << "\n";

    cout << "What Is The Item That Insert Befor It" << "\n";
    int insert_befor_it;
    cin >> insert_befor_it;
    cout << "What Is The New Item" << "\n";
    int new_item;
    cin >> new_item;
    lin.InsertBefore(insert_befor_it, new_item);
    lin.DisplayForward();


    cout << "What is The Item Will Append it" << "\n";
    int new_item_append;
    cin >> new_item_append;
    lin.Append(new_item_append);
    lin.DisplayForward();


    cout << "What Is The Item Will Delete\n";
    int item_delete;
    cin >> item_delete;
    lin.DeleteByValue(item_delete);
    lin.DisplayForward();
    lin.DeleteAtBeginning();
    lin.DisplayForward();
    lin.DeleteAtEnd();
    lin.DisplayForward();

    cout << "Select Item By Index\n";
    int index;
    cin >> index;
    cout << lin.SelectForward(index) << "\n";

    cout << "What Is The Index  Will Update\n";
    int update_index;
    cin >> update_index;
    cout << "What Is The New Item\n";
    int new_ite;
    cin >> new_ite;
    lin.Update(update_index, new_ite);
    lin.DisplayForward();

    cout << "What Is The Index  Will Insert in it\n";
    int insert_index;
    cin >> insert_index;
    cout << "What Is The New Item\n";
    int new_itemm_2;
    cin >> new_itemm_2;
    lin.InsertByIndex(insert_index, new_itemm_2);
    lin.DisplayForward();

    cout << "What Is The Index  Will Delete in it\n";
    int delete_index;
    cin >> delete_index;
    lin.DeleteByIndex(delete_index);
    lin.DisplayForward();

    lin.Clear();
}
void TestDoublyLinkedList()
{
    DoublyLinkedList<int> lin;

    lin.Fill();

    lin.DisplayForward();
    lin.DisplayBackward();

    cout << "The Count" << "\n";
    cout << lin.Count() << "\n";

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << lin.IsFound(search_val) << "\n";

    cout << "What Is The Item That Insert Befor It" << "\n";
    int insert_befor_it;
    cin >> insert_befor_it;
    cout << "What Is The New Item" << "\n";
    int new_item;
    cin >> new_item;
    lin.InsertBefore(insert_befor_it, new_item);
    lin.DisplayForward();
    lin.DisplayBackward();


    cout << "What is The Item Will Append it" << "\n";
    int new_item_append;
    cin >> new_item_append;
    lin.Append(new_item_append);
    lin.DisplayForward();
    lin.DisplayBackward();


    cout << "What Is The Item Will Delete\n";
    int item_delete;
    cin >> item_delete;
    lin.DeleteByValue(item_delete);
    lin.DisplayForward();
    lin.DisplayBackward();
    lin.DeleteAtBeginning();
    lin.DisplayForward();
    lin.DisplayBackward();
    lin.DeleteAtEnd();
    lin.DisplayForward();
    lin.DisplayBackward();

    cout << "Select Item By Index From Forward\n";
    int index_1;
    cin >> index_1;
    cout << lin.SelectForward(index_1) << "\n";

    cout << "Select Item By Index From Backward\n";
    int index_2;
    cin >> index_2;
    cout << lin.SelectBackward(index_2) << "\n";

    cout << "What Is The Index  Will Update\n";
    int update_index;
    cin >> update_index;
    cout << "What Is The New Item\n";
    int new_ite;
    cin >> new_ite;
    lin.Update(update_index, new_ite);
    lin.DisplayForward();

    cout << "What Is The Index  Will Insert in it\n";
    int insert_index;
    cin >> insert_index;
    cout << "What Is The New Item\n";
    int new_itemm_2;
    cin >> new_itemm_2;
    lin.InsertByIndex(insert_index, new_itemm_2);
    lin.DisplayForward();

    cout << "What Is The Index  Will Delete in it\n";
    int delete_index;
    cin >> delete_index;
    lin.DeleteByIndex(delete_index);
    lin.DisplayForward();

    lin.Clear();
}
void TestCircularSinglyLinkedList()
{
    CircularSinglyLinkedList<int> lin;

    lin.Fill();

    lin.DisplayForward();

    cout << "The Count" << "\n";
    cout << lin.Count() << "\n";

    cout << "What do you search" << "\n";
    int search_val;
    cin >> search_val;
    cout << lin.IsFound(search_val) << "\n";

    cout << "What Is The Item That Insert Befor It" << "\n";
    int insert_befor_it;
    cin >> insert_befor_it;
    cout << "What Is The New Item" << "\n";
    int new_item;
    cin >> new_item;
    lin.InsertBefore(insert_befor_it, new_item);
    cout << "The Count" << "\n";
    cout << lin.Count() << "\n";
    lin.DisplayForward();


    cout << "What is The Item Will Append it" << "\n";
    int new_item_append;
    cin >> new_item_append;
    lin.Append(new_item_append);
    cout << "The Count" << "\n";
    cout << lin.Count() << "\n";
    lin.DisplayForward();


    cout << "What Is The Item Will Delete\n";
    int item_delete;
    cin >> item_delete;
    lin.DeleteByValue(item_delete);
    lin.DisplayForward();
    lin.DeleteAtBeginning();
    lin.DisplayForward();
    lin.DeleteAtEnd();
    lin.DisplayForward();

    cout << "Select Item By Index\n";
    int index;
    cin >> index;
    cout << lin.SelectForward(index) << "\n";


    cout << "What Is The Index  Will Update\n";
    int update_index;
    cin >> update_index;
    cout << "What Is The New Item\n";
    int new_ite;
    cin >> new_ite;
    lin.Update(update_index, new_ite);
    lin.DisplayForward();

    cout << "What Is The Index  Will Insert in it\n";
    int insert_index;
    cin >> insert_index;
    cout << "What Is The New Item\n";
    int new_itemm_2;
    cin >> new_itemm_2;
    lin.InsertByIndex(insert_index, new_itemm_2);
    lin.DisplayForward();

    cout << "What Is The Index  Will Delete in it\n";
    int delete_index;
    cin >> delete_index;
    lin.DeleteByIndex(delete_index);
    lin.DisplayForward();

    lin.Clear();
}

int main()
{
   
    try
    {
        cout << "Start Singly LinkedList Test:" << "\n";
        TestSinglyLinkedList();
        cout << "Start Test Doubly LinkedList Test:" << "\n";
        TestDoublyLinkedList();
        cout << "Start Test Circular Singly LinkedList Test:" << "\n";
        TestCircularSinglyLinkedList();
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