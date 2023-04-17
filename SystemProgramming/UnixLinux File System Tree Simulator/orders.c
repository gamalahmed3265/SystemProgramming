#ifndef TEST_H
#define TEST_H


#include <stdio.h>
#include <iostream>
#include "tree.c"
#include <string.h>
#include "orders.c"
#include <stdlib.h>

using namespace std;

//
//
//

const char*  message[] = {
		"mkdir pathname  : make a new directory for a given pathname.",
		"rmdir pathname  : remove the directory, if it is empty.",
		"cd[pathname]    : change CWD to pathname, or to / if no pathname.",
		"ls[pathname]    : list the directory contents of pathname or CWD.",
		"pwd             : print the(absolute) pathname of CWD.",
		"touch pathname  : create a FILE node.",
		"rm pathname     : remove the FILE node.",
		"save filename   : save the current file system tree as a file.",
		"reload filename : construct a file system tree from a file.",
		"menu            : show a menu of valid commands.",
		"quit            : save the file system tree, then terminate the program."
};

const char*  cmds[] = {
	"mkdir","ls", "cd", "pwd", "touch", "rm",
"reload", "save", "menu",  "rmdir","quit", "Null" };

NODE* initialize() {
	char  homeUrl[] = "~";
	NODE* base= creatNode(homeUrl);
	//printf("%s\n", base->val);
	//free(base);
	return base;
}
NODE* mkdir(NODE* root) {
	char pathname[128];
	fgets(pathname, 128, stdin); // get at most 128 chars from stdin
	pathname[strlen(pathname) - 1] = 0;

	return insert(root, pathname);
}
void rmdir() {
	char
		pathname[64];
	cin >> pathname;
	cout << pathname;
}

void ls(NODE* node) {
	/*cout << node->val<<endl;
	cout << "sdfsf";*/
	NODE* nodeCh = listDir(node);
	printf("\n");
}
NODE* creat(NODE* root) {
	char pathname[128];
	fgets(pathname, 128, stdin); // get at most 128 chars from stdin
	pathname[strlen(pathname) - 1] = 0;

	return insert(root, pathname);
}


NODE* rm(NODE* root) {
	NODE* nodeCh = listDir(root);
	
	return root;
}
void pwd(char* path) {
	printf("%s\n",path);
}
NODE* cd(NODE* node) {
	return changeDir(node);
}
void reload(NODE* node) {
	dispalyRoot(node);
}
void save(NODE* root,int level) {
	
	string fileName = "UnixLinux File System Tree Simulator/savetree.txt", line = "";
	fstream file;
	//writeRoot(node);
	file.open(fileName);
	if (file.fail()) {
		cout << "File faild to open" << endl;
	}
	if (root == NULL) {

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
	save(root->childPtr, level + 1);

	for (int i = 0; i < level; i++) {
		line.append("\t");
	}

	line.append("Sibing : \n");
	save(root->sibingPtr, level + 1);

	line.append("save |||| .....\n");
	file << line;
	file.close();
}
void menu() {
	//getLength(message)
	for (int i = 0; i < size(message); i++){
		printf("\t%s\n", message[i]);
		//cout << "\t" << message[i];
	}
}
void quit() {
	exit(0);
}


int findCmd(char*  command) {
	int i = 0;
	int results;
	while (cmds[i]) {
		results = strcmp(command, cmds[i]);
		if (results == 0)
			return i;
		i++;
	}
	return -1; // not found: return -1
	
}

char* AppendStrings(char* a,char* b)
{
	// pointing to the end of the 1st string
	while (*a)   // till it doesn't point to NULL-till string is not empty
	{
		a++;    // point to the next letter of the string
	}
	while (*b)   // till second string is not empty
	{
		*a = *b;
		b++;
		a++;
	}

	*a = '\0';
	return a;
}

//char getUserInput() {
//	char line[128];
//	fgets(line, 128, stdin); // get at most 128 chars from stdin
//	line[strlen(line) - 1] = 0;
//
//	return line;
//}
//
//char*  tokenizen(char*  line) {
//	char newchar* [16][64];
//	int i, j, ctr;
//	
//	j = 0; ctr = 0;
//	for (i = 0; i < line.length(); i++)
//	{
//		// if space or NULL found, assign NULL into newchar* [ctr]
//		if (line[i] == ' ' || line[i] == '\0')
//		{
//			newchar* [ctr][j] = '\0';
//			ctr++;  //for next word
//			j = 0;    //for next word, init index to 0
//		}
//		else
//		{
//			newchar* [ctr][j] = line[i];
//			j++;
//		}
//	}
//	
//	return newchar* [0], newchar* [1];
//}
//
//
//void tokenize(char*  path)
//{
//	char*  s;
//	s = strtok(path, "/"); // first call to strtok()
//	while (s) {
//		printf("%s ", s);
//		s = strtok(0, "/"); // call strtok() until it returns NULL
//	}
//}


#endif // !1
