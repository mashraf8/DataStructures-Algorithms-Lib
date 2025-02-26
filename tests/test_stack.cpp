#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/Stack.hpp"

using namespace std;
using namespace DataStrcture;
void TestStack()
{
	StackWithLinkedList<int>* sta = new StackWithLinkedList<int>();
	sta->Fill();
	sta->Display();

	StackWithLinkedList<int>* sta2 = new StackWithLinkedList<int>();
	sta2->Fill();
	sta2->Display();

	sta->Swap(sta2);
	sta->Display();
	sta2->Display();

}

int main()
{
    try
    {
        TestStack();
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