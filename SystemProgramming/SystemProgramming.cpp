
#include <stdio.h>

#include <iostream>
#include "static dynamic linking/t.c"
#include "UnixLinux File System Tree Simulator/main.c"
//#include "tswitch function/t.c"
//#include "subreaper process/C3.4.c"


using namespace std;

int main()
{
	int taskNum;
	cout << "Enter Task's Number"<<endl;
	cin >> taskNum;
	switch (taskNum){
	case 1:
		mainTask1();
		break;
	case 2:
		mainTaks2();
		break;
	case 3:
		//mainTask3();
		break;
	case 4:
		//mainTask4();
		break;
	default:
		cout << "invalid number of task"<<endl;
		break;
	}

}

