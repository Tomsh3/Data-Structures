#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include "dataStructures.h"

/**********************************************************************************************************************
															Linked List
**********************************************************************************************************************/

/*****************************************************************
						Functions
*****************************************************************/
list* createList() {
	list* myList =(list*) malloc(sizeof(list)); 
	if (myList == NULL) {//memory allocation has failed
		printf("ERROR: Memory allocaiton has failed\n");
		exit(1);
	}
	return myList;
}

// Return the value of the first node
int first(const list* myList){
	return myList->head->val; 
}

int last(const list* myList) {
	if (myList->head == NULL)
		return -1;
	node* iter = myList->head;
	while (iter->next != NULL) {
		iter = iter->next;
	}
	return iter->val;
}

// Retrun a pointer to the element at place 'p'
node* retrive(const list* myList, int p) {
	if (myList->head == NULL)
		return NULL;
	node* iter;
	iter = myList->head;
	for (int i = 0; i < p; i++) {
		if (iter->next == NULL)
			return NULL;
		iter = iter->next;
	}
	return iter;
}

// Return the index of the element that holds value 'x'. If there isn't return '-1'
// counting starts from 0
int locate(const list* myList, int x) {
	if (myList == NULL)
		return -1;
	int idx = 0;
	node* iter = myList->head;
	while (iter->next != NULL) {
		if (iter->val = x)
			return idx;
		idx++;
		iter = iter->next;
	}
	return -1;
}

int empty(const list* myList) {
	if (myList == NULL)
		return 1;
	return 0;
}

node* createNode(int val) {
	node* newNode = (node*)malloc(sizeof(node));
	if(newNode==NULL){//memory allocation has failed
		printf("ERROR: Memory allocaiton has failed\n");
		exit(1);
	}
	newNode->val = val;
	return newNode;
}


// insert value 'x' into place 'p'. promote the rest of the list
// if p is to big append to the end
void insert(int x, int p, list* myList) {
	node* newNode = createNode(x);
	node* temp = myList->head;
	node* prev=temp;
	for (int i = 0; i < p; i++) {
		prev = temp;
		temp = temp->next;
		if (temp == NULL)
			break;
	}
	newNode->next = temp;
	prev->next = newNode;
}

void deleteNode(list* myList,int x) {
	node* iter = myList->head;
	node* prev=iter;
	node* temp;
	while (iter->next != NULL) {
		// Item has found
		if (iter->val == x) {
			if (iter == myList->head) { // want to delete the head of the list
				myList->head = myList->head->next;
				free(iter);
				break;
			}
			temp = iter->next;
			prev->next = temp;
			free(iter);
			break;
		}
		prev = iter;
		iter = iter->next;
	}
}

/**********************************************************************************************************************
															Stack
**********************************************************************************************************************/


/*****************************************************************
						Functions
*****************************************************************/
stack* createStack() {
	stack* myStack = (stack*)malloc(sizeof(stack));
	if (myStack == NULL) {//memory allocation has failed
		printf("ERROR: Memory allocaiton has failed\n");
		exit(1);
	}
	return myStack;
}

int stackEmpty(stack* myStack) {
	if (myStack == NULL) {
		return 1;
	}
	return 0;
}

int top(stack* myStack) {
	if (stackEmpty(myStack))
		return NULL;
	return myStack->head->val;
}

void push(int x, stack* myStack) {
	node* newNode = createNode(x);// same funciton from linked list
	newNode->next = myStack->head;
	myStack->head = newNode;
}

int pop(stack* myStack) {
	int res = myStack->head->val;
	node* temp = myStack->head;
	myStack->head = myStack->head->next;
	free(temp);
	return res;
}

/**********************************************************************************************************************
															Queue
**********************************************************************************************************************/

/*****************************************************************
						Functions
*****************************************************************/
void initialQueue(queue* q) {
	q->head = NULL;
	q->tail = NULL;
}

// The function return 'True' if suceeded or 'False' if else
int enqueue(queue* q, int val) {
	node* newNode =(node*) malloc(sizeof(node));
	if (newNode == NULL)//memory allocation has failed
		return 0;
	newNode->val = val;
	if (q->tail == NULL) {  //first element
		q->tail = newNode;
		q->head = newNode;
		return 1;
	}
	q->tail->next = newNode;
	return 1;
}

