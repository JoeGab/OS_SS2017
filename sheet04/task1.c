#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main () {
	int i;
	pid_t pid;

	for (i = 0; i < 9; i++) {
		pid = fork();
		if (pid == 0) {
			// child (finishes immediately)
			exit(0);
		} else if (pid > 0) {
			// parent (waits for them to finish)
			wait(NULL);
		} else {
			fprintf(stderr, "Error while forking\n");
			exit(1);
		}
	}
	return 0;
}
	


