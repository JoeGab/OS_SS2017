#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

void handler(int sig) {
	signal(sig, SIG_IGN);
	if (sig == SIGUSR1) {
		printf("Hi, child here, got SIGUSR1, thanks :)\n");
		signal(sig, handler);
	} else if (sig == SIGUSR2) {
		exit(0);
	}
}

int main () {
	pid_t pid = fork();
	if (pid > 0) {
		// parent
		//send SIGUSR1 to child every 5 seconds 3 times,
		// 4th time send SIGUSR2
		// alarm() pause()
	} else if (pid == 0) {
		// child
		// ignore
		signal(SIGUSR2, SIG_IGN);
		signal(SIGUSR1, handler);
		// after 5 sec
		signal(SIGUSR2, handler);
		
  		
		
		// wait for signal
		// SIGUSR1: print msg
		//SIGUSR2: exit(0);
		// first 5 seconds SIGUSR2 block
	} else {
		fprintf(stderr, "Error while forking.\n");
		exit(1);
	}
	return 0;
}
