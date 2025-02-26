#ifndef TREES_HPP
#define TREES_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include <iomanip> //For Setw In Print Trees 
#include "Vector.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class BinarySearchTree
    {
    private:
        class Node
        {
        public:
            Node* _left;
            T _data;
            Node* _right;
            Node()
            {
                _left = NULL;
                _data = NULL;
                _right = NULL;
            }
            Node(T setroot)
            {
                _left = NULL;
                _data = setroot;
                _right = NULL;
            }
        };
    private:
        Node* first_root;
    public:
        BinarySearchTree()
        {
            first_root = NULL;
        }
        ~BinarySearchTree()
        {
            Clear();
        }
        void Insert(T new_item)
        {
            if (Isembty())
            {
                first_root = new Node(new_item);
            }
            else
            {
                first_root = LoopInsert(first_root, new_item);
            }
            return;
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
            if (Isembty())
            {
                return;
            }
            first_root = DeleteNode(first_root, item);

        }
        void Update(T old_item, T new_item)
        {
            Node* node = SearchNode(old_item);
            if (node == NULL)
            {
                return;
            }
            Delete(old_item);
            Insert(new_item);
            return;
        }
        void DisplayTree()
        {
            if (Isembty())
            {
                return;
            }
            PrintTree(first_root, 0, "Root:");
        }
        bool SearchBool(T item)
        {
            Node* isthere = LoopSearch(first_root, item);
            return isthere == NULL ? false : true;

        }
        Node* SearchNode(T item)
        {
            return LoopSearch(first_root, item);

        }
        bool Isembty()
        {
            return first_root == NULL;

        }
        T MinItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MinItemNode(first_root)->_data;
        }
        T MaxItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MaxItemNode(first_root)->_data;
        }
        int Height()
        {
            return LoopHeight(first_root);
        }
        bool IsRedBlackTreeBalance()
        {
            float ret = DifBetLR1(first_root);
            return ret > 2.0 || ret < 0.5 ? false : true;
        }
        bool IsAVLTreeBalance()
        {
            int ret = DifBetLR2(first_root);
            return ret > 1 || ret < -1 ? false : true;
        }
        void Clear()
        {
            if (Isembty())
            {
                return;
            }
            LoopClear(first_root);
            first_root = NULL;
        }
    private:
        Node* LoopInsert(Node* root, T new_item)
        {
            if (root == NULL)
            {
                return new Node(new_item);
            }
            if (new_item <= root->_data)
            {
                root->_left = LoopInsert(root->_left, new_item);
            }
            else if (new_item > root->_data)
            {
                root->_right = LoopInsert(root->_right, new_item);
            }
            return root;
        }
        Node* DeleteNode(Node* root, T item)
        {
            if (root == NULL)
            {
                return root;
            }

            if (item < root->_data)
            {
                root->_left = DeleteNode(root->_left, item);
            }
            else if (item > root->_data)
            {
                root->_right = DeleteNode(root->_right, item);
            }
            else
            {

                if (root->_left == NULL && root->_right == NULL)
                {
                    delete root;
                    return NULL;
                }

                else if (root->_left == NULL)
                {
                    Node* re_root = root->_right;
                    delete root;
                    return re_root;
                }
                else if (root->_right == NULL)
                {
                    Node* re_root = root->_left;
                    delete root;
                    return re_root;
                }

                else
                {
                    Node* re_root = MinItemNode(root->_right);
                    root->_data = re_root->_data;
                    root->_right = DeleteNode(root->_right, re_root->_data);
                }
            }
            return root;
        }
        float DifBetLR1(Node* node)
        {
            if (node == NULL)
            {
                return 1;
            }
            float leftHeight = LoopHeight(node->_left);
            float rightHeight = LoopHeight(node->_right);

            if (rightHeight == 0)
            {
                return leftHeight;
            }
            return leftHeight / rightHeight;
        }
        int DifBetLR2(Node* node)
        {
            if (node == NULL)
            {
                return 0;
            }
            return LoopHeight(node->_left) - LoopHeight(node->_right);
        }
        void PrintTree(Node* root, int space, string direction) {
            if (root == NULL)
            {
                return;
            }
            space += 5;
            PrintTree(root->_right, space, "R--");
            cout << setw(space) << direction << root->_data << "\n";
            PrintTree(root->_left, space, "L--");
        }
        Node* LoopSearch(Node* root, T item) {
            if (root == NULL || root->_data == item)
            {
                return root;
            }
            if (item <= root->_data)
            {
                return LoopSearch(root->_left, item);
            }
            return LoopSearch(root->_right, item);
        }
        Node* MinItemNode(Node* node)
        {
            Node* current = node;
            while (current != NULL && current->_left != NULL)
            {
                current = current->_left;
            }
            return current;
        }
        Node* MaxItemNode(Node* node)
        {
            Node* current = node;
            while (current != NULL && current->_right != NULL)
            {
                current = current->_right;
            }
            return current;
        }
        int LoopHeight(Node* node) {
            if (node == NULL)
            {
                return 0;
            }

            int leftheight = LoopHeight(node->_left);
            int rightheight = LoopHeight(node->_right);
            return 1 + max(leftheight, rightheight);
        }
        void LoopClear(Node* node) {
            if (node == NULL)
            {
                return;
            }

            LoopClear(node->_left);
            LoopClear(node->_right);

            delete node;
        }

    };

    template <typename T>
    class AVLTree
    {
    private:
        class Node
        {
        public:
            Node* _left;
            T _data;
            Node* _right;
            int _height;

            Node()
            {
                _left = NULL;
                _data = NULL;
                _right = NULL;
                _height = NULL;
            }
            Node(T setroot)
            {
                _left = NULL;
                _data = setroot;
                _right = NULL;
                _height = 1;
            }
        };
    private:
        Node* first_root;
    public:
        AVLTree()
        {
            first_root = NULL;
        }
        ~AVLTree()
        {
            Clear();
        }
        void Insert(T new_item)
        {
            if (Isembty())
            {
                first_root = new Node(new_item);
            }
            else
            {
                first_root = LoopInsert(first_root, new_item);
            }
            return;
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
            if (Isembty())
            {
                return;
            }
            first_root = DeleteNode(first_root, item);

        }
        void Update(T old_item, T new_item)
        {
            Node* node = SearchNode(old_item);
            if (node == NULL)
            {
                return;
            }
            Delete(old_item);
            Insert(new_item);
            return;
        }
        void DisplayTree()
        {
            if (Isembty())
            {
                return;
            }
            PrintTree(first_root, 0, "Root:");
        }
        bool SearchBool(T item)
        {
            Node* isthere = LoopSearch(first_root, item);
            return isthere == NULL ? false : true;

        }
        Node* SearchNode(T item)
        {
            return LoopSearch(first_root, item);
        }
        bool Isembty()
        {
            return first_root == NULL;

        }
        T MinItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MinItemNode(first_root)->_data;
        }
        T MaxItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MaxItemNode(first_root)->_data;
        }
        int Height()
        {
            return GetHeight(first_root);
        }
        void Clear()
        {
            if (Isembty())
            {
                return;
            }
            LoopClear(first_root);
            first_root = NULL;
        }
    private:
        Node* LoopInsert(Node* root, T new_item)
        {
            if (root == NULL)
            {
                return new Node(new_item);
            }
            if (new_item <= root->_data)
            {
                root->_left = LoopInsert(root->_left, new_item);
            }
            else if (new_item > root->_data)
            {
                root->_right = LoopInsert(root->_right, new_item);
            }
            UpdateHeight(root);
            return Balance(root);
        }
        Node* Balance(Node* root)
        {
            int balance = GetHeight(root->_left) - GetHeight(root->_right);

            if (balance > 1 && GetHeight(root->_left->_left) >= GetHeight(root->_left->_right))
            {
                return RotateRight(root);
            }
            if (balance > 1 && GetHeight(root->_left->_left) < GetHeight(root->_left->_right))
            {
                root->_left = RotateLeft(root->_left);
                return RotateRight(root);
            }
            if (balance < -1 && GetHeight(root->_right->_right) >= GetHeight(root->_right->_left))
            {
                return RotateLeft(root);
            }
            if (balance < -1 && GetHeight(root->_right->_right) < GetHeight(root->_right->_left))
            {
                root->_right = RotateRight(root->_right);
                return RotateLeft(root);
            }

            return root;
        }
        Node* RotateRight(Node* y)
        {
            Node* x = y->_left;
            Node* x_ri = x->_right;

            x->_right = y;
            y->_left = x_ri;

            UpdateHeight(y);
            UpdateHeight(x);
            return x;
        }
        Node* RotateLeft(Node* y)
        {
            Node* x = y->_right;
            Node* x_le = x->_left;

            x->_left = y;
            y->_right = x_le;

            UpdateHeight(y);
            UpdateHeight(x);
            return x;
        }
        Node* DeleteNode(Node* root, T item)
        {
            if (root == NULL)
            {
                return root;
            }

            if (item < root->_data)
            {
                root->_left = DeleteNode(root->_left, item);
            }
            else if (item > root->_data)
            {
                root->_right = DeleteNode(root->_right, item);
            }
            else
            {

                if (root->_left == NULL && root->_right == NULL)
                {
                    delete root;
                    return NULL;
                }

                else if (root->_left == NULL)
                {
                    Node* re_root = root->_right;
                    delete root;
                    return re_root;
                }
                else if (root->_right == NULL)
                {
                    Node* re_root = root->_left;
                    delete root;
                    return re_root;
                }

                else
                {
                    Node* re_root = MinItemNode(root->_right);
                    root->_data = re_root->_data;
                    root->_right = DeleteNode(root->_right, re_root->_data);
                }
            }
            UpdateHeight(root);
            return Balance(root);
        }
        void PrintTree(Node* root, int space, string direction) {
            if (root == NULL)
            {
                return;
            }
            space += 5;
            PrintTree(root->_right, space, "R--");
            cout << setw(space) << direction << root->_data << "\n";
            PrintTree(root->_left, space, "L--");
        }
        Node* LoopSearch(Node* root, T item) {
            if (root == NULL || root->_data == item)
            {
                return root;
            }
            if (item <= root->_data)
            {
                return LoopSearch(root->_left, item);
            }
            return LoopSearch(root->_right, item);
        }
        Node* MinItemNode(Node* node)
        {
            Node* current = node;
            while (current != NULL && current->_left != NULL)
            {
                current = current->_left;
            }
            return current;
        }
        Node* MaxItemNode(Node* node)
        {
            Node* current = node;
            while (current != NULL && current->_right != NULL)
            {
                current = current->_right;
            }
            return current;
        }
        int GetHeight(Node* node)
        {
            return node == NULL ? 0 : node->_height;
        }
        void UpdateHeight(Node* node)
        {
            if (node != NULL)
            {
                node->_height = 1 + max(GetHeight(node->_left), GetHeight(node->_right));
            }
        }
        void LoopClear(Node* node) {
            if (node == NULL)
            {
                return;
            }

            LoopClear(node->_left);
            LoopClear(node->_right);

            delete node;
        }

    };

    template <typename T>
    class RedBlackTree
    {
    private:
        class Node
        {
        public:
            Node* _left;
            T _data;
            Node* _right;
            int _height;
            Node()
            {
                _left = NULL;
                _data = NULL;
                _right = NULL;
                _height = NULL;
            }
            Node(T setroot)
            {
                _left = NULL;
                _data = setroot;
                _right = NULL;
                _height = 1;

            }
        };
    private:
        Node* first_root;
    public:
        RedBlackTree()
        {
            first_root = NULL;
        }
        ~RedBlackTree()
        {
            Clear();
        }
        void Insert(T new_item)
        {
            if (Isembty())
            {
                first_root = new Node(new_item);
            }
            else
            {
                first_root = LoopInsert(first_root, new_item);
            }
            return;
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
            if (Isembty())
            {
                return;
            }
            first_root = DeleteNode(first_root, item);

        }
        void Update(T old_item, T new_item)
        {
            Node* node = SearchNode(old_item);
            if (node == NULL)
            {
                return;
            }
            Delete(old_item);
            Insert(new_item);
            return;
        }
        void DisplayTree()
        {
            if (Isembty())
            {
                return;
            }
            PrintTree(first_root, 0, "Root:");
        }
        bool SearchBool(T item)
        {
            Node* isthere = LoopSearch(first_root, item);
            return isthere == NULL ? false : true;

        }
        Node* SearchNode(T item)
        {
            return LoopSearch(first_root, item);

        }
        bool Isembty()
        {
            return first_root == NULL;

        }
        T MinItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MinItemNode(first_root)->_data;
        }
        T MaxItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MaxItemNode(first_root)->_data;
        }
        int Height()
        {
            return GetHeight(first_root);
        }
        void Clear()
        {
            if (Isembty())
            {
                return;
            }
            LoopClear(first_root);
            first_root = NULL;
        }
    private:
        Node* LoopInsert(Node* root, T new_item)
        {
            if (root == NULL)
            {
                return new Node(new_item);
            }
            if (new_item <= root->_data)
            {
                root->_left = LoopInsert(root->_left, new_item);
            }
            else if (new_item > root->_data)
            {
                root->_right = LoopInsert(root->_right, new_item);
            }
            UpdateHeight(root);
            return Balance(root);
        }
        Node* Balance(Node* root)
        {
            float balance = 1;
            if (root)
            {
                float leftHeight = GetHeight(root->_left);
                float rightHeight = GetHeight(root->_right);

                if (rightHeight == 0)
                {
                    balance = leftHeight;
                }
                balance = leftHeight / rightHeight;
            }


            if (balance > 2.0 && GetHeight(root->_left->_left) >= GetHeight(root->_left->_right))
            {
                return RotateRight(root);
            }
            if (balance > 2.0 && GetHeight(root->_left->_left) < GetHeight(root->_left->_right))
            {
                root->_left = RotateLeft(root->_left);
                return RotateRight(root);
            }
            if (balance < 0.5 && GetHeight(root->_right->_right) >= GetHeight(root->_right->_left))
            {
                return RotateLeft(root);
            }
            if (balance < 0.5 && GetHeight(root->_right->_right) < GetHeight(root->_right->_left))
            {
                root->_right = RotateRight(root->_right);
                return RotateLeft(root);
            }
            return root;
        }
        Node* RotateRight(Node* y)
        {
            Node* x = y->_left;
            Node* x_ri = x->_right;

            x->_right = y;
            y->_left = x_ri;

            UpdateHeight(y);
            UpdateHeight(x);
            return x;
        }
        Node* RotateLeft(Node* y)
        {
            Node* x = y->_right;
            Node* x_le = x->_left;

            x->_left = y;
            y->_right = x_le;

            UpdateHeight(y);
            UpdateHeight(x);
            return x;
        }
        Node* DeleteNode(Node* root, T item)
        {
            if (root == NULL)
            {
                return root;
            }

            if (item < root->_data)
            {
                root->_left = DeleteNode(root->_left, item);
            }
            else if (item > root->_data)
            {
                root->_right = DeleteNode(root->_right, item);
            }
            else
            {

                if (root->_left == NULL && root->_right == NULL)
                {
                    delete root;
                    return NULL;
                }

                else if (root->_left == NULL)
                {
                    Node* re_root = root->_right;
                    delete root;
                    return re_root;
                }
                else if (root->_right == NULL)
                {
                    Node* re_root = root->_left;
                    delete root;
                    return re_root;
                }

                else
                {
                    Node* re_root = MinItemNode(root->_right);
                    root->_data = re_root->_data;
                    root->_right = DeleteNode(root->_right, re_root->_data);
                }
            }
            UpdateHeight(root);
            return Balance(root);
        }
        void PrintTree(Node* root, int space, string direction) {
            if (root == NULL)
            {
                return;
            }
            space += 5;
            PrintTree(root->_right, space, "R--");
            cout << setw(space) << direction << root->_data << "\n";
            PrintTree(root->_left, space, "L--");
        }
        Node* LoopSearch(Node* root, T item) {
            if (root == NULL || root->_data == item)
            {
                return root;
            }
            if (item <= root->_data)
            {
                return LoopSearch(root->_left, item);
            }
            return LoopSearch(root->_right, item);
        }
        Node* MinItemNode(Node* node)
        {
            Node* current = node;
            while (current != NULL && current->_left != NULL)
            {
                current = current->_left;
            }
            return current;
        }
        Node* MaxItemNode(Node* node)
        {
            Node* current = node;
            while (current != NULL && current->_right != NULL)
            {
                current = current->_right;
            }
            return current;
        }
        int GetHeight(Node* node)
        {
            return node == NULL ? 0 : node->_height;
        }
        void UpdateHeight(Node* node)
        {
            if (node != NULL)
            {
                node->_height = 1 + max(GetHeight(node->_left), GetHeight(node->_right));
            }
        }
        void LoopClear(Node* node) {
            if (node == NULL)
            {
                return;
            }

            LoopClear(node->_left);
            LoopClear(node->_right);

            delete node;
        }

    };


    template <typename T>
    class BTree
    {
    private:
        class BTreeNode
        {
        public:
            Vector<T> keys;
            Vector<BTreeNode*> children;
            bool isLeaf = true;
            int numKeys = 1;
            BTreeNode* parent;

            BTreeNode(int t) : keys(2 * t), children(2 * t + 1)
            {
                parent = NULL;
            }
        };

    private:
        BTreeNode* treeRoot;
        int t;

    public:
        BTree()
        {
            t = 2;
            treeRoot = NULL;
        }
        BTree(int degree)
        {
            if (degree < 2)
            {
                cout << "The Min Degree Is 2 \n";
                degree = 2;
            }
            t = degree;
            treeRoot = NULL;
        }
        ~BTree()
        {
            Clear();
        }
        void Insert(T value)
        {

            if (treeRoot == NULL)
            {
                treeRoot = new BTreeNode(t);

                treeRoot->keys[0] = value;
            }
            else
            {

                LoopInsert(treeRoot, value);

            }


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
            if (treeRoot != NULL)
            {
                LoopDelete(treeRoot, item);

            }
        }
        void Update(T old_item, T new_item)
        {
            BTreeNode* node = SearchNode(old_item);
            if (node == NULL)
            {
                return;
            }
            Delete(old_item);
            Insert(new_item);
            return;
        }
        bool SearchBool(T item)
        {
            return LoopSearch(treeRoot, item) != NULL;
        }
        BTreeNode* SearchNode(T item)
        {

            return LoopSearch(treeRoot, item);

        }
        T* SelectItem(T item)
        {

            BTreeNode* node = SearchNode(item);
            if (node == NULL)
            {
                return NULL;
            }
            for (int i = 0; i < node->numKeys; i++)
            {
                if (node->keys[i] == item)
                {
                    return &(node->keys[i]);
                }
            }

        }
        T MinItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MinItemNode(treeRoot);
        }
        T MaxItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MaxItemNode(treeRoot);
        }
        void Display()
        {
            if (!Isembty())
            {
                PrintTree(treeRoot, 0, "Root:");
            }
        }
        bool Isembty()
        {
            return treeRoot == NULL;

        }
        void Clear()
        {
            if (treeRoot != NULL)
            {
                ClearNode(treeRoot);
                treeRoot = NULL;
            }
        }

    private:

        BTreeNode* CutChild(BTreeNode* tree)
        {
            int split_index = ((2 * t - 1) / 2);
            BTreeNode* rightNode = new BTreeNode(t);
            rightNode->numKeys = tree->numKeys - split_index - 1;
            T risingNode = tree->keys[split_index];


            if (tree->parent != NULL)
            {
                BTreeNode* currentParent = tree->parent;
                int parentIndex = 0;
                for (parentIndex = 0; parentIndex < currentParent->numKeys + 1 && currentParent->children[parentIndex] != tree; parentIndex++);
                if (parentIndex == currentParent->numKeys + 1)
                {
                    throw std::runtime_error("Couldn't find which child we were!");
                }
                for (int i = currentParent->numKeys; i > parentIndex; i--)
                {
                    currentParent->children[i + 1] = currentParent->children[i];

                    currentParent->keys[i] = currentParent->keys[i - 1];
                }
                currentParent->numKeys++;
                currentParent->keys[parentIndex] = risingNode;




                currentParent->children[parentIndex + 1] = rightNode;
                rightNode->parent = currentParent;

            }




            int i = 0;
            for (i = split_index + 1; i < tree->numKeys + 1; i++)
            {
                rightNode->children[i - split_index - 1] = tree->children[i];
                if (tree->children[i] != NULL)
                {
                    rightNode->isLeaf = false;

                    if (tree->children[i] != NULL)
                    {
                        tree->children[i]->parent = rightNode;
                    }
                    tree->children[i] = NULL;

                }
            }
            for (i = split_index + 1; i < tree->numKeys; i++)
            {
                rightNode->keys[i - split_index - 1] = tree->keys[i];
            }
            BTreeNode* leftNode = tree;
            leftNode->numKeys = split_index;


            if (tree->parent != NULL)
            {
                return tree->parent;
            }
            else
            {
                this->treeRoot = new BTreeNode(t);

                treeRoot->keys[0] = risingNode;
                treeRoot->children[0] = leftNode;
                treeRoot->children[1] = rightNode;
                leftNode->parent = treeRoot;
                rightNode->parent = treeRoot;
                treeRoot->isLeaf = false;
                return treeRoot;
            }



        }
        void LoopInsert(BTreeNode* tree, T value)
        {

            if (tree->isLeaf)
            {

                tree->numKeys++;
                int insertIndex = tree->numKeys - 1;
                while (insertIndex > 0 && tree->keys[insertIndex - 1] > value)
                {
                    tree->keys[insertIndex] = tree->keys[insertIndex - 1];
                    insertIndex--;
                }
                tree->keys[insertIndex] = value;
                InsertRepair(tree);
            }
            else
            {
                int findIndex = 0;
                while (findIndex < tree->numKeys && tree->keys[findIndex] < value)
                {
                    findIndex++;
                }
                LoopInsert(tree->children[findIndex], value);
            }
        }
        void InsertRepair(BTreeNode* tree)
        {
            if (tree->numKeys <= 2 * t - 1)
            {
                return;
            }
            else if (tree->parent == NULL)
            {
                treeRoot = CutChild(tree);
                return;
            }
            else
            {
                BTreeNode* newNode = CutChild(tree);
                InsertRepair(newNode);
            }
        }
        void LoopDelete(BTreeNode* tree, T item)
        {
            if (tree != NULL)
            {
                int i;
                for (i = 0; i < tree->numKeys && tree->keys[i] < item; i++);
                if (i == tree->numKeys)
                {
                    if (!tree->isLeaf)
                    {

                        LoopDelete(tree->children[tree->numKeys], item);
                    }
                }
                else if (tree->keys[i] > item)
                {
                    if (!tree->isLeaf)
                    {
                        LoopDelete(tree->children[i], item);
                    }

                }
                else
                {

                    if (tree->isLeaf)
                    {
                        for (int j = i; j < tree->numKeys - 1; j++)
                        {
                            tree->keys[j] = tree->keys[j + 1];
                        }
                        tree->numKeys--;
                        RepairAfterDelete(tree);
                    }
                    else
                    {
                        BTreeNode* maxNode = tree->children[i];
                        while (!maxNode->isLeaf)
                        {

                            maxNode = maxNode->children[maxNode->numKeys];
                        }
                        tree->keys[i] = maxNode->keys[maxNode->numKeys - 1];
                        maxNode->numKeys--;
                        RepairAfterDelete(maxNode);
                    }
                }

            }
        }
        BTreeNode* Merge(BTreeNode* tree)
        {

            BTreeNode* parentNode = tree->parent;
            int parentIndex = 0;
            for (parentIndex = 0; parentNode->children[parentIndex] != tree; parentIndex++);
            BTreeNode* rightSib = parentNode->children[parentIndex + 1];


            tree->keys[tree->numKeys] = parentNode->keys[parentIndex];
            int fromParentIndex = tree->numKeys;



            for (int i = 0; i < rightSib->numKeys; i++)
            {
                tree->keys[tree->numKeys + 1 + i] = rightSib->keys[i];

            }
            if (!tree->isLeaf)
            {
                for (int i = 0; i <= rightSib->numKeys; i++)
                {
                    tree->children[tree->numKeys + 1 + i] = rightSib->children[i];
                    tree->children[tree->numKeys + 1 + i]->parent = tree;

                }
            }
            for (int i = parentIndex + 1; i < parentNode->numKeys; i++)
            {
                parentNode->children[i] = parentNode->children[i + 1];
                parentNode->keys[i - 1] = parentNode->keys[i];
            }
            parentNode->numKeys--;
            tree->numKeys = tree->numKeys + rightSib->numKeys + 1;
            delete rightSib;
            return tree;
        }
        BTreeNode* BorrowFromNext(BTreeNode* tree, int parentIndex)
        {
            BTreeNode* parentNode = tree->parent;

            BTreeNode* rightSib = parentNode->children[parentIndex + 1];
            tree->numKeys++;

            tree->keys[tree->numKeys - 1] = parentNode->keys[parentIndex];
            parentNode->keys[parentIndex] = rightSib->keys[0];


            if (!tree->isLeaf)
            {
                tree->children[tree->numKeys] = rightSib->children[0];
                tree->children[tree->numKeys]->parent = tree;


                for (int i = 1; i < rightSib->numKeys + 1; i++)
                {
                    rightSib->children[i - 1] = rightSib->children[i];

                }

            }
            for (int i = 1; i < rightSib->numKeys; i++)
            {
                rightSib->keys[i - 1] = rightSib->keys[i];
            }
            rightSib->numKeys--;
            return tree;

        }
        BTreeNode* BorrowFromBefore(BTreeNode* tree, int parentIndex)
        {
            BTreeNode* parentNode = tree->parent;
            tree->numKeys++;

            for (int i = tree->numKeys - 1; i > 0; i--)
            {
                tree->keys[i] = tree->keys[i - 1];
            }
            BTreeNode* leftSib = parentNode->children[parentIndex - 1];

            if (!tree->isLeaf)
            {
                for (int i = tree->numKeys; i > 0; i--)
                {
                    tree->children[i] = tree->children[i - 1];
                }
                tree->children[0] = leftSib->children[leftSib->numKeys];
                leftSib->children[leftSib->numKeys] = NULL;
                tree->children[0]->parent = tree;

            }

            tree->keys[0] = parentNode->keys[parentIndex - 1];
            parentNode->keys[parentIndex - 1] = leftSib->keys[leftSib->numKeys - 1];


            leftSib->numKeys--;
            return tree;
        }
        void RepairAfterDelete(BTreeNode* tree)
        {
            int min_keys = ((2 * t + 1) / 2) - 1;
            if (tree->numKeys < min_keys)
            {
                if (tree->parent == NULL)
                {
                    if (tree->numKeys == 0)
                    {
                        treeRoot = tree->children[0];
                        if (treeRoot != NULL)
                        {
                            treeRoot->parent = NULL;
                        }
                    }
                }
                else
                {
                    BTreeNode* parentNode = tree->parent;
                    int parentIndex = 0;
                    for (parentIndex = 0; parentNode->children[parentIndex] != tree; parentIndex++);
                    if (parentIndex > 0 && parentNode->children[parentIndex - 1]->numKeys > min_keys)
                    {
                        BorrowFromBefore(tree, parentIndex);

                    }
                    else if (parentIndex < parentNode->numKeys && parentNode->children[parentIndex + 1]->numKeys > min_keys)
                    {
                        BorrowFromNext(tree, parentIndex);

                    }
                    else if (parentIndex == 0)
                    {
                        BTreeNode* nextNode = Merge(tree);
                        RepairAfterDelete(nextNode->parent);
                    }
                    else
                    {
                        BTreeNode* nextNode = Merge(parentNode->children[parentIndex - 1]);
                        RepairAfterDelete(nextNode->parent);

                    }


                }
            }
        }
        BTreeNode* LoopSearch(BTreeNode* tree, T item)
        {
            while (tree != NULL)
            {
                int i = 0;
                while (i < tree->numKeys && tree->keys[i] < item)
                {
                    i++;
                }

                if (i < tree->numKeys && tree->keys[i] == item)
                {
                    return tree;
                }

                if (tree->isLeaf)
                {
                    return NULL;
                }
                tree = tree->children[i];
            }

            return NULL;
        }
        T MinItemNode(BTreeNode* tree)
        {
            BTreeNode* current = tree;
            while (!current->isLeaf)
            {
                current = current->children[0];
            }
            return current->keys[0];
        }
        T MaxItemNode(BTreeNode* tree)
        {

            BTreeNode* current = tree;
            while (!current->isLeaf)
            {
                current = current->children[current->numKeys];
            }
            return current->keys[current->numKeys - 1];
        }
        void PrintTree(BTreeNode* tree, int space, string direction)
        {
            if (tree == NULL)
            {
                return;
            }

            space += 5;
            for (int i = tree->numKeys - 1; i >= 0; --i)
            {
                if (!tree->isLeaf)
                {
                    PrintTree(tree->children[i + 1], space, "R--");
                }
                cout << setw(space) << direction << tree->keys[i] << "\n";
            }

            if (!tree->isLeaf)
            {
                PrintTree(tree->children[0], space, "L--");
            }
        }
        void ClearNode(BTreeNode* tree)
        {
            if (tree == NULL)
            {
                return;
            }
            for (int i = tree->numKeys - 1; i >= 0; --i)
            {
                if (!tree->isLeaf)
                {
                    ClearNode(tree->children[i + 1]);
                }
            }

            if (!tree->isLeaf)
            {
                ClearNode(tree->children[0]);
            }
            delete tree;
        }
    };


    template <typename T>
    class BPlusTree
    {
    private:
        class BTreeNode
        {
        public:
            Vector<T> keys;
            Vector<BTreeNode*> children;
            int numKeys = 1;
            bool isLeaf = true;
            BTreeNode* parent;
            BTreeNode* next;
            BTreeNode(int t) : keys(2 * t), children(2 * t + 1)
            {
                parent = NULL;
                next = NULL;
            }

        };
    private:
        BTreeNode* treeRoot;
        int t;
    public:
        BPlusTree()
        {
            t = 2;
            treeRoot = NULL;
        }
        BPlusTree(int degree)
        {
            if (degree < 2)
            {
                cout << "The Min Degree Is 2 \n";
                degree = 2;
            }
            t = degree;
            treeRoot = NULL;
        }
        ~BPlusTree()
        {
            Clear();
        }
        void Insert(T value)
        {


            if (treeRoot == NULL)
            {
                treeRoot = new BTreeNode(t);
                treeRoot->keys[0] = value;
            }
            else
            {
                LoopInsert(treeRoot, value);

            }


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
            if (!Isembty())
            {
                LoopDelete(treeRoot, item);
            }

        }
        void Update(T old_item, T new_item)
        {
            BTreeNode* node = SearchNode(old_item);
            if (node == NULL)
            {
                return;
            }
            Delete(old_item);
            Insert(new_item);
            return;
        }
        bool SearchBool(T item)
        {
            return LoopSearch(treeRoot, item) != NULL;
        }
        BTreeNode* SearchNode(T item)
        {

            return LoopSearch(treeRoot, item);

        }
        T* SelectItem(T item)
        {

            BTreeNode* node = SearchNode(item);
            if (node == NULL)
            {
                return NULL;
            }
            for (int i = 0; i < node->numKeys; i++)
            {
                if (node->keys[i] == item)
                {
                    return &(node->keys[i]);
                }
            }

        }
        void Range(T from, T to, Vector<T>& results)
        {
            if (Isembty())
            {
                return;
            }
            RangeQuery(treeRoot, from, to, results);
        }
        T MinItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MinItemNode(treeRoot);
        }
        T MaxItem()
        {
            if (Isembty())
            {
                return NULL;
            }
            return MaxItemNode(treeRoot);
        }
        void Display()
        {
            if (!Isembty())
            {
                PrintTree(treeRoot, 0, "Root:");
            }
        }
        bool Isembty()
        {
            return treeRoot == NULL;

        }
        void Clear()
        {
            if (treeRoot != NULL)
            {
                ClearNode(treeRoot);
                treeRoot = NULL;
            }
        }


    private:
        void LoopInsert(BTreeNode* tree, T value)
        {
            if (tree->isLeaf)
            {
                tree->numKeys++;
                int insertIndex = tree->numKeys - 1;

                while (insertIndex > 0 && tree->keys[insertIndex - 1] > value)
                {
                    tree->keys[insertIndex] = tree->keys[insertIndex - 1];
                    insertIndex--;
                }

                tree->keys[insertIndex] = value;

                InsertRepair(tree);

            }
            else
            {
                int findIndex = 0;
                while (findIndex < tree->numKeys && tree->keys[findIndex] < value)
                {
                    findIndex++;
                }

                LoopInsert(tree->children[findIndex], value);
            }
        }
        void InsertRepair(BTreeNode* tree)
        {
            if (tree->numKeys <= 2 * t - 1)
            {
                return;
            }

            if (tree->parent == NULL)
            {
                treeRoot = CutChild(tree);
                return;
            }

            BTreeNode* newNode = CutChild(tree);
            InsertRepair(newNode);
        }
        BTreeNode* CutChild(BTreeNode* tree)
        {

            int splitIndex = (2 * t) / 2;
            BTreeNode* rightNode = new BTreeNode(t);
            T risingNode = tree->keys[splitIndex];

            if (tree->parent != NULL)
            {
                BTreeNode* currentParent = tree->parent;
                int parentIndex = 0;

                while (parentIndex <= currentParent->numKeys && currentParent->children[parentIndex] != tree)
                {
                    parentIndex++;
                }

                if (parentIndex > currentParent->numKeys)
                {
                    throw std::runtime_error("Couldn't find which child we were!");
                }

                for (int i = currentParent->numKeys; i > parentIndex; i--)
                {
                    currentParent->children[i + 1] = currentParent->children[i];
                    currentParent->keys[i] = currentParent->keys[i - 1];
                }
                currentParent->keys[parentIndex] = risingNode;
                currentParent->children[parentIndex + 1] = rightNode;
                rightNode->parent = currentParent;
                currentParent->numKeys++;
            }

            int rightSplit = 0;
            if (tree->isLeaf)
            {
                rightNode->next = tree->next;
                tree->next = rightNode;
                rightSplit = splitIndex;
            }
            else
            {
                rightSplit = splitIndex + 1;
            }
            rightNode->numKeys = tree->numKeys - rightSplit;

            for (int i = rightSplit; i < tree->numKeys + 1; i++)
            {
                rightNode->children[i - rightSplit] = tree->children[i];
                if (tree->children[i] != NULL)
                {
                    rightNode->isLeaf = false;


                    if (tree->children[i] != NULL)
                    {
                        tree->children[i]->parent = rightNode;
                    }
                    tree->children[i] = NULL;

                }
            }
            for (int i = rightSplit; i < tree->numKeys; i++)
            {
                rightNode->keys[i - rightSplit] = tree->keys[i];
            }
            BTreeNode* leftNode = tree;
            leftNode->numKeys = splitIndex;

            tree->numKeys = splitIndex;

            if (tree->parent != NULL)
            {
                return tree->parent;
            }
            else
            {
                treeRoot = new BTreeNode(t);
                treeRoot->keys[0] = risingNode;
                treeRoot->children[0] = leftNode;
                treeRoot->children[1] = rightNode;
                leftNode->parent = treeRoot;
                rightNode->parent = treeRoot;
                treeRoot->isLeaf = false;
                return treeRoot;
            }
        }
        void LoopDelete(BTreeNode* tree, T item)
        {
            if (tree != NULL)
            {

                int i = 0;
                for (i = 0; i < tree->numKeys && tree->keys[i] < item; i++);
                if (i == tree->numKeys)
                {
                    if (!tree->isLeaf)
                    {

                        LoopDelete(tree->children[tree->numKeys], item);
                    }

                }
                else if (!tree->isLeaf && tree->keys[i] == item)
                {

                    LoopDelete(tree->children[i + 1], item);
                }
                else if (!tree->isLeaf)
                {

                    LoopDelete(tree->children[i], item);
                }
                else if (tree->isLeaf && tree->keys[i] == item)
                {

                    for (int j = i; j < tree->numKeys - 1; j++)
                    {
                        tree->keys[j] = tree->keys[j + 1];
                    }
                    tree->numKeys--;


                    if (i == 0 && tree->parent != NULL)
                    {
                        T* nextSmallest = NULL;
                        BTreeNode* parentNode = tree->parent;
                        int parentIndex = 0;
                        for (parentIndex = 0; parentNode->children[parentIndex] != tree; parentIndex++);
                        if (tree->numKeys == 0)
                        {
                            if (parentIndex == parentNode->numKeys)
                            {
                                nextSmallest = NULL;
                            }
                            else
                            {
                                nextSmallest = &parentNode->children[parentIndex + 1]->keys[0];
                            }
                        }
                        else
                        {
                            nextSmallest = &tree->keys[0];
                        }
                        while (parentNode != NULL)
                        {
                            if (parentIndex > 0 && parentNode->keys[parentIndex - 1] == item)
                            {

                                if (nextSmallest != NULL)
                                {
                                    parentNode->keys[parentIndex - 1] = *nextSmallest;

                                }






                            }
                            BTreeNode* grandParent = parentNode->parent;
                            for (parentIndex = 0; grandParent != NULL && grandParent->children[parentIndex] != parentNode; parentIndex++);
                            parentNode = grandParent;

                        }

                    }
                    RepairAfterDelete(tree);

                }


            }
        }
        void RepairAfterDelete(BTreeNode* tree)
        {
            int min_keys = (((2 * t) + 1) / 2) - 1;
            if (tree->numKeys < min_keys)
            {
                if (tree->parent == NULL)
                {
                    if (tree->numKeys == 0)
                    {
                        treeRoot = tree->children[0];
                        if (treeRoot != NULL)
                        {
                            treeRoot->parent = NULL;
                        }
                    }

                }
                else
                {
                    BTreeNode* parentNode = tree->parent;
                    int parentIndex = 0;
                    for (parentIndex = 0; parentNode->children[parentIndex] != tree; parentIndex++);


                    if (parentIndex > 0 && parentNode->children[parentIndex - 1]->numKeys > min_keys)
                    {
                        BorrowFromBefore(tree, parentIndex);

                    }
                    else if (parentIndex < parentNode->numKeys && parentNode->children[parentIndex + 1]->numKeys > min_keys)
                    {
                        BorrowFromNext(tree, parentIndex);

                    }
                    else if (parentIndex == 0)
                    {
                        BTreeNode* nextNode = Merge(tree);
                        RepairAfterDelete(nextNode->parent);
                    }
                    else
                    {
                        BTreeNode* nextNode = Merge(parentNode->children[parentIndex - 1]);
                        RepairAfterDelete(nextNode->parent);

                    }


                }
            }

        }
        BTreeNode* Merge(BTreeNode* tree)
        {

            BTreeNode* parentNode = tree->parent;
            int parentIndex = 0;
            for (parentIndex = 0; parentNode->children[parentIndex] != tree; parentIndex++);
            BTreeNode* rightSib = parentNode->children[parentIndex + 1];


            if (!tree->isLeaf)
            {
                tree->keys[tree->numKeys] = parentNode->keys[parentIndex];
            }



            int fromParentIndex = tree->numKeys;


            for (int i = 0; i < rightSib->numKeys; i++)
            {
                int insertIndex = tree->numKeys + 1 + i;
                if (tree->isLeaf)
                {
                    insertIndex -= 1;
                }
                tree->keys[insertIndex] = rightSib->keys[i];

            }
            if (!tree->isLeaf)
            {
                for (int i = 0; i <= rightSib->numKeys; i++)
                {

                    tree->children[tree->numKeys + 1 + i] = rightSib->children[i];
                    tree->children[tree->numKeys + 1 + i]->parent = tree;

                }
                tree->numKeys = tree->numKeys + rightSib->numKeys + 1;

            }
            else
            {
                tree->numKeys = tree->numKeys + rightSib->numKeys;

                tree->next = rightSib->next;

            }
            for (int i = parentIndex + 1; i < parentNode->numKeys; i++)
            {
                parentNode->children[i] = parentNode->children[i + 1];

                parentNode->keys[i - 1] = parentNode->keys[i];
            }
            parentNode->numKeys--;

            delete rightSib;
            return tree;
        }
        BTreeNode* BorrowFromNext(BTreeNode* tree, int parentIndex)
        {
            BTreeNode* parentNode = tree->parent;

            BTreeNode* rightSib = parentNode->children[parentIndex + 1];
            tree->numKeys++;

            if (tree->isLeaf)
            {

                tree->keys[tree->numKeys - 1] = rightSib->keys[0];
                parentNode->keys[parentIndex] = rightSib->keys[1];

            }
            else
            {

                tree->keys[tree->numKeys - 1] = parentNode->keys[parentIndex];
                parentNode->keys[parentIndex] = rightSib->keys[0];
            }


            if (!tree->isLeaf)
            {
                tree->children[tree->numKeys] = rightSib->children[0];
                tree->children[tree->numKeys]->parent = tree;


                for (int i = 1; i < rightSib->numKeys + 1; i++)
                {
                    rightSib->children[i - 1] = rightSib->children[i];

                }

            }
            for (int i = 1; i < rightSib->numKeys; i++)
            {
                rightSib->keys[i - 1] = rightSib->keys[i];
            }
            rightSib->numKeys--;


            return tree;

        }
        BTreeNode* BorrowFromBefore(BTreeNode* tree, int parentIndex)
        {
            BTreeNode* parentNode = tree->parent;
            tree->numKeys++;


            for (int i = tree->numKeys - 1; i > 0; i--)
            {
                tree->keys[i] = tree->keys[i - 1];
            }
            BTreeNode* leftSib = parentNode->children[parentIndex - 1];


            if (tree->isLeaf)
            {

                tree->keys[0] = leftSib->keys[leftSib->numKeys - 1];
                parentNode->keys[parentIndex - 1] = leftSib->keys[leftSib->numKeys - 1];
            }
            else
            {

                tree->keys[0] = parentNode->keys[parentIndex - 1];
                parentNode->keys[parentIndex - 1] = leftSib->keys[leftSib->numKeys - 1];
            }



            if (!tree->isLeaf)
            {
                for (int i = tree->numKeys; i > 0; i--)
                {
                    tree->children[i] = tree->children[i - 1];

                }
                tree->children[0] = leftSib->children[leftSib->numKeys];
                leftSib->children[leftSib->numKeys] = NULL;
                tree->children[0]->parent = tree;

            }

            leftSib->numKeys--;

            return tree;
        }
        BTreeNode* LoopSearch(BTreeNode* tree, T item)
        {
            if (tree == NULL)
            {
                return NULL;
            }

            int i = 0;
            while (!tree->isLeaf)
            {
                while (i < tree->numKeys && tree->keys[i] <= item)
                {
                    i++;
                }
                tree = tree->children[i];
                i = 0;
            }

            for (i = 0; i < tree->numKeys; i++)
            {
                if (tree->keys[i] == item)
                {
                    return tree;
                }
            }

            return NULL;
        }
        void RangeQuery(BTreeNode* tree, T low, T high, Vector<T>& results)
        {
            if (tree == NULL)
            {
                return;
            }

            if (tree->isLeaf)
            {
                int i = 0;
                while (i < tree->numKeys && tree->keys[i] < low)
                {
                    i++;
                }

                while (i < tree->numKeys && tree->keys[i] <= high)
                {
                    results.PushBack(tree->keys[i]);
                    i++;
                }
                if (tree->next != NULL)
                {
                    RangeQuery(tree->next, low, high, results);
                }
            }
            else
            {
                int i = 0;
                while (i < tree->numKeys && tree->keys[i] < low)
                {
                    i++;
                }

                for (int j = 0; j <= tree->numKeys; j++)
                {
                    if (tree->children[j] != NULL)
                    {
                        RangeQuery(tree->children[j], low, high, results);
                    }
                    break;
                }
            }
        }
        T MinItemNode(BTreeNode* tree)
        {
            BTreeNode* current = tree;
            while (!current->isLeaf)
            {
                current = current->children[0];
            }
            return current->keys[0];
        }
        T MaxItemNode(BTreeNode* tree)
        {

            BTreeNode* current = tree;
            while (!current->isLeaf)
            {
                current = current->children[current->numKeys];
            }
            return current->keys[current->numKeys - 1];
        }
        void PrintTree(BTreeNode* tree, int space, string direction)
        {
            if (tree == NULL)
            {
                return;
            }

            space += 5;
            for (int i = tree->numKeys - 1; i >= 0; --i)
            {
                if (!tree->isLeaf)
                {
                    PrintTree(tree->children[i + 1], space, "R--");
                }
                cout << setw(space) << direction << tree->keys[i] << "\n";
            }

            if (!tree->isLeaf)
            {
                PrintTree(tree->children[0], space, "L--");
            }
        }
        void ClearNode(BTreeNode* tree)
        {
            if (tree == NULL)
            {
                return;
            }
            for (int i = tree->numKeys - 1; i >= 0; --i)
            {
                if (!tree->isLeaf)
                {
                    ClearNode(tree->children[i + 1]);
                }
            }

            if (!tree->isLeaf)
            {
                ClearNode(tree->children[0]);
            }
            delete tree;
        }




    };
}
#endif