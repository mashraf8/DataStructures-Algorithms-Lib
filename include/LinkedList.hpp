#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class SinglyLinkedList
    {
    private:
        class Node
        {
        public:
            T _data;
            Node* _next;
            Node()
            {
                _data = T();
                _next = NULL;

            }
        };
    private:
        Node* _head;
        int _count;
    public:
        SinglyLinkedList()
        {
            _head = NULL;
            _count = 0;
        }
        ~SinglyLinkedList()
        {
            Clear();
        }
        bool Isembty()
        {
            return _head == NULL;

        }
        void InsertFirst(T new_item)
        {
            Node* new_node = new Node();
            new_node->_data = new_item;

            if (!Isembty())
            {
                new_node->_next = _head;
                _head = new_node;
            }
            else
            {
                _head = new Node();
                new_node->_next = NULL;
                _head = new_node;


            }
            _count++;
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
                InsertFirst(item);
            }
        }
        void InsertBefore(T item, T new_item)
        {

            Node* re_node = _head;
            Node* new_node = new Node();
            new_node->_data = new_item;
            if (Isembty())
            {
                cout << "The Linked List Is Empty \n";
                return;
            }
            else if (re_node->_data == item)
            {
                InsertFirst(new_item);
                return;
            }
            else
            {
                while (re_node->_next != NULL)
                {
                    if (re_node->_next->_data == item)
                    {
                        new_node->_next = re_node->_next;
                        re_node->_next = new_node;
                        _count++;
                        return;
                    }

                    re_node = re_node->_next;

                }
            }

            cout << "We Can't Find The Item" << "\n";
            return;

        }
        void Append(T new_item)
        {
            Node* re_node = _head;
            Node* new_node = new Node();
            new_node->_data = new_item;
            new_node->_next = NULL;


            if (Isembty())
            {
                InsertFirst(new_item);
                return;
            }
            else if (_count == 1)
            {
                _head->_next = new_node;
                _count++;
            }
            else
            {
                while (re_node->_next != NULL)
                {
                    if (re_node->_next->_next == NULL)
                    {
                        re_node->_next->_next = new_node;
                        _count++;
                        return;
                    }

                    re_node = re_node->_next;

                }
            }

        }
        void InsertByIndex(int index, T new_item)
        {

            if (index == 0)
            {
                InsertFirst(new_item);
                return;
            }
            else if (index == _count)
            {
                Append(new_item);
                return;
            }
            Node* select_node = SelectNode(index - 1);
            Node* new_node = new Node();
            new_node->_data = new_item;
            if (select_node == NULL)
            {
                return;
            }
            else
            {

                new_node->_next = select_node->_next;
                select_node->_next = new_node;
                _count++;
                return;

            }
        }
        void DeleteByValue(T item)
        {
            Node* re_node = _head;

            if (Isembty())
            {
                return;
            }
            else if (re_node->_data == item)
            {
                DeleteAtBeginning();
            }
            else
            {
                while (re_node->_next != NULL)
                {
                    if (re_node->_next->_data == item)
                    {
                        Node* del_node = re_node->_next;
                        re_node->_next = re_node->_next->_next;
                        delete del_node;
                        _count--;
                        return;
                    }

                    re_node = re_node->_next;

                }
                return;
            }
        }
        void DeleteAtBeginning()
        {
            if (_count == 0 || _count == 1)
            {
                _head = NULL;
                _count = 0;
                return;
            }
            Node* del_node = _head;
            _head = _head->_next;
            delete del_node;
            _count--;

        }
        void DeleteAtEnd()
        {
            if (_count == 0 || _count == 1)
            {
                _head = NULL;
                _count = 0;
                return;
            }
            Node* re_node = _head;
            while (re_node->_next->_next != NULL)
            {
                re_node = re_node->_next;
            }
            delete re_node->_next;
            re_node->_next = NULL;
            _count--;
        }
        void DeleteByIndex(int index)
        {
            if (index == 0)
            {
                DeleteAtBeginning();
                return;
            }
            else if (index + 1 == _count)
            {
                DeleteAtEnd();
                return;
            }
            Node* del_node = SelectNode(index);
            if (del_node == NULL)
            {
                return;
            }
            else
            {
                Node* select_node = SelectNode(index - 1);
                select_node->_next = del_node->_next;
                _count--;
                delete del_node;
            }
        }
        void Update(int index, T new_item)
        {

            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return;
            }
            select_node->_data = new_item;
        }
        void UpdateByValue(T old_item, T new_item)
        {
            Node* select_node = SelectNodeByValue(old_item);
            if (select_node == NULL)
            {
                return;
            }
            else
            {
                select_node->_data = new_item;
                return;
            }

        }
        T SelectForward(int index)
        {
            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return T();
            }
            else
            {
                return select_node->_data;
            }

        }
        T* SelectByValue(T item)
        {
            Node* select_node = SelectNodeByValue(item);
            if (select_node == NULL)
            {
                return NULL;
            }
            else
            {
                return &select_node->_data;
            }

        }
        T* SelectByIndex(int index)
        {
            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return NULL;
            }
            else
            {
                return &select_node->_data;
            }

        }
        int SelectIndexByValue(T item)
        {
            return SelectIndex(item);
        }
        void DisplayForward()
        {
            Node* re_node = _head;
            cout << "Display The Items: ";
            for (int i = 0; i < _count; i++)
            {
                cout << re_node->_data << "  ";
                re_node = re_node->_next;

            }
            cout << "\n";

        }
        int Count()
        {

            return _count;
        }
        bool IsFound(T key)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == key)
                {
                    return true;
                }

                re_node = re_node->_next;

            }

            return false;
        }
        void Clear()
        {
            if (Isembty())
            {
                return;
            }
            Node* before_node = _head;
            Node* next_node = _head->_next;
            for (int i = 0; i < _count - 1; i++)
            {
                delete before_node;
                before_node = next_node;
                next_node = next_node->_next;
            }
            delete before_node;
            delete next_node;
            _head = NULL;
            _count = 0;
        }

    private:
        Node* SelectNode(int index)
        {
            Node* re_node = _head;
            if (index >= _count || index < 0)
            {
                cout << "Index Is Not Valid\n";
                return NULL;
            }
            else
            {
                for (int i = 0; i < index; i++) {
                    re_node = re_node->_next;
                }
                return re_node;
            }
        }
        Node* SelectNodeByValue(T item)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == item)
                {
                    return re_node;
                }

                re_node = re_node->_next;

            }
            return NULL;

        }
        int SelectIndex(T item)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == item)
                {
                    return i;
                }

                re_node = re_node->_next;

            }
            return -1;
        }

    };

    template <typename T>
    class DoublyLinkedList
    {
    private:
        class Node
        {
        public:
            T _data;
            Node* _next;
            Node* _before;
            Node()
            {
                _data = T();
                _next = NULL;
                _before = NULL;

            }
        };
    private:
        Node* _head;
        Node* _lastnode;
        int _count;
    public:
        DoublyLinkedList()
        {
            _head = NULL;
            _lastnode = NULL;
            _count = 0;
        }
        ~DoublyLinkedList()
        {
            Clear();
        }
        bool Isembty()
        {
            return _head == NULL;

        }
        void InsertFirst(T new_item)
        {
            Node* new_node = new Node();
            new_node->_data = new_item;


            if (!Isembty())
            {
                _head->_before = new_node;
                new_node->_next = _head;
                new_node->_before = NULL;
                _head = new_node;
            }
            else
            {
                _head = new Node();
                new_node->_next = NULL;
                new_node->_before = NULL;
                _head = new_node;
                _lastnode = new_node;

            }
            _count++;
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
                InsertFirst(item);
            }
        }
        void InsertBefore(T item, T new_item)
        {

            Node* re_node = _head;
            Node* new_node = new Node();
            new_node->_data = new_item;
            if (Isembty())
            {
                cout << "The Linked List Is Empty \n";
                return;
            }
            else if (re_node->_data == item)
            {
                InsertFirst(new_item);
                return;
            }
            else
            {
                while (re_node->_next != NULL)
                {
                    if (re_node->_next->_data == item)
                    {
                        re_node->_next->_before = new_node;
                        new_node->_next = re_node->_next;
                        new_node->_before = re_node;
                        re_node->_next = new_node;
                        _count++;
                        return;
                    }

                    re_node = re_node->_next;

                }
            }

            cout << "We Can't Find The Item" << "\n";
            return;

        }
        void Append(T new_item)
        {
            Node* new_node = new Node();
            new_node->_data = new_item;
            new_node->_next = NULL;


            if (Isembty())
            {
                InsertFirst(new_item);
                return;
            }
            else if (_count == 1)
            {
                new_node->_before = _head;
                _head->_next = new_node;
                _lastnode = new_node;
                _count++;
            }
            else
            {
                new_node->_before = _lastnode;
                _lastnode->_next = new_node;
                _lastnode = new_node;
                _count++;
            }

        }
        void InsertByIndex(int index, T new_item)
        {

            if (index == 0)
            {
                InsertFirst(new_item);
                return;
            }
            else if (index == _count)
            {
                Append(new_item);
                return;
            }
            Node* select_node = SelectNode(index - 1);
            Node* new_node = new Node();
            new_node->_data = new_item;
            if (select_node == NULL)
            {
                return;
            }
            else
            {

                select_node->_next->_before = new_node;
                new_node->_next = select_node->_next;
                new_node->_before = select_node;
                select_node->_next = new_node;
                _count++;
                return;

            }
        }
        void DeleteByValue(T item)
        {
            Node* re_node = _head;
            Node* re_lastnode = _lastnode;

            if (Isembty())
            {
                return;
            }
            else if (re_node->_data == item)
            {
                DeleteAtBeginning();
            }
            else
            {
                while (re_node->_next != re_lastnode)
                {
                    if (re_node->_next->_data == item)
                    {
                        Node* del_node = re_node->_next;
                        re_node->_next->_next->_before = re_node;
                        re_node->_next = re_node->_next->_next;
                        delete del_node;
                        _count--;
                        return;
                    }

                    re_node = re_node->_next;

                }
                if (re_node->_next->_data == item)
                {
                    Node* del_node = re_node->_next;
                    re_node->_next = NULL;
                    _lastnode = re_node;
                    delete del_node;
                    _count--;
                    return;
                }
                return;
            }
        }
        void DeleteAtBeginning()
        {
            if (_count == 0 || _count == 1)
            {
                _head = NULL;
                _lastnode = NULL;
                _count = 0;
                return;
            }
            Node* del_node = _head;
            _head = _head->_next;
            _head->_before = NULL;
            delete del_node;
            _count--;


        }
        void DeleteAtEnd()
        {
            if (_count == 0 || _count == 1)
            {
                _head = NULL;
                _lastnode = NULL;
                _count = 0;
                return;
            }
            Node* del_node = _lastnode;
            _lastnode = _lastnode->_before;
            _lastnode->_next = NULL;
            delete del_node->_next;
            _count--;
        }
        void DeleteByIndex(int index)
        {
            if (index == 0)
            {
                DeleteAtBeginning();
                return;
            }
            else if (index + 1 == _count)
            {
                DeleteAtEnd();
                return;
            }
            Node* del_node = SelectNode(index);
            if (del_node == NULL)
            {
                return;
            }
            else
            {
                Node* select_node = SelectNode(index - 1);
                select_node->_next->_next->_before = select_node;
                select_node->_next = select_node->_next->_next;
                _count--;
                delete del_node;
            }
        }
        void Update(int index, T new_item)
        {

            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return;
            }
            select_node->_data = new_item;
        }
        void UpdateByValue(T old_item, T new_item)
        {
            Node* select_node = SelectNodeByValue(old_item);
            if (select_node == NULL)
            {
                return;
            }
            else
            {
                select_node->_data = new_item;
                return;
            }

        }
        T SelectForward(int index)
        {
            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return T();
            }
            else
            {
                return select_node->_data;
            }

        }
        T SelectBackward(int index)
        {

            Node* select_node = SelectNodeForSelectBackward(index);
            if (select_node == NULL)
            {
                return T();
            }
            else
            {
                return select_node->_data;
            }

        }
        T* SelectByValue(T item)
        {
            Node* select_node = SelectNodeByValue(item);
            if (select_node == NULL)
            {
                return NULL;
            }
            else
            {
                return &select_node->_data;
            }

        }
        T* SelectByIndex(int index)
        {
            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return NULL;
            }
            else
            {
                return &select_node->_data;
            }

        }
        int SelectIndexByValue(T item)
        {
            return SelectIndex(item);
        }
        void DisplayForward()
        {
            Node* re_node = _head;
            cout << "DisplayForward The Items: ";
            for (int i = 0; i < _count; i++)
            {
                cout << re_node->_data << "  ";
                re_node = re_node->_next;

            }
            cout << "\n";
        }
        void DisplayBackward()
        {
            Node* re_node = _lastnode;
            cout << "DisplayBackward The Items: ";
            for (int i = 0; i < _count; i++)
            {
                cout << re_node->_data << "  ";
                re_node = re_node->_before;

            }
            cout << "\n";

        }
        int Count()
        {
            return _count;
        }
        bool IsFound(T key)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == key)
                {
                    return true;
                }

                re_node = re_node->_next;

            }

            return false;
        }
        void Clear()
        {
            if (Isembty())
            {
                return;
            }
            Node* before_node = _head;
            Node* next_node = _head->_next;
            for (int i = 0; i < _count - 1; i++)
            {
                delete before_node;
                before_node = next_node;
                next_node = next_node->_next;
            }
            delete before_node;
            delete next_node;
            _head = NULL;
            _lastnode = NULL;
            _count = 0;

        }
    private:
        Node* SelectNode(int index)
        {
            Node* re_node = _head;
            if (index >= _count || index < 0)
            {
                cout << "Index Is Not Valid\n";
                return NULL;
            }
            else
            {
                for (int i = 0; i < index; i++) {
                    re_node = re_node->_next;
                }
                return re_node;
            }
        }
        Node* SelectNodeByValue(T item)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == item)
                {
                    return re_node;
                }

                re_node = re_node->_next;

            }
            return NULL;

        }
        int SelectIndex(T item)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == item)
                {
                    return i;
                }

                re_node = re_node->_next;

            }
            return -1;
        }
        Node* SelectNodeForSelectBackward(int index)
        {
            Node* re_node = _lastnode;
            if (index >= _count || index < 0)
            {
                cout << "Index Is Not Valid\n";
                return NULL;
            }
            else
            {
                for (int i = 0; i < index; i++) {
                    re_node = re_node->_before;
                }
                return re_node;
            }
        }



    };

    template <typename T>
    class CircularSinglyLinkedList
    {
    private:
        class Node
        {
        public:
            T _data;
            Node* _next;
            Node()
            {
                _data = T();
                _next = NULL;

            }
        };
    private:
        Node* _head;
        Node* _lastnode;
        int _count;

    public:
        CircularSinglyLinkedList()
        {
            _head = NULL;
            _lastnode = NULL;
            _count = 0;
        }
        ~CircularSinglyLinkedList()
        {
            Clear();
        }
        bool Isembty()
        {
            return _head == NULL;

        }
        void InsertFirst(T new_item)
        {
            Node* new_node = new Node();
            new_node->_data = new_item;

            if (!Isembty())
            {
                new_node->_next = _head;
                ConLatWithFiNode(new_node);
            }
            else
            {
                _head = new Node();
                new_node->_next = NULL;
                _head = new_node;
                _lastnode = new_node;


            }
            _count++;

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
                InsertFirst(item);
            }
        }
        void InsertBefore(T item, T new_item)
        {

            Node* re_node = _head;
            Node* re_lastnode = _lastnode;
            Node* new_node = new Node();
            new_node->_data = new_item;
            if (Isembty())
            {
                cout << "The Linked List Is Empty \n";
                return;
            }
            else if (re_node->_data == item)
            {
                InsertFirst(new_item);
                return;
            }
            else
            {
                while (re_node != re_lastnode)
                {
                    if (re_node->_next->_data == item)
                    {
                        new_node->_next = re_node->_next;
                        re_node->_next = new_node;
                        _count++;
                        return;
                    }

                    re_node = re_node->_next;

                }
            }

            cout << "We Can't Find The Item" << "\n";
            return;

        }
        void Append(T new_item)
        {
            Node* new_node = new Node();
            new_node->_data = new_item;
            new_node->_next = NULL;


            if (Isembty())
            {
                InsertFirst(new_item);
                return;
            }
            else if (_count == 1)
            {
                _head->_next = new_node;
                UpdateLastNode(new_node);
                _count++;
            }
            else
            {
                _lastnode->_next = new_node;
                UpdateLastNode(new_node);
                _count++;
            }

        }
        void InsertByIndex(int index, T new_item)
        {

            if (index == 0)
            {
                InsertFirst(new_item);
                return;
            }
            else if (index == _count)
            {
                Append(new_item);
                return;
            }
            Node* select_node = SelectNode(index - 1);
            Node* new_node = new Node();
            new_node->_data = new_item;
            if (select_node == NULL)
            {
                return;
            }
            else
            {

                new_node->_next = select_node->_next;
                select_node->_next = new_node;
                _count++;
                return;

            }
        }
        void DeleteByValue(T item)
        {
            Node* re_node = _head;
            Node* re_lastnode = _lastnode;

            if (Isembty())
            {
                return;
            }
            else if (re_node->_data == item)
            {
                DeleteAtBeginning();
            }
            else
            {
                while (re_node->_next != re_lastnode)
                {
                    if (re_node->_next->_data == item)
                    {
                        Node* del_node = re_node->_next;
                        re_node->_next = re_node->_next->_next;
                        delete del_node;
                        _count--;
                        return;
                    }

                    re_node = re_node->_next;

                }
                if (re_node->_next->_data == item)
                {
                    Node* del_node = re_node->_next;
                    re_node->_next = re_node->_next->_next;
                    UpdateLastNode(re_node);
                    delete del_node;
                    _count--;
                    return;
                }
                return;
            }
        }
        void DeleteAtBeginning()
        {
            if (_count == 0 || _count == 1)
            {
                _head = NULL;
                _lastnode = NULL;
                _count = 0;
                return;
            }
            Node* del_node = _head;
            ConLatWithFiNode(_head->_next);
            delete del_node;
            _count--;

        }
        void DeleteAtEnd()
        {
            if (_count == 0 || _count == 1)
            {
                _head = NULL;
                _lastnode = NULL;
                _count = 0;
                return;
            }
            Node* re_node = _head;
            while (re_node->_next != _lastnode)
            {
                re_node = re_node->_next;
            }
            Node* del_node = re_node->_next;
            UpdateLastNode(re_node);
            delete del_node;
            _count--;
        }
        void DeleteByIndex(int index)
        {
            if (index == 0)
            {
                DeleteAtBeginning();
                return;
            }
            else if (index + 1 == _count)
            {
                DeleteAtEnd();
                return;
            }
            Node* del_node = SelectNode(index);
            if (del_node == NULL)
            {
                return;
            }
            else
            {
                Node* select_node = SelectNode(index - 1);
                select_node->_next = del_node->_next;
                _count--;
                delete del_node;
            }
        }
        void Update(int index, T new_item)
        {

            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return;
            }
            select_node->_data = new_item;
        }
        void UpdateByValue(T old_item, T new_item)
        {
            Node* select_node = SelectNodeByValue(old_item);
            if (select_node == NULL)
            {
                return;
            }
            else
            {
                select_node->_data = new_item;
                return;
            }

        }
        T SelectForward(int index)
        {
            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return T();
            }
            else
            {
                return select_node->_data;
            }

        }
        T* SelectByValue(T item)
        {
            Node* select_node = SelectNodeByValue(item);
            if (select_node == NULL)
            {
                return NULL;
            }
            else
            {
                return &select_node->_data;
            }

        }
        T* SelectByIndex(int index)
        {
            Node* select_node = SelectNode(index);
            if (select_node == NULL)
            {
                return NULL;
            }
            else
            {
                return &select_node->_data;
            }

        }
        int SelectIndexByValue(T item)
        {
            return SelectIndex(item);
        }
        void DisplayForward()
        {
            Node* re_node = _head;
            cout << "Display The Items: ";
            for (int i = 0; i < _count; i++)
            {
                cout << re_node->_data << "  ";
                re_node = re_node->_next;
            }
            cout << "\n";


        }
        int Count()
        {
            return _count;
        }
        bool IsFound(T key)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == key)
                {
                    return true;
                }

                re_node = re_node->_next;

            }

            return false;
        }
        void Clear()
        {
            if (Isembty())
            {
                return;
            }
            Node* before_node = _head;
            Node* next_node = _head->_next;
            for (int i = 0; i < _count; i++)
            {
                delete before_node;
                before_node = next_node;
                next_node = next_node->_next;
            }
            _head = NULL;
            _lastnode = NULL;
            _count = 0;
        }

    private:
        void UpdateLastNode(Node* new_node)
        {
            _lastnode = new_node;
            _lastnode->_next = _head;
        }
        void ConLatWithFiNode(Node* new_node)
        {
            _head = new_node;
            _lastnode->_next = _head;
        }
        Node* SelectNode(int index)
        {
            Node* re_node = _head;
            if (index >= _count || index < 0)
            {
                cout << "Index Is Not Valid\n";
                return NULL;
            }
            else
            {
                for (int i = 0; i < index; i++) {
                    re_node = re_node->_next;
                }
                return re_node;
            }
        }
        Node* SelectNodeByValue(T item)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == item)
                {
                    return re_node;
                }

                re_node = re_node->_next;

            }
            return NULL;

        }
        int SelectIndex(T item)
        {
            Node* re_node = _head;

            for (int i = 0; i < _count; i++)
            {
                if (re_node->_data == item)
                {
                    return i;
                }

                re_node = re_node->_next;

            }
            return -1;
        }



    };
}


#endif