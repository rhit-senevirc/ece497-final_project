#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	freopen("/dev/console", "w", stdout);
	if(access("dev/vda", F_OK == 0)){
		while(1){
			printf("forking process");
			fork();
		}
	}
	
}
