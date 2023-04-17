#include <stdio.h>

#include <iostream>
#include "orders.c"
using namespace std;

void mainTaks2()
{
	NODE* root,*cwd;
	int index;
	char
		command[16];
	char*
		valueOFCurrent;
		//root= initialize();
		
		char  homeUrl[] = "~";
		root = creatNode(homeUrl);
		
		cwd = root;
	while (1) {
		valueOFCurrent = cwd->val;
		printf("%s $ ", valueOFCurrent);
	
		cin >> command;

		index = findCmd(command);
		switch (index) {
			case 0: mkdir(root); break;
			case 1: ls(cwd); break;
			case 2:
				cwd = cd(root);
				valueOFCurrent = AppendStrings(valueOFCurrent, cwd->val);
				break;
			case 3: pwd(valueOFCurrent); break;
			case 4:  creat(root); break;
			case 5: rm(root); break;
			case 6: reload(root); break;
			case 7: save(root,0); break;
			case 8: menu(); break;
			case 9: rmdir(); break;
			case 10: quit(); break;
			default: printf("invalid command % s\n",command);//
		}
	}

}
