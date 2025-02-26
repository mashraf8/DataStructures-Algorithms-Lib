#ifndef STACK_HPP
#define STACK_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include "LinkedList.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class StackWithLinkedList
    {
    private:
        SinglyLinkedList<T>* _list;
    public:
        StackWithLinkedList()
        {
            _list = new SinglyLinkedList<T>();
        }
        ~StackWithLinkedList()
        {
            Clear();
        }
        void Push(T item)
        {
            _list->InsertFirst(item);
        }
        void Fill()
        {
            _list->Fill();
        }
        T Pop()
        {
            T ret = _list->SelectForward(0);
            _list->DeleteAtBeginning();
            return ret;
        }
        T Top()
        {
            return _list->SelectForward(0);
        }
        bool IsEmpty()
        {
            return _list->Isembty();
        }
        int Count()
        {
            return _list->Count();
        }
        void Swap(StackWithLinkedList& other)
        {

            StackWithLinkedList<T> re_stack = other;
            other = *this;
            *this = re_stack;
            StackWithLinkedList<T> del_stack;
            re_stack = del_stack;



        }
        void Swap(StackWithLinkedList*& other)
        {

            StackWithLinkedList<T>  re_stack = *other;
            *other = *this;
            *this = re_stack;
            StackWithLinkedList<T> del_stack;
            re_stack = del_stack;



        }
        void Clear()
        {
            _list->Clear();
        }
        void Display()
        {
            _list->DisplayForward();
        }
    };
}

#endif 