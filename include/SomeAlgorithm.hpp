#ifndef SOMEALGO_HPP
#define SOMEALGO_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include "Array.hpp"
#include "Vector.hpp"
#include "LinkedList.hpp"
#include "Heap.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class SomeAlgorForDataStrc
    {
    public:


        static void QuickSortArrayMin(Array<T>& arr)
        {
            QuickSortLoopMin(arr, 0, arr.GetLenght() - 1);
        }
        static void QuickSortArrayMax(Array<T>& arr)
        {
            QuickSortLoopMax(arr, 0, arr.GetLenght() - 1);
        }
        static void QuickSortVectorMin(Vector<T>& vic)
        {
            Array<T> arr(vic.GetLenght());
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                arr.Insert(vic.At(i), i);
            }
            QuickSortLoopMin(arr, 0, arr.GetLenght() - 1);
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                vic.UpdateByIndex(arr.SelectValue(i), i);
            }
        }
        static void QuickSortVectorMax(Vector<T>& vic)
        {
            Array<T> arr(vic.GetLenght());
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                arr.Insert(vic.At(i), i);
            }
            QuickSortLoopMax(arr, 0, arr.GetLenght() - 1);
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                vic.UpdateByIndex(arr.SelectValue(i), i);
            }
        }
        static void QuickSortLinkedListMin(SinglyLinkedList<T>& lin)
        {
            Array<T> arr(lin.Count());
            for (int i = 0; i < lin.Count(); i++)
            {
                arr.Insert(lin.SelectForward(i), i);
            }
            QuickSortLoopMin(arr, 0, arr.GetLenght() - 1);
            for (int i = 0; i < lin.Count(); i++)
            {
                lin.Update(i, arr.SelectValue(i));

            }
        }
        static void QuickSortLinkedListMax(SinglyLinkedList<T>& lin)
        {
            Array<T> arr(lin.Count());
            for (int i = 0; i < lin.Count(); i++)
            {
                arr.Insert(lin.SelectForward(i), i);
            }
            QuickSortLoopMax(arr, 0, arr.GetLenght() - 1);
            for (int i = 0; i < lin.Count(); i++)
            {
                lin.Update(i, arr.SelectValue(i));

            }
        }


        static void MaxHeapSortOfArray(Array<T>& arr)
        {
            MaxHeap<T> dd(arr.GetLenght());
            for (int i = 0; i < arr.GetLenght(); i++)
            {
                dd.Push(arr.SelectValue(i));
            }
            for (int i = 0; i < arr.GetLenght(); i++)
            {
                arr.UpdateByIndex(dd.PopRoot(), i);
            }

        }
        static void MinHeapSortOfArray(Array<T>& arr)
        {
            MinHeap<T> dd(arr.GetLenght());
            for (int i = 0; i < arr.GetLenght(); i++)
            {
                dd.Push(arr.SelectValue(i));
            }
            for (int i = 0; i < arr.GetLenght(); i++)
            {
                arr.UpdateByIndex(dd.PopRoot(), i);
            }

        }
        static void MaxHeapSortOfVector(Vector<T>& vic)
        {
            MaxHeap<T> dd(vic.GetLenght());
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                dd.Push(vic.At(i));
            }
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                vic.UpdateByIndex(dd.PopRoot(), i);
            }

        }
        static void MinHeapSortOfVector(Vector<T>& vic)
        {
            MinHeap<T> dd(vic.GetLenght());
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                dd.Push(vic.At(i));
            }
            for (int i = 0; i < vic.GetLenght(); i++)
            {
                vic.UpdateByIndex(dd.PopRoot(), i);
            }

        }

        static int BinarySearchOfMinArray(Array<T>& arr, T item)
        {
            int low = 0;
            int high = arr.GetLenght() - 1;
            int mid = (low + high) / 2;
            while (low <= high)
            {
                if (arr.SelectValue(mid) == item)
                {
                    return mid;
                }
                else if (arr.SelectValue(mid) > item)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
                mid = (low + high) / 2;
            }
            return -1;

        }
        static int BinarySearchOfMinVector(Vector<T>& vic, T item)
        {
            int low = 0;
            int high = vic.GetLenght() - 1;
            int mid = (low + high) / 2;
            while (low <= high)
            {
                if (vic.At(mid) == item)
                {
                    return mid;
                }
                else if (vic.At(mid) > item)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
                mid = (low + high) / 2;
            }
            return -1;

        }

    private:
        static void QuickSortLoopMin(Array<T>& arr, int low_index, int high_index)
        {
            if (low_index < high_index)
            {
                int piv_index = SortListMin(arr, low_index, high_index);
                QuickSortLoopMin(arr, low_index, piv_index - 1);
                QuickSortLoopMin(arr, piv_index + 1, high_index);
            }
        }
        static void QuickSortLoopMax(Array<T>& arr, int low_index, int high_index)
        {
            if (low_index < high_index)
            {
                int piv_index = SortListMax(arr, low_index, high_index);
                QuickSortLoopMax(arr, low_index, piv_index - 1);
                QuickSortLoopMax(arr, piv_index + 1, high_index);
            }
        }
        static int SortListMin(Array<T>& arr, int low_index, int high_index)
        {
            int piv = arr.SelectValue(high_index);
            int i = low_index - 1;

            for (int j = low_index; j < high_index; ++j)
            {
                if (arr.SelectValue(j) <= piv)
                {
                    ++i;
                    Swap(arr.SelectAddress(i), arr.SelectAddress(j));
                }
            }

            Swap(arr.SelectAddress(i + 1), arr.SelectAddress(high_index));
            return i + 1;
        }
        static int SortListMax(Array<T>& arr, int low_index, int high_index)
        {
            int piv = arr.SelectValue(high_index);
            int i = low_index - 1;

            for (int j = low_index; j < high_index; ++j)
            {
                if (arr.SelectValue(j) >= piv)
                {
                    ++i;
                    Swap(arr.SelectAddress(i), arr.SelectAddress(j));
                }
            }

            Swap(arr.SelectAddress(i + 1), arr.SelectAddress(high_index));
            return i + 1;
        }
        static void Swap(T& x, T& y)
        {
            T re_item = x;
            x = y;
            y = re_item;
        }

    };
}

#endif