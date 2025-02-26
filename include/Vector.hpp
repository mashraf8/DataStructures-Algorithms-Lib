#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include "Array.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class Vector
    {
    private:
        Array<T>* cal_array;
    public:
        Vector(int initsize)
        {
            cal_array = new Array<T>(initsize);
        }
        ~Vector()
        {
            delete cal_array;
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
                PushBack(newitem);
            }
        }
        void PushBack(T newitem)
        {
            CheckCapacity();
            cal_array->Append(newitem);

        }
        void Insert(T newitem, int index)
        {
            CheckCapacity();
            cal_array->Insert(newitem, index);
        }
        T PopBack()
        {
            T re_value = cal_array->SelectValue(GetLenght() - 1);
            cal_array->DeleteByIndex(GetLenght() - 1);
            return re_value;
        }
        void EraseByIndex(int index)
        {
            cal_array->DeleteByIndex(index);
        }
        void EraseByItem(T item)
        {
            cal_array->DeleteByItem(item);
        }
        void UpdateByIndex(T newitem, int index)
        {
            cal_array->UpdateByIndex(newitem, index);
        }
        void UpdateByItem(T newitem, T olditem)
        {
            cal_array->UpdateByItem(newitem, olditem);
        }
        T& operator[](int index)
        {
            return cal_array->SelectAddress(index);
        }
        T At(int index)
        {
            return cal_array->SelectValue(index);
        }
        T& AccessItem(int index)
        {
            return cal_array->SelectAddress(index);
        }
        int SelectIndex(T item)
        {
            return  cal_array->SelectIndex(item);
        }
        int GetLenght()
        {
            return cal_array->GetLenght();
        }
        int GetCapacity()
        {
            return cal_array->GetSize();
        }
        void Print()
        {
            cal_array->Display();
        }
        bool Isembty()
        {
            return cal_array->Isembty();

        }
        void Shrink()
        {
            cal_array->Shrink();
        }
        void Merge(Vector<T>& othervector)
        {
            cal_array->Merge(*othervector.cal_array);
        }
    private:
        void CheckCapacity()
        {
            if (GetLenght() == GetCapacity())
            {
                Reserve();
            }
        }
        void Reserve()
        {
            cal_array->Enlarge(GetCapacity() * 2);
        }


    };
}


#endif 