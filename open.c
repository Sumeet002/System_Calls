#include <stdio.h>
#include <fcntl.h>  /*defines options flags*/
#include <sys/types.h> /*defines types used by sys/stat.h*/
#include <sys/stat.h>  /*defines S_IREAD and S_IWRITE */

static char message[] = "Hello World!";

int main(){

	int fd;
	char buffer[80];

	/* open data.txt for read/write access (O_RDWR)
	   create data.txt if it does not exist (O_CREAT)
	   return error if data already exists (O_EXCL)
	   permit read/write access to file (S_IWRITE | S_IREAD)
	*/
	fd = open("data.txt", O_RDWR | O_CREAT | O_EXCL,S_IREAD | S_IWRITE);
	//fd = open("data.txt", O_RDONLY | O_CREAT | O_EXCL , S_IREAD);
	//printf("fd value: %d\n",fd);
	if(fd != -1){
		printf("data.txt opened for read/write access\n");
		
		if(write(fd,message,sizeof(message)) == -1){
			printf("data.txt is readonly\n");
			close(fd);
			exit(0);
		}
                
	
		//printf("fd after write message %d\n",fd);
		int offset = lseek(fd,0L,0);    /*go back to the beginning of file*/
		//printf("fd After lseek: %d\n",fd);
		
		if(read(fd,buffer,sizeof(message))== sizeof(message))
			printf("\"%s\" was written to data.txt\n",buffer);
		else
			printf("error reading data.txt\n");
		close(fd);
	}
	else
		printf("data.txt already exists\n");
	exit(0);
}
