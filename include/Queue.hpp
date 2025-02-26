#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include "LinkedList.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class QueueWithLinkedList
    {
    private:
        DoublyLinkedList<T>* _list;
    public:
        QueueWithLinkedList()
        {
            _list = new DoublyLinkedList<T>();
        }
        ~QueueWithLinkedList()
        {
            Clear();
        }
        void Enqueue(T item)
        {
            _list->InsertFirst(item);
        }
        void Fill()
        {
            _list->Fill();
        }
        T Dequeue()
        {
            T ret = _list->SelectBackward(0);
            _list->DeleteAtEnd();
            return ret;
        }
        T Peek()
        {
            return _list->SelectBackward(0);
        }
        bool IsEmpty()
        {
            return _list->Isembty();
        }
        int Count()
        {
            return _list->Count();
        }
        void DisplayForward()
        {
            _list->DisplayForward();
        }
        void DisplayBackward()
        {
            _list->DisplayBackward();
        }
        void Clear()
        {
            _list->Clear();
        }


    };
}
#endif 