#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	FILE *con = freopen("/dev/console", "w", stdout);
	if(con != NULL){
		
		if(access("/dev/vda", F_OK) == 0){
			while(1){
				fprintf(con, "Flooding the main page.\n");
			}
		}
	
		else{
			fprintf(con, "Flooding the main page.\n");
		}
	}
}
