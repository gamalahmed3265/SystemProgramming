#include <stdio.h>

#include <iostream>
#include "orders.c"
using namespace std;

void switchTask2()
{
	NODE* root,*cwd;
	int index;
	char
		//line[128],
		command[16],
		pathname[64];
	char*
		valueOFCurrent;
		//root= initialize();
		
		char  homeUrl[] = "~";
		root = creatNode(homeUrl);
		
		cwd = root;
	while (1) {
		valueOFCurrent = cwd->val;
		printf("%s $ ", valueOFCurrent);
	
		cin >> command >> pathname;

		index = findCmd(command);

		switch (index) {
			case 0: root->sibingPtr= mkdir(pathname); break;
			case 1: ls(root->sibingPtr); break;
			case 2:
				cwd->childPtr = cd(root, pathname);
				valueOFCurrent = AppendStrings(valueOFCurrent, cwd->childPtr->val);
				//cout<< <<endl;
				break;
			case 3: pwd(valueOFCurrent); break;
			case 4: root->sibingPtr= creat(pathname); break;
			case 5: rm(pathname); break;
			case 6: reload(root); break;
			case 7: save(root,0); break;
			case 8: menu(pathname); break;
			case 9: rmdir(pathname); break;
			case 10: quit(pathname); break;
			default: printf("invalid command % s\n",command);//
		}
	}

}
