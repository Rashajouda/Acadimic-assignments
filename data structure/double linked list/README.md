# Data Structures - Doubly Linked List Implementation

**Course:** Data Structures  
**Repository:** Academic Assignments  

## Description
This project contains a **C++ implementation of a Doubly Linked List**.  
It demonstrates key data structure concepts such as:

- Dynamic memory allocation  
- Bi-directional node traversal  
- Insertion and deletion at head, tail, or after a specific value  
- Searching for nodes  
- Reversing the linked list  
- Checking if the list is empty  
- Using classes and encapsulation for improved structure and maintainability  

The implementation includes two main classes: **Node** and **DoubleLinkedList**, following object-oriented programming principles.

---

## Classes

### 🔹 Node
Represents a single element in the doubly linked list and contains:
- `data` (integer value)
- `next` (pointer to next node)
- `prev` (pointer to previous node)
- Getter & Setter methods for all attributes

### 🔹 DoubleLinkedList
Represents the entire linked list and includes:
- `head` (pointer to the first node)
- Methods for:
  - Adding nodes (head, tail, after value)
  - Deleting nodes (head, tail, by value)
  - Searching for a value
  - Reversing the list  
  - Printing all nodes  
- Destructor to properly free allocated memory

---

## Features

- Add a node to **head**
- Add a node to **tail**
- Insert a node **after a specific value**
- Delete a node from:
  - **Head**
  - **Tail**
  - **Any node by value**
- Reverse the linked list
- Search for a value and return its position
- Print the entire list
- Check if the list is empty

---

## 🚀 How to Run Locally

# 1️⃣ Clone the repository
git clone https://github.com/Rashajouda/Acadimic-assignments.git

# 2️⃣ Navigate to the project directory
cd "data structure/single linked list/"


# 3️⃣ Compile the C++ program:
g++ linked_list.cpp -o linked_list


# 4️⃣ Run the program:

---

## 📄 License

This project was created **for educational purposes only**,  
as part of the **Data sturcture coursework**.  
It is not intended for commercial use.
