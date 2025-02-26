#include <iostream>
#include <random> 
#include <chrono> 
#include <string> 
#include "../include/Graph.hpp"

using namespace std;
using namespace DataStrcture;
void TestGraph()
{
    Graph<int> gr;
    for (int i = 0; i <= 100; i++)
    {
        gr.Insert(i);
    }

    gr.InsertEdge(0, 2, 5);
    gr.InsertEdge(0, 1, 4);
    gr.InsertEdge(0, 4, 8);
    gr.InsertEdge(1, 0, 1);
    gr.InsertEdge(1, 6, 1);
    gr.InsertEdge(1, 5, 5);
    gr.InsertEdge(2, 4, 7);
    gr.InsertEdge(2, 5, 6);
    gr.InsertEdge(3, 1, 3);
    gr.InsertEdge(3, 7, 5);
    gr.InsertEdge(3, 5, 2);
    gr.InsertEdge(4, 7, 3);
    gr.InsertEdge(5, 6, 9);
    gr.InsertEdge(5, 3, 5);
    gr.InsertEdge(5, 7, 3);
    gr.InsertEdge(6, 2, 3);
    gr.InsertEdge(6, 7, 5);
    gr.InsertEdge(7, 5, 4);

    cout << gr.SearchNode(6)->data << "\n";

    gr.PrintGraphByDFS(0);

    gr.ShortPathForAll(5);

    DoublyLinkedList<int>* pr = gr.AllItemPathForShortPath(5, 4);
    pr->DisplayBackward();
    cout << "The Cost Is: " << gr.CostForShortPath(5, 4) << "\n";

    gr.Update(4, 105);

    pr = gr.AllItemPathForShortPath(5, 105);
    pr->DisplayBackward();
    cout << "The Cost Is: " << gr.CostForShortPath(5, 105) << "\n";

    gr.UpdateCost(7, 5, 1);
    gr.PrintGraphByDFS(0);

}

int main()
{
    try
    {
        TestGraph();
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