#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main (){
	int c,a=fork() ;
	if(a==-1){
		printf("error %s\n",strerror(errno));
		return -1;
	}
	if (a!=0){
		printf("I'm parent, my PID is %d, child PID is %d.\n",getpid(),a);
		printf("Waiting for child...\n");
		c=wait(&a);
		if(WIFEXITED(a))
			printf("Child with PID %d exited with code %d.\n",c,WEXITSTATUS(a));
		if(WIFSIGNALED(a))
			printf("Child with PID %d exited by signal %d.\n",c,WTERMSIG(a));
	}
	else{
		printf("I'm child, my PID is %d. My PPID is %d.\n",getpid(),getppid());
		printf("Sleeping for 10 seconds...\n");
		sleep(10);
		printf("Exiting.\n");
		return 10;
	}
	return 0;
}
