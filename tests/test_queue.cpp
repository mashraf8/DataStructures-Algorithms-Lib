#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/Queue.hpp"

using namespace std;
using namespace DataStrcture;
void TestQueue()
{
    QueueWithLinkedList<int> que;
    que.Fill();
    que.DisplayBackward();
    cout << "Dequeue " << que.Dequeue() << "\n";
    cout << "Peek " << que.Peek() << "\n";
    que.DisplayBackward();
    que.Clear();
    cout << "Count After Delete " << que.Count() << "\n";
}

int main()
{
    try
    {
        TestQueue();
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