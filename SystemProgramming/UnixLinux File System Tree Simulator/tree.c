#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>

#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

typedef struct node {
	char*  val;
	struct node* childPtr;
	struct node* sibingPtr;
}NODE;

/*#define N 7
int nodeValue[N] = { 50,30,20,40,70,60,80 };*/

// create a new node

NODE* creatNode(char*  val)
{
	NODE* results = (NODE*)malloc(sizeof(NODE));
	 char spa[] = "/";
	if (results !=NULL) {
		results->childPtr = NULL;
		results->sibingPtr = NULL;
		/*printf("val is %s\n", val);
		printf("spa is %s\n", spa);*/
		//results->val = val;
		results->val = strcat(val, spa);
	}
	return results;
}

NODE* childInsert(NODE* node, char* val)
{
	if (node == NULL)
		return NULL;
	node->childPtr = childInsert(node->childPtr,val);
	
	return node;
}
NODE* changeDir(NODE* node){

	if (node == NULL)
		return NULL;
	//changeDir(node->val);
		cout << changeDir(node)->val;
	//printf();
	/*if (node->val == pathname)
		return node;
	else
		return changeDir(node->sibingPtr);*/

	
}

NODE* listDir(NODE* node)
{
	if (node == NULL)
		return NULL;
	node->sibingPtr = listDir(node->sibingPtr);
	printf("%s\t", node->val);
	//cout << "\t" << node->val;
}

NODE* sibingInsert(NODE* node)
{
	if (node == NULL)
		return NULL;
	node->sibingPtr = sibingInsert(node->sibingPtr);

	return node;
}

NODE* insert(NODE* parent,char*pathname) {
	NODE* newNode;
	newNode = creatNode(pathname);

	if (parent == NULL)
		return NULL;


	if (parent->sibingPtr == NULL) {
		parent->sibingPtr = newNode;
	}
	else {
		NODE* sibling = parent->sibingPtr;
		while (sibling->sibingPtr != NULL) {
			sibling = sibling->sibingPtr;
		}
		sibling->val = pathname;
		sibling->sibingPtr = newNode;
		
	}
	return parent;
}


void printTaps(int level) {
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
}

void dispalyRoot__level(NODE* root,int level) {
	if (root ==NULL) {
		printTaps(level);
		return;
	}
	printTaps(level);
	printf("value is: %s\n",root->val);

	/*printTaps(level);
	printf("Child : \n");
	dispalyRoot__level(root->childPtr, level+1);
*/
	printTaps(level);

	printf("Sibing : \n");
	dispalyRoot__level(root->sibingPtr, level+ 1);

	printf("done.....\n");
}

void dispalyRoot(NODE* root) {
	dispalyRoot__level(root, 0);
}


void dispalySibing(NODE* root) {
	if (root == NULL) {
		return;
	}
	printf("sibingPtr is: %s\n", root->val);
	dispalySibing(root->sibingPtr);
}


void dispalyPath(NODE* root) {
	if (root == NULL) {
		return;
	}
	printf("%s", root->val);
}









//void writeRoot__level(NODE* root, int level) {
	//string line = "";
	/*if (root == NULL) {
		
		return;
	}
	
	for (int i = 0; i < level; i++) {
		line.append("\t");
	}
	line.append(root->val);

	for (int i = 0; i < level; i++) {
		line.append("\t");
	}
	line.append("Child : \n");
	writeRoot__level(root->childPtr, level + 1);

	for (int i = 0; i < level; i++) {
		line.append("\t");
	}

	line.append("Sibing : \n");
	writeRoot__level(root->sibingPtr, level + 1);
	line.append("done.....\n");*/

	//return line.data();
	//}


//void writeRoot(NODE* root) {
	//writeRoot__level(root, 0);
//}
