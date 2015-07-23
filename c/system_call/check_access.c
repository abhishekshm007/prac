#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(argc == 1){
		puts("usage: check_access <path to the file> \n");
		return EXIT_FAILURE;
	}
	char *file = argv[1];
	int rval;
	rval = access(argv[1], F_OK);
	if(rval == 0){
		printf("%s exists\n",file);
	}else{
		if(errno == ENOENT){
			printf("%s does not exixts\n",file);
		}else if(errno == EACCES){
			printf("directory is not accessible\n");
		}
	}
	rval = access(argv[1], R_OK);
	if(rval == 0){
		printf("%s is read permitted by current process\n",file);
	}else{
		if(errno == EACCES){
			printf("%s id not accessible to read\n",file);
		}
	}
	rval = access(argv[1], W_OK);
	if(rval == 0){
		printf("%s is write permissible by current process\n",file);
	}else{
		if(errno == EACCES){
			printf("%s is not accessible to write\n",file);
		}else if(errno == EROFS){
			printf("%s is read-only file system\n",file);
		}
	}
	rval = access(argv[1], X_OK);
	if(rval == 0){
		printf("%s is executable by current process\n",file);
	}else{
		if(errno == EACCES){
			printf("%s is not accessible for execution\n",file);
		}
	}
}
