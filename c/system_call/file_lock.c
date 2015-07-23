#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	char *file = argv[1];
	struct flock lock;
	int fd;
	puts("opening file...");
	fd = open (file, O_WRONLY);
	puts("locking...");
	memset(&lock,0,sizeof(lock));
	lock.l_type = F_WRLCK;
	fcntl(fd, F_SETLKW, &lock);
	puts("locked: hit enter to unlock");
	getchar();
	puts("unlocking..");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLKW, &lock);
	close(fd);
	return 0;
}
