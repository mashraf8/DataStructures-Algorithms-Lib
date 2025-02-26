#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class Array
    {
    private:
        int _size;
        int _length;
        T* _array;
    public:
        Array(int initsize)
        {
            if (initsize < 1)
            {
                throw out_of_range("The Size Less Then One\n");
            }
            _array = new T[initsize];
            _size = initsize;
            _length = 0;
        }
        ~Array()
        {
            if (Isembty())
            {
                return;
            }
            delete[]_array;
            _length = 0;
            _size = 0;
        }
        void Fill()
        {
            int no_item;
            cout << "How many item\n";
            cin >> no_item;
            if (no_item + _length > _size)
            {
                cout << "The Size Of Array Smiller Than Num Of Item\n";
                return;
            }
            else
            {
                for (int i = 0; i < no_item; i++)
                {
                    cout << "Enter Item of " << i + 1 << "\n";
                    cin >> _array[_length];
                    _length++;
                }
            }

        }
        void Display()
        {
            for (int i = 0; i < _length; i++)
            {
                cout << _array[i] << "    ";
            }
            cout << "\n";
        }
        int GetSize()
        {
            return _size;
        }
        int GetLenght()
        {
            return _length;
        }
        T& operator[](int index)
        {
            return SelectAddress(index);
        }
        T SelectValue(int index)
        {

            if (index >= 0 && index < _length)
            {
                return _array[index];
            }
            throw out_of_range("The Index Is Not Valid");

        }
        T& SelectAddress(int index)
        {
            if (index >= 0 && index < _length)
            {
                return _array[index];
            }
            else if (index >= _length && index < _size)
            {
                for (int i = _length; i <= index; ++i)
                {
                    _array[i] = T();
                }
                _length = index + 1;
                return _array[index];
            }
            throw std::out_of_range("The Index Is Not Valid");
        }
        int SelectIndex(T item)
        {
            for (int i = 0; i < _length; i++)
            {
                if (_array[i] == item)
                {
                    return i;
                }
            }
            return -1;
        }
        void Append(T newitem)
        {
            if (_length == _size)
            {
                cout << "The Array Is Full" << "\n";
            }
            else
            {
                _array[_length] = newitem;
                _length++;
            }
        }
        void Insert(T newitem, int index)
        {
            int pointer = _length - 1;
            if (_length == _size)
            {
                cout << "The Array Is Full" << "\n";

            }
            else if (index >= 0 && index <= _length)
            {
                while (pointer >= index)
                {
                    _array[pointer + 1] = _array[pointer];
                    pointer--;
                }
                _array[index] = newitem;
                _length++;
            }
            else
            {
                throw out_of_range("The Index Is Not Valid");
            }
        }
        void DeleteByIndex(int index)
        {
            int pointer = index;
            if (index >= 0 && index < _length)
            {
                while (pointer < _length)
                {
                    _array[pointer] = _array[pointer + 1];
                    pointer++;
                }
                _length--;
            }
            else
            {
                throw out_of_range("The Index Is Not Valid");
            }
        }
        void DeleteByItem(T item)
        {
            int index = SelectIndex(item);
            if (index == -1)
            {
                return;
            }

            DeleteByIndex(index);
        }
        void UpdateByIndex(T newitem, int index)
        {
            if (index >= 0 && index < _length)
            {
                _array[index] = newitem;
            }
            else
            {
                throw out_of_range("The Index Is Not Valid");
            }
        }
        void UpdateByItem(T newitem, T olditem)
        {
            int index = SelectIndex(olditem);
            if (index == -1)
            {
                return;
            }
            UpdateByIndex(newitem, index);
        }
        void Enlarge(int newsize)
        {
            if (newsize <= _size)
            {
                cout << "New Size Must be Large Then Old Size\n";
                return;
            }
            else
            {
                T* rearray = _array;
                _array = new T[newsize];
                for (int i = 0; i < _length; i++)
                {
                    _array[i] = rearray[i];
                }
                _size = newsize;
                delete[]rearray;
            }

        }
        void Shrink()
        {
            if (_size > _length)
            {
                T* rearray = _array;
                _array = new T[_length];
                for (int i = 0; i < _length; i++)
                {
                    _array[i] = rearray[i];
                }
                _size = _length;
                delete[]rearray;
            }
            else
            {
                cout << "There Is Not Place For Shrink \n";
            }
        }
        void Merge(Array<T>& otherarray)
        {
            _size += otherarray.GetSize();
            T* rearray = _array;
            _array = new T[_size];
            for (int i = 0; i < _length; i++)
            {
                _array[i] = rearray[i];
            }
            delete[]rearray;
            int counter = 0;
            for (int i = _length; i < _length + otherarray.GetLenght(); i++)
            {
                _array[i] = otherarray._array[counter];
                counter++;
            }
            _length += otherarray.GetLenght();


        }
        bool Isembty()
        {
            return _length == 0;

        }

    };
}

#endif