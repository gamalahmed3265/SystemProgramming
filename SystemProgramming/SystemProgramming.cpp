
#include <stdio.h>

#include <iostream>
#include "static dynamic linking/t.c"
#include "UnixLinux File System Tree Simulator/main.c"
#include "Labs/C. Cd and pwd commands/main.cpp"
#include "Labs/B. Processing Queries/main.cpp"
#include "Labs/E. Easy Scheduling/main.cpp"
//#include "tswitch function/t.c"
//#include "subreaper process/C3.4.c"


using namespace std;
void switchTasks() {
	int taskNum;
	cout << "Enter Task's Number" << endl;
	cin >> taskNum;
	switch (taskNum) {
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
		cout << "invalid number of task" << endl;
		break;
	}

}
int main(){
	//switchTasks();
	//cCdandPwdCommands();
	//bProcessingQueries();
	eEasyScheduling();

}

