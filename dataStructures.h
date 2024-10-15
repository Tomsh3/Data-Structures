#include <stdio.h>
#include <stdlib.h>
#ifndef dataStructures_H
/**********************************************************************************************************************
															Linked List
**********************************************************************************************************************/

/*****************************************************************
						Structs
*****************************************************************/

// Linked List node
typedef struct node {
	int val; // node value
	struct node* next;
	//struct node* prev; // option for addition
}node;

// Not a mandatory struct, only for make the list managment easier
typedef struct _list {
	node* head;
}list;
/*****************************************************************
						Functions declerations
*****************************************************************/
list* createList();

// Return the value of the first node
int first(const list* myList);

int last(const list* myList);

// Retrun apointer to the element at place 'p'
node* retrive(const list* myList, int p);

// Return the index of the element that holds value 'x'. If there isn't return '-1'
// counting starts from 0
int locate(const list* myList, int x);

int empty(const list* myList);

node* createNode(int val);

// insert value 'x' into place 'p'. promote the rest of the list
// if p is to big append to the end
void insert(int x, int p, list* myList);

void deleteNode(list* myList, int x);

/**********************************************************************************************************************
															Stack
**********************************************************************************************************************/

/*****************************************************************
						Structs
*****************************************************************/

// The same node as of linked list
// The elements point "downward"
typedef struct _stack {
	node* head;
}stack;

/*****************************************************************
						Functions declerations
*****************************************************************/
stack* createStack();

int stackEmpty(stack* myStack);

int top(stack* myStack);

void push(int x, stack* myStack);

int pop(stack* myStack);

/**********************************************************************************************************************
															Queue
**********************************************************************************************************************/
/*****************************************************************
						Structs
*****************************************************************/

// The same node as of linked list
// The elements point to the one behind him
typedef struct _queue {
	node* head;
	node* tail;
}queue;

/*****************************************************************
						Functions declerations
*****************************************************************/
void initialQueue(queue* q);

// The function return 'True' if suceeded or 'False' if else
int enqueue(queue* q, int val);

int dequeue(queue* q);

/**********************************************************************************************************************
														Priority Queue (Min)
														Also use of Heap
														Parent is smaller or equal to his children
														parent of arr[i] will always be at p[i/2] (lower value)
														Think about tree but implement as an array
**********************************************************************************************************************/
/*****************************************************************
						Structs
*****************************************************************/
typedef struct _heap {
	int* arr;
	int size;
	int maxSize;
}heap;

/*****************************************************************
						Functions decleration
*****************************************************************/

heap* createHeap(int maxSize);

void swap(int* a, int* b);

//Insert new element to the most left place 
void insertHeap(heap* myHeap, int x);

//function for correcting the heap
void heapify(heap* myHeap, int i);

int deleteMin(heap* myHeap);

/**********************************************************************************************************************
														Binary Search Tree (BST)
**********************************************************************************************************************/
/*****************************************************************
						Structs
*****************************************************************/
typedef struct treeNode {
	int val;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

/*****************************************************************
						Functions declerations
*****************************************************************/
treeNode* createNodeBST(int x);

//boolean function that return true if 'x' is a member in the tree, or false else
int member(int x, treeNode* root);

//its not allowed to put duplicates inputs
void insertBST(treeNode* root, int x);

int maxValBST(const treeNode* root);

int minValBST(const treeNode* root);

//help function
// replace a with b and return b so we can delete it
//check if this deep enough
void semiSwap(treeNode* a, treeNode* b);

void deleteBST(treeNode* root, int x);

// return the minimal element that bigger than 'x'
int succesor(int x, treeNode* root);

//return the maximal element that smaller than 'x'
int predecessor(int x, treeNode* root);

/**********  ways to walk over binary trees  *********/
// INORDER: first visiting the root after the left child and before the right child
// its not a must require to print the value. we can do what ever we want
// This order prints value from small to big
void inorder(const treeNode* root);

// PREORDER: visiting root,then left child, then right child
// its not a must require to print the value. we can do what ever we want
void preorder(const treeNode* root);

// POSTORDER: visiting left child, then right child, then root
// its not a must require to print the value. we can do what ever we want
void postorder(const treeNode* root);

/**********************************************************************************************************************
														Hash Table
**********************************************************************************************************************/
/*****************************************************************
						Structs
*****************************************************************/
typedef struct _entries {
	int key;
	int val;
	struct entries* next;//for collisions
}entries;

typedef struct _hashMap {
	entries** hashTable;
	int size;
}hashMap;

/*****************************************************************
						Functions declerations
*****************************************************************/
hashMap* initialHash(int size);

//return the relevant index at the hash map, can be recived more relevant parameters
int hashFunc(int key);
#endif // !dataStructures_H