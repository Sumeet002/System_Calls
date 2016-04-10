#include <stdio.h>

int main(){

	if(link("foo_old.txt","foo_new.txt")== -1){
		perror(" ");
		exit(1);  /*non-zero exit code on error*/
	}
	exit(0);
}
