#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include "Vector.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class MaxHeap
    {
    private:
        Vector<T>* _vector;
    public:
        MaxHeap(int initsize)
        {
            _vector = new Vector<T>(initsize);
        }
        ~MaxHeap()
        {
            delete _vector;
        }
        void Push(T item)
        {
            _vector->PushBack(item);
            CheckHeapUp(_vector->GetLenght() - 1);
        }
        void Fill()
        {
            int no_item;
            cout << "How many item\n";
            cin >> no_item;
            T newitem;
            for (int i = 0; i < no_item; i++)
            {
                cout << "Enter Item of " << i + 1 << "\n";
                cin >> newitem;
                Push(newitem);
            }
        }
        T PopRoot()
        {
            if (_vector->Isembty())
            {
                cout << "The Heap Is Empty\n";
            }

            T root = _vector->At(0);
            _vector->UpdateByIndex(_vector->At(_vector->GetLenght() - 1), 0);
            _vector->PopBack();
            CheckHeapDown(0);
            return root;
        }
        void EraseByItem(T item)
        {
            int index = SelectIndex(item);
            if (index == -1)
            {
                return;
            }
            _vector->EraseByItem(item);
            CheckHeapDown(index);
            CheckHeapUp(index);
        }
        void UpdateByItem(T newitem, T olditem)
        {
            int index = SelectIndex(olditem);
            if (index == -1)
            {
                return;
            }
            _vector->UpdateByItem(newitem, olditem);
            CheckHeapDown(index);
            CheckHeapUp(index);
        }
        T Root()
        {
            if (_vector->Isembty())
            {
                cout << "The Heap Is Empty\n";
            }
            return _vector->At(0);
        }
        T At(int index)
        {
            return _vector->At(index);
        }
        int SelectIndex(T item)
        {
            return _vector->SelectIndex(item);
        }
        bool Isempty()
        {
            return _vector->Isembty();
        }
        int GetLenght()
        {
            return _vector->GetLenght();
        }
        int GetCapacity()
        {
            return _vector->GetCapacity();
        }
        void Print()
        {
            _vector->Print();
        }
    private:
        void CheckHeapDown(int index)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int par = index;

            if (left < _vector->GetLenght() && _vector->At(left) > _vector->At(par)) {
                par = left;
            }

            if (right < _vector->GetLenght() && _vector->At(right) > _vector->At(par)) {
                par = right;
            }

            if (par != index)
            {
                Swap(_vector->AccessItem(index), _vector->AccessItem(par));
                CheckHeapDown(par);
            }
        }
        void CheckHeapUp(int index)
        {
            if (index == 0)
            {
                return;
            }
            int parent = (index - 1) / 2;

            if (_vector->At(index) > _vector->At(parent)) {
                Swap(_vector->AccessItem(index), _vector->AccessItem(parent));
                CheckHeapUp(parent);
            }
        }
        void Swap(T& x, T& y)
        {
            T re_item = x;
            x = y;
            y = re_item;
        }


    };

    template <typename T>
    class MinHeap
    {
    private:
        Vector<T>* _vector;
    public:
        MinHeap(int initsize)
        {
            _vector = new Vector<T>(initsize);
        }
        ~MinHeap()
        {
            delete _vector;
        }
        void Push(T item)
        {
            _vector->PushBack(item);
            CheckHeapUp(_vector->GetLenght() - 1);
        }
        void Fill()
        {
            int no_item;
            cout << "How many item\n";
            cin >> no_item;
            T newitem;
            for (int i = 0; i < no_item; i++)
            {
                cout << "Enter Item of " << i + 1 << "\n";
                cin >> newitem;
                Push(newitem);
            }
        }
        T PopRoot()
        {
            if (_vector->Isembty())
            {
                cout << "The Heap Is Empty\n";
            }

            T root = _vector->At(0);
            _vector->UpdateByIndex(_vector->At(_vector->GetLenght() - 1), 0);
            _vector->PopBack();
            CheckHeapDown(0);
            return root;
        }
        void EraseByItem(T item)
        {
            int index = SelectIndex(item);
            if (index == -1)
            {
                return;
            }
            _vector->EraseByItem(item);
            CheckHeapDown(index);
            CheckHeapUp(index);
        }
        void UpdateByItem(T newitem, T olditem)
        {
            int index = SelectIndex(olditem);
            if (index == -1)
            {
                return;
            }
            _vector->UpdateByItem(newitem, olditem);
            CheckHeapDown(index);
            CheckHeapUp(index);
        }
        T Root()
        {
            if (_vector->Isembty())
            {
                cout << "The Heap Is Empty\n";
            }
            return _vector->At(0);
        }
        T At(int index)
        {
            return _vector->At(index);
        }
        int SelectIndex(T item)
        {
            return _vector->SelectIndex(item);
        }
        bool Isempty()
        {
            return _vector->Isembty();
        }
        int GetLenght()
        {
            return _vector->GetLenght();
        }
        int GetCapacity()
        {
            return _vector->GetCapacity();
        }
        void Print()
        {
            _vector->Print();
        }
    private:
        void CheckHeapDown(int index)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int par = index;

            if (left < _vector->GetLenght() && _vector->At(left) < _vector->At(par)) {
                par = left;
            }

            if (right < _vector->GetLenght() && _vector->At(right) < _vector->At(par)) {
                par = right;
            }

            if (par != index)
            {
                Swap(_vector->AccessItem(index), _vector->AccessItem(par));
                CheckHeapDown(par);
            }
        }
        void CheckHeapUp(int index)
        {
            if (index == 0)
            {
                return;
            }
            int parent = (index - 1) / 2;

            if (_vector->At(index) < _vector->At(parent)) {
                Swap(_vector->AccessItem(index), _vector->AccessItem(parent));
                CheckHeapUp(parent);
            }
        }
        void Swap(T& x, T& y)
        {
            T re_item = x;
            x = y;
            y = re_item;
        }


    };
}

#endif 