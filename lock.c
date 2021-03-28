#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>


int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Oops\n");
		return 1;
	}

	char * filename = argv[1];
	int fd = open(filename, O_WRONLY);
	printf("Trying to acquire lock ... \n");
	int r = lockf(fd, F_LOCK, 0);
	if (r != 0) {
		printf("Lock failed!\n");
		perror("main");
		return 2;
	}
	printf("Success! Dominating for 3 seconds from C now\n");
	sleep(3);
	close(fd);
}