int dequeue(queue* q) {
	if (q->head != NULL) {
		node* temp = q->head;
		int res = q->head->val;
		q->head = q->head->next;
		free(temp);
		return res;
	}
	return -1;
}


/**********************************************************************************************************************
														Priority Queue (Min)
														Also use of Heap
														Parent is smaller or equal to his children
														parent of arr[i] will always be at p[i/2] (lower value)
														Think about tree but implement as an array
**********************************************************************************************************************/

/*****************************************************************
						Functions
*****************************************************************/
heap* createHeap(int maxSize) {
	if (maxSize < 1)
		return NULL;
	heap* myHeap = (heap*)malloc(sizeof(heap));
	if (myHeap == NULL) {//memory allocation has failed
		printf("ERROR: Memory allocaiton has failed\n");
		exit(1);
	}
	myHeap->arr = (int*)malloc(maxSize * sizeof(int));
	if (myHeap->arr == NULL) {//memory allocation has failed
		printf("ERROR: Memory allocaiton has failed\n");
		free(myHeap);
		exit(1);
	}
	myHeap->maxSize = maxSize;
	myHeap->size = 0;
	return myHeap;
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Insert new element to the most left place 
void insertHeap(heap* myHeap, int x) {
	if (myHeap->size == myHeap->maxSize) {
		printf("ERROR: The heap is full\n");
		printf("Overflow\n");
	}
	myHeap->size++;
	myHeap->arr[myHeap->size] = x;
	int cur = myHeap->size;
	while (cur > 1) {
		if (myHeap->arr[cur] < myHeap->arr[cur / 2]) {
			swap(&myHeap->arr[cur], &myHeap->arr[cur / 2]);
			cur = cur / 2;
		}
		break;
	}
}

//function for correcting the heap
void heapify(heap* myHeap, int i) {
	if (2 * i > myHeap->maxSize)//no children
		return;
	if (2 * i + 1 > myHeap->maxSize) {//only left child
		if (myHeap->arr[i] > myHeap->arr[2 * i]) {
			swap(&myHeap->arr[i], &myHeap->arr[2 * i]);
			return;
		}
	}
	else {
		int j = 0;
		if (myHeap->arr[2 * i] > myHeap->arr[2 * i + 1])
			j = 2 * i + 1;
		else
			j = 2 * i;
		if (myHeap->arr[i] > myHeap->arr[j]) {
			swap(&myHeap->arr[i], &myHeap->arr[j]);
			heapify(myHeap, j);
		}
		else
			return;
	}
}
int deleteMin(heap* myHeap) {
	if (myHeap == NULL)
		return NULL;
	int min = myHeap->arr[0];
	if (myHeap->size == 1) {
		myHeap->size--;
		return min;
	}
	myHeap->arr[0] = myHeap->size;
	myHeap->arr[myHeap->size] = NULL; // delete the element
	myHeap->size--;
	heapify(myHeap,1);
	return min;
}


/**********************************************************************************************************************
														Binary Search Tree (BST)
**********************************************************************************************************************/

/*****************************************************************
						Functions
*****************************************************************/
treeNode* createNodeBST(int x) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	if (newNode == NULL) {//memory allocation has failed
		printf("ERROR: Memory allocaiton has failed\n");
		exit(1);
	}
	newNode->val = x;
}

//boolean function that return true if 'x' is a member in the tree, or false else
int member(int x,  treeNode* root) {
	treeNode* pnode = root;
	while (pnode != NULL) {
		if (pnode->val == x) {
			return 1;
		}
		if (pnode->val < x) {
			pnode = pnode->right;
			continue;
		}
		pnode = pnode->left;
	}
	return 0;
}

//its not allowed to put duplicates inputs
void insertBST( treeNode* root, int x) {
	if (root == NULL)
		return;
	if (member(x, root))
		return;
	treeNode* iter = root;
	treeNode* newNode = createNodeBST(x);
	while (iter != NULL) {
		if (iter->val > x){
			iter = iter->left;
		continue;
		}
		iter = iter->right;
	}
	iter = newNode;
}

int maxValBST(const treeNode* root) {
	if (root == NULL)
		return;
	if (root->right != NULL)
		return maxValBST(root->right);
	else
		return root->val;
}

int minValBST(const treeNode* root) {
	if (root == NULL)
		return;
	if (root->left != NULL)
		return maxValBST(root->left);
	else
		return root->val;
}

//help function
// replace a with b and return b so we can delete it

void semiSwap(treeNode* a, treeNode* b) {
	a->val = b->val;
	free(b);
}

void deleteBST(treeNode* root, int x) {
	if (root == NULL)
		return;
	if (member(x, root)) {
		treeNode* temp;
		treeNode* iter = root;
		treeNode* prev;
		while (iter != NULL) {
			prev = iter;
			if (iter->val > x) {
				iter = iter->left;
			}
			if (iter->val < x)
				iter = iter->right;
			if (iter->val == x) {//item has found
				if (iter->left == NULL && iter->right == NULL) {//no children
					free(iter);
				}
				if (iter->left != NULL && iter->right == NULL) { //only 1 child
					if (iter == root) {//the element is in the root
						root = root->left;
						free(iter);
					}
					else {
						temp = iter;
						if (prev->left == iter) {
							prev->left = iter->left;
							free(iter);
						}
						else {
							prev->right = iter->left;
							free(iter);
						}
					}
				}
				if (iter->right != NULL && iter->left == NULL) { //only 1 child
					if (iter == root) {//the element is in the root
						root = root->right;
						free(iter);
					}
					else {
						temp = iter;
						if (prev->left == iter) {
							prev->left = iter->right;
							free(iter);
						}
						else {
							prev->right = iter->right;
							free(iter);
						}
					}
				}
				else {//iter has 2 children
					temp = iter;
					iter = iter->right;
					while (iter->left != NULL) {
						iter = iter->left;
					}
					semiSwap(iter->left, temp);
				}
			}
		}
	}
}

// return the minimal element that bigger than 'x'
int succesor(int x, treeNode* root) {
	treeNode* iter = root;
	if (!member(x, root)) {
		return NULL;
	}
	if (iter->right != NULL)
		return minValBST(iter->right);
	return x;//there isn't any element bigger than 'x'
}

//return the maximal element that smaller than 'x'
int predecessor(int x, treeNode* root) {
	treeNode* iter = root;
	if (!member(x, root)) {
		return NULL;
	}
	if (iter->left != NULL)
		return maxValBST(iter->left);
	return x;//there isn't any element smaller than 'x'
}

/**********  ways to walk over binary trees  *********/
// INORDER: first visiting the root after the left child and before the right child
// its not a must require to print the value. we can do what ever we want
// This order prints value from small to big
void inorder(const treeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("Node value: %d\n", &root->val);
		inorder(root->right);
	}
}

// PREORDER: visiting root,then left child, then right child
// its not a must require to print the value. we can do what ever we want
void preorder(const treeNode* root) {
	if (root != NULL) {
		printf("Node value: %d\n", &root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

// POSTORDER: visiting left child, then right child, then root
// its not a must require to print the value. we can do what ever we want
void postorder(const treeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("Node value: %d\n", &root->val);
	}
}

/**********************************************************************************************************************
														Hash Table
**********************************************************************************************************************/

/*****************************************************************
						Functions
*****************************************************************/
hashMap* initialHash(int size) {
	if (size == 0)
		return NULL;
	hashMap* myTable =(hashMap*) malloc(sizeof(hashMap));
	myTable->size = size;
	myTable->hashTable = (entries**)malloc(size * sizeof(entries*));
	for (int i = 0; i < size; i++) {
		myTable->hashTable[i] = NULL;
	}
	return myTable;
}

//return the relevant index at the hash map, can be recived more relevant parameters
/*int hashFunc(int key) {
	printf("This is a reminder - the hash function isn't defined yet.\n");
	printf("You need to go in to the file and edit it as you wish.\n");
	return 0;
}*/


