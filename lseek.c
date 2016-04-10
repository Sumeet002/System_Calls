#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(){

	int fd;
	int position;
	
	fd= open("data.txt",O_RDONLY);
	if(fd != -1){
		//position = lseek(fd,0L,2); /*seek 0 bytes from end of file*/
		position = lseek(fd,0L,SEEK_END);
		//position = lseek(fd,0L,L_XTND);
		if(position != -1)
			printf("length of data.txt is %ld bytes.\n",position);
		else
			perror("lseek error");
	}
	else
		printf("can't open data.txt\n");
	close(fd);
}
