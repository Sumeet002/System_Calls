#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int fd;

	fd = open("foo.txt",O_WRONLY | O_CREAT,S_IREAD | S_IWRITE);
	if(fd == -1){
		perror("foo.txt");
		exit(1);
	}
	close(1); /*close standard output*/
	dup(fd); /*fd will be duplicated into standard out slot*/
	close(fd); /*close the extra slot*/
	printf("Hello,world!\n"); /*should go to file foo.txt*/
	exit(0);  /*exit() will close all files*/

}
