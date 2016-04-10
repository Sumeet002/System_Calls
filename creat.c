#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	
	int fd;
	//fd= creat("data.txt",S_IREAD | S_IWRITE);
	fd = creat("data.txt",S_IRWXU);
	if(fd == -1)
		printf("Error in opening data.txt\n");
	else{
		printf("data.txt opened for read/write access\n");
	}

	close(fd);
	printf("data.txt closed");
	exit(0);
}

