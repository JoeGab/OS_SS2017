#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main () {
	int i;
	pid_t pid;

	for (i = 0; i < 16; i++) {
		pid = fork();
		if (pid == 0) {
			// child
			printf("%d\n", getpid());
			exit(0);
		} else if (pid > 0) {
			// parent	
		} else {
			fprintf(stderr, "Error while forking\n");
			exit(1);
		}
	}
	printf("16 child processes has been created.\n");

	return 0;
}
