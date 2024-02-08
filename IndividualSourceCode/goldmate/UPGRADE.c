#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char pass[12];
    printf("Enter the password to run UPGRADE: \n");
    fgets(pass, 12, stdin);
    if(strcmp(pass, "RunUpgr4d3!")) {
        printf("Incorrect Password\n");
        printf("Check in filesystem (/etc) for password data...\n");
        return 0;
    } else {
        printf("UPGRADE RUNNING...\n");

        sleep(1);

        printf("Upgrade in progress...\n");
        printf("[##########...........................]\n");
        sleep(1);
        printf("[####################.................]\n");
        sleep(1);
        printf("[#####################################]\n");
        sleep(1);
        printf("Upgrade complete....\n");

        for(int i = 0; i < 8; i++) {
            printf("ERROR: vulnerability %d added!\n", i+5);
        }
        sleep(1);
        printf("Firmware now has 12 total vulnerabilities\n");
        printf("Must remove these vulnerabilities before continuing...\n");
    }

        return 0;
}