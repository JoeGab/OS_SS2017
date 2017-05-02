#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void handler(int sig) {
	if (sig == SIGUSR1) {
		printf("Hi, child here, got SIGUSR1, thanks :)\n");
	} else if (sig == SIGUSR2) {
		exit(0);
	}
}

int main () {
	pid_t pid = fork();
	if (pid > 0) {
		// parent
		int ret, i;
		for (i = 0; i < 3; i++) {
			ret = kill(pid, SIGUSR1);
			if (ret != 0) {
				fprintf(stderr, "Error while sending SIGUSR1.\n");
			}
			sleep(5);
		}
		ret = kill(pid, SIGUSR2);
		if (ret != 0) {
			fprintf(stderr, "Error while sending SIGUSR2.\n");
		}
	} else if (pid == 0) {
		// child
		signal(SIGUSR2, SIG_IGN);
		signal(SIGUSR1, handler);
		sleep(5);
		signal(SIGUSR2, handler);
		pause();
	} else {
		fprintf(stderr, "Error while forking.\n");
		exit(1);
	}
	return 0;
}
