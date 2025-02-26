#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include <cmath>  // For Sqrt And Pow
#include "Array.hpp"
#include "LinkedList.hpp"
#include "Trees.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class HashTableWithLinkedList
    {
    private:
        Array<DoublyLinkedList<T>>* arr;
    public:
        HashTableWithLinkedList(int init_size)
        {
            arr = new Array<DoublyLinkedList<T>>(init_size);

        }
        ~HashTableWithLinkedList()
        {
            Clear();
            delete arr;
        }
        void Insert(T item)
        {
            SelectLinkedList(HashFun(&item)).InsertFirst(item);
        }
        void Fill()
        {
            int no_item;
            T item;
            cout << "How many item\n";
            cin >> no_item;
            for (int i = 0; i < no_item; i++)
            {
                cout << "Enter Item of " << i + 1 << "\n";
                cin >> item;
                Insert(item);
            }
        }
        void Delete(T item)
        {
            SelectLinkedList(HashFun(&item)).DeleteByValue(item);
        }
        void Update(T old_item, T new_item)
        {
            DoublyLinkedList<T>* lin = &SelectLinkedList(HashFun(&old_item));
            if (lin->IsFound(old_item))
            {
                lin->DeleteByValue(old_item);
                Insert(new_item);
            }
        }
        bool SearchBool(T item)
        {
            return  SelectLinkedList(HashFun(&item)).IsFound(item);
        }
        T* SelectItem(T item)
        {

            T* item_sel = SelectLinkedList(HashFun(&item)).SelectByValue(item);
            if (item_sel == NULL)
            {
                return NULL;
            }
            else
            {
                return item_sel;
            }

        }
        DoublyLinkedList<T>& SelectLinked(T item)
        {
            return SelectLinkedList(HashFun(&item));
        }
        void Display()
        {
            PrintLoop();
        }
        double CalculateStandardDeviation()
        {
            DoublyLinkedList<T>* lin;
            int _size = arr->GetSize();
            double sum = 0;
            double mean = 0;

            for (int i = 0; i < _size; i++)
            {
                lin = &SelectLinkedList(i);
                mean += lin->Count();
            }
            mean /= _size;

            for (int i = 0; i < _size; i++)
            {
                lin = &SelectLinkedList(i);
                sum += pow(lin->Count() - mean, 2);
            }

            return sqrt(sum / _size);



        }
        void Clear()
        {
            ClearLoop();
        }
    private:
        DoublyLinkedList<T>& SelectLinkedList(int index)
        {
            return (*arr)[index];
        }
        int HashFun(T* item)
        {
            int num = ProcessBytes(item);
            return num % arr->GetSize();


        }
        int ProcessBytes(T* item)
        {

            uint8_t* data;
            uint32_t h1 = 0;
            int len;
            int nblocks;
            if constexpr (std::is_same_v<T, std::string>)
            {
                string str = *item;
                data = (uint8_t*)str.c_str();
                len = str.size();
                nblocks = len / 4;
            }
            else
            {
                data = (uint8_t*)item;
                len = sizeof(T);
                nblocks = len / 4;
            }

            if (len % 4 != 0)
            {
                for (int i = 4 - len % 4; i > 0; i--)
                {
                    data[(nblocks + 1) * 4 - i] = 0;

                }

                nblocks++;
            }


            for (int i = 0; i < nblocks; ++i)
            {
                uint32_t k1 = *((uint32_t*)(data + i * 4));
                k1 *= 1540483477;
                k1 ^= k1 >> 24;
                k1 *= 1540483477;
                h1 *= 1540483477;
                h1 ^= k1;
            }

            int ret = h1;
            if (ret < 0)
            {
                return ret *= -1;
            }

            return ret;
        }
        void PrintLoop()
        {
            int i = 0;
            DoublyLinkedList<T>* lin;
            for (i = 0; i < arr->GetSize(); i++)
            {
                lin = &SelectLinkedList(i);
                if (!lin->Isembty())
                {
                    int count = lin->Count();
                    cout << "LinkedList at index: " << i << " Is ";
                    for (int j = 0; j < count; j++)
                    {
                        cout << lin->SelectForward(j) << "->";

                    }
                    cout << "\n";
                }


            }

        }
        void ClearLoop()
        {
            int i = 0;
            DoublyLinkedList<T>* lin;
            for (i = 0; i < arr->GetSize(); i++)
            {
                lin = &SelectLinkedList(i);
                if (!lin->Isembty())
                {
                    lin->Clear();
                }


            }
        }

    };


    template <typename T>
    class HashTableWithBPlusTree
    {
    private:
        Array<BPlusTree<T>>* arr;
    public:
        HashTableWithBPlusTree(int init_size, int degree)
        {
            arr = new Array<BPlusTree<T>>(init_size);
            for (int i = 0; i < init_size; i++)
            {
                arr->Append(BPlusTree<T>(degree));
            }
        }
        ~HashTableWithBPlusTree()
        {
            Clear();
            delete arr;
        }
        void Insert(T item)
        {
            SelectBPlusTree(HashFun(&item)).Insert(item);
        }
        void Fill()
        {
            int no_item;
            T item;
            cout << "How many item\n";
            cin >> no_item;
            for (int i = 0; i < no_item; i++)
            {
                cout << "Enter Item of " << i + 1 << "\n";
                cin >> item;
                Insert(item);
            }
        }
        void Delete(T item)
        {
            SelectBPlusTree(HashFun(&item)).Delete(item);
        }
        void Update(T old_item, T new_item)
        {
            BPlusTree<T>* b_plus = &SelectBPlusTree(HashFun(&old_item));
            if (b_plus->SearchBool(old_item))
            {
                b_plus->Delete(old_item);
                Insert(new_item);
            }
        }
        bool SearchBool(T item)
        {
            return  SelectBPlusTree(HashFun(&item)).SearchBool(item);
        }
        T* SelectItem(T item)
        {

            T* item_sel = SelectBPlusTree(HashFun(&item)).SelectItem(item);
            if (item_sel == NULL)
            {
                return NULL;
            }
            else
            {
                return item_sel;
            }

        }
        BPlusTree<T>& SelectTree(T item)
        {
            return SelectBPlusTree(HashFun(&item));
        }
        void Display()
        {
            PrintLoop();
        }
        double CalculateStandardDeviation()
        {
            BPlusTree<T>* b_plus;
            int _size = arr->GetSize();
            double sum = 0;
            double mean = 0;

            for (int i = 0; i < _size; i++)
            {
                b_plus = &SelectBPlusTree(i);
                T minValue = b_plus->MinItem();
                T maxValue = b_plus->MaxItem();
                Vector<T> results(10);
                b_plus->Range(minValue, maxValue, results);
                mean += results.GetLenght();
            }
            mean /= _size;

            for (int i = 0; i < _size; i++)
            {
                b_plus = &SelectBPlusTree(i);
                T minValue = b_plus->MinItem();
                T maxValue = b_plus->MaxItem();
                Vector<T> results(10);
                b_plus->Range(minValue, maxValue, results);
                sum += pow(results.GetLenght() - mean, 2);
            }

            return sqrt(sum / _size);



        }
        void Clear()
        {
            ClearLoop();
        }
    private:
        BPlusTree<T>& SelectBPlusTree(int index)
        {
            return (*arr)[index];
        }
        int HashFun(T* item)
        {
            int num = ProcessBytes(item);
            return num % arr->GetSize();


        }
        int ProcessBytes(T* item)
        {

            uint8_t* data;
            uint32_t h1 = 0;
            int len;
            int nblocks;
            if constexpr (std::is_same_v<T, std::string>)
            {
                string str = *item;
                data = (uint8_t*)str.c_str();
                len = str.size();
                nblocks = len / 4;
            }
            else
            {
                data = (uint8_t*)item;
                len = sizeof(T);
                nblocks = len / 4;
            }

            if (len % 4 != 0)
            {
                for (int i = 4 - len % 4; i > 0; i--)
                {
                    data[(nblocks + 1) * 4 - i] = 0;

                }

                nblocks++;
            }


            for (int i = 0; i < nblocks; ++i)
            {
                uint32_t k1 = *((uint32_t*)(data + i * 4));
                k1 *= 1540483477;
                k1 ^= k1 >> 24;
                k1 *= 1540483477;
                h1 *= 1540483477;
                h1 ^= k1;
            }

            int ret = h1;
            if (ret < 0)
            {
                return ret *= -1;
            }

            return ret;
        }
        void PrintLoop()
        {
            int i = 0;
            BPlusTree<T>* b_plus;
            for (i = 0; i < arr->GetSize(); i++)
            {
                b_plus = &SelectBPlusTree(i);
                if (!b_plus->Isembty())
                {
                    cout << "BPlusTree at index: " << i << "\n";
                    b_plus->Display();
                    cout << "\n";
                }


            }

        }
        void ClearLoop()
        {
            int i = 0;
            BPlusTree<T>* b_plus;
            for (i = 0; i < arr->GetSize(); i++)
            {
                b_plus = &SelectBPlusTree(i);
                if (!b_plus->Isembty())
                {
                    b_plus->Clear();
                }


            }
        }

    };



    template <typename T, typename D>
    class HashTableWithAnyDataStrc
    {
    private:
        Array<T>* arr;
    public:
        HashTableWithAnyDataStrc(int init_size)
        {
            arr = new Array<T>(init_size);
        }
        ~HashTableWithAnyDataStrc()
        {
            delete arr;
        }
        T& SelectDataStrcByItem(D item)
        {
            return SelectDataStrc(HashFun(&item));
        }
        T& SelectDataStrcByIndex(int index)
        {
            return SelectDataStrc(index);
        }
    private:
        T& SelectDataStrc(int index)
        {
            return (*arr)[index];
        }
        int HashFun(D* item)
        {
            int num = ProcessBytes(item);
            return num % arr->GetSize();


        }
        int ProcessBytes(D* item)
        {

            uint8_t* data;
            uint32_t h1 = 0;
            int len;
            int nblocks;
            if constexpr (std::is_same_v<D, std::string>)
            {
                string str = *item;
                data = (uint8_t*)str.c_str();
                len = str.size();
                nblocks = len / 4;
            }
            else
            {
                data = (uint8_t*)item;
                len = sizeof(D);
                nblocks = len / 4;
            }

            if (len % 4 != 0)
            {
                for (int i = 4 - len % 4; i > 0; i--)
                {
                    data[(nblocks + 1) * 4 - i] = 0;

                }

                nblocks++;
            }


            for (int i = 0; i < nblocks; ++i)
            {
                uint32_t k1 = *((uint32_t*)(data + i * 4));
                k1 *= 1540483477;
                k1 ^= k1 >> 24;
                k1 *= 1540483477;
                h1 *= 1540483477;
                h1 ^= k1;
            }

            int ret = h1;
            if (ret < 0)
            {
                return ret *= -1;
            }

            return ret;
        }

    };
}
#endif 