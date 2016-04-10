#include <stdio.h>

int main(){

	if((unlink("foo_new.txt"))== -1){
			
		perror(" ");
		exit(1);
	}
	exit(0);
}
