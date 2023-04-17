#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/prctl.h>
int mainTask4()
{
	int pid, r, status;
	printf("mark process %d as a subreaper\n", getpid());
	r = prctl(PR_SET_CHILD_SUBREAPER);
	pid = fork();
	if (pid) { // parent
		printf("subreaper %d child=%d\n", getpid(), pid);
		while (1) {
			pid = wait(&status); // wait for ZOMBIE children
			if (pid > 0)
				printf("subreaper %d waited a ZOMBIE=%d\n", getpid(), pid);
			else // no more children
				break;
		}
	}
	else { // child
		printf("child %d parent=%d\n", getpid(), (pid_t)getppid());
		pid = fork(); // child fork a grandchild
		if (pid) { // child
			printf("child=%d start: grandchild=%d\n", getpid(), pid);
			printf("child=%d EXIT : grandchild=%d\n", getpid(), pid);
		}
		else { // grandchild
			printf("grandchild=%d start: myparent=%d\n", getpid(),
				getppid());
			printf("grandchild=%d EXIT : myparent=%d\n", getpid(),
				getppid());
		}
	}
}