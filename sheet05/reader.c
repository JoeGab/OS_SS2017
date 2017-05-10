#include <sys/types.h>
#include <sys/select.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main() {
	char *dbFifo = "/tmp/db_fifo", *webFifo = "/tmp/web_fifo", *mwFifo = "/tmp/mw_fifo";

	fd_set readfds;
	char buf[MAX_BUF];
	
	int fdDb = open(dbFifo, O_RDONLY), fdWeb = open(webFifo, O_RDONLY), fdMw = open(mwFifo, O_RDONLY);
	
	while(7) {
		FD_ZERO(&readfds);			
		FD_SET(fdDb, &readfds);
		FD_SET(fdWeb, &readfds);
		FD_SET(fdMw, &readfds);
	
		select(fdMw+1, &readfds, NULL, NULL, NULL);

    	if (FD_ISSET(fdDb, &readfds))
    	    read(fdDb, buf, MAX_BUF);
    		printf("%s\n", buf);
    	if (FD_ISSET(fdWeb, &readfds))
    	    read(fdWeb, buf, MAX_BUF);
    		printf("%s\n", buf);
		if (FD_ISSET(fdMw, &readfds))
    	    read(fdMw, buf, MAX_BUF);
    		printf("%s\n", buf);
	}
	
    return 0;
}
