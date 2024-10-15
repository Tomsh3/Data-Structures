

# Data Structures Implementation in C

This project provides basic implementations of some common data structures in C, including Linked Lists, Hash Maps, and Min Heaps.

## Files

- **dataStructures.c**: This file contains the implementation of the data structures and their associated operations.
- **dataStructures.h**: This is the header file, containing the declarations of the structs and functions for linked lists, hash maps, and heaps.

## Data Structures

### 1. Linked List
A simple linked list implementation, where each node contains an integer value and a pointer to the next node.

**Key Functions**:
- `list* createList()`: Allocates and initializes an empty linked list.
- `int first(const list* myList)`: Returns the value of the first node in the list.
- `int last(const list* myList)`: Returns the value of the last node in the list.

### 2. Hash Map
A basic hash map that supports collision handling using chaining.

**Key Functions**:
- `hashMap* initialHash(int size)`: Initializes a hash map with a given size.
- **Collision Handling**: Handled using linked lists to store multiple key-value pairs in a single bucket.

### 3. Min Heap
A minimum heap implementation to store integers with dynamic memory management.

**Key Functions**:
- `heap* createHeap(int maxSize)`: Creates a new heap with a maximum size.
- The heap structure stores its elements in an array and maintains the min-heap property.

## Compilation

To compile the project, run the following command:

```bash
gcc dataStructures.c -o dataStructures -lm
```

The `-lm` flag is included in case any math library functions are required.

## Example Usage

You can include these data structures in any C program by including the header file:

```c
#include "dataStructures.h"
```

Then, you can initialize and use the data structures as needed. For example:

```c
list* myList = createList();
heap* myHeap = createHeap(10);
hashMap* myHashMap = initialHash(20);
```

## Memory Management

Each data structure uses dynamic memory allocation (`malloc`). Remember to free any allocated memory to avoid memory leaks.

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).

---

Feel free to modify this README to add more details or change the content depending on your project needs!