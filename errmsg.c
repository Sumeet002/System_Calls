/*errmsg
print all system error messages using perror()
1-34 err nos in asm-generic/erno-base.h
35-133 err nos in asm-generic/errno.h
*/


#include<stdio.h>
#include<errno.h>

int main(){
	
	int i;
	extern int errno,sys_nerr;

	for(i=0 ; i < sys_nerr; ++i){
		fprintf(stderr,"%3d",i);
		errno = i;
		perror(" ");
	}

	exit(0);

}
