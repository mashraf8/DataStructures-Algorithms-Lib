#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/SomeAlgorithm.hpp"

using namespace std;
using namespace DataStrcture;
void TestSomeAlgo()
{
    Vector<char> ch_ar(4);
    ch_ar.Fill();
    SomeAlgorForDataStrc<char>::MinHeapSortOfVector(ch_ar);
    ch_ar.Print();
    char item;
    cout << "Enter item you search\n";
    cin >> item;
    cout << SomeAlgorForDataStrc<char>::BinarySearchOfMinVector(ch_ar, item) << "\n";
}

int main()
{
    
    try
    {
        TestSomeAlgo();
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
