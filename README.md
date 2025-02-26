# **Data Structures & Algorithms Library**

### High-Performance Library with Efficient Memory Management for Developers

Welcome to the **Data Structures & Algorithms Library** a comprehensive and efficient library built entirely from scratch using **C++**. This library is specifically designed for developers who need customized, high-performance data structures and algorithms. It provides powerful tools to help programmers **solve complex problems efficiently** and serves as a valuable resource for **learning and assisting developers** in mastering data structures, algorithms.

## **Features**

- **Custom Data Structures:**
  - **Arrays** 
  - **Vectors**
  - **Heap** 
    - Max Heap 
    - Min Heap
  - **Linked Lists:**
    - Singly Linked List
    - Doubly Linked List
    - Circular Singly Linked List
  - **Stack** 
  - **Queue**
  - **Trees:**
    - Binary Search Tree (BST)
    - AVL Tree
    - Red-Black Tree
    - B-Tree and B+ Tree
  - **Hash Tables:**
    - HashTableWithLinkedList
    - HashTableWithBPlusTree
    - HashTableWithAnyDataStrc
  - **Graphs**

- **Efficient Algorithms:**
  - Quick Sort
  - Heap Sort
  - Binary Search

- **Generic Type Support:**  
  - All data structures and algorithms support generic types to ensure flexibility and reusability.

- **Memory Management:**
  - All memory allocation and deallocation are handled manually.
  - Optimized for high performance with efficient memory usage.

- **Custom Operation Support:**  
  - Each data structure supports a wide range of advanced operations.

## **Usage**

### **Compiler Requirements**
Make sure you are using a C++ compiler that supports **C++17** or higher. You can verify your compiler version using the following command: `g++ --version ` 

### **How to Use**
- Include the Header Files, You can include the .hpp files in your project by using: `#include "path/filename.hpp"`
- Write Your Code, After including the necessary header files, you can start writing your code. For example:

````cpp
#include <iostream>
#include "../include/LinkedList.hpp"

using namespace DataStrcture;
int main()
{
	SinglyLinkedList<int> lin;

	lin.Fill();

	lin.DisplayForward();

	std::cout << "The count is: " << "\n";
	std::cout << lin.Count() << "\n";

	std::cout << "Enter the value to search for: " << "\n";
	int search_val;
	std::cin >> search_val;
	std::cout << (lin.IsFound(search_val) ? "Value found." : "Value not found.") << "\n";

	return 0;

}
````
- Compile And Run The Program, Use the following command to compile your C++ code and generate an executable: `g++ my_code.cpp -o run_program`
## **Contributing**
If you are interested in contributing, please check out the **[CONTRIBUTING.md](CONTRIBUTING.md)** for detailed guidelines.

## **Contact**
If you have any questions, suggestions, or feedback, feel free to reach out to us at **Email:** [mohashraf.eng@gmail.com](mailto:mohashraf.eng@gmail.com)

## **License**
This project is licensed under the [MIT License](./LICENSE) © 2025 Mohammed Ashraf.


