#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    int fd, count = 0, randomTime;
    char *fifo = "/tmp/web_fifo", *text = "";

    if (0 != mkfifo(fifo, 0666)) {
    	unlink(fifo);
    	return -1;
    }
    
    srand(time(NULL));
    
    while(7) {
    	randomTime = rand() % 6 + 2;
    	sleep(randomTime);
    	fd = open(fifo, O_WRONLY);
    	sprintf(text, "[database] message %d", ++count); 
    	write(fd, text, sizeof(text));
    	close(fd);
    }
    
    // dead code
    unlink(fifo);
    return 0;
}
