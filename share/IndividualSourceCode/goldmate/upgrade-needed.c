#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        FILE *con = freopen("/dev/console", "w", stdout);

        if(con != NULL) {
                for(int i = 0; i < 3; i++) {
                        fprintf(con, "vulnerable firmware detected!\n");
                }
                for(int i = 0; i < 10; i++) {
                        fprintf(con, "UPGRADE NEEDED\n");
                }
                fprintf(con, "4 VULNERABILITIES FOUND\n");
                fprintf(con, "run UPGRADE to avoid vulnerabilities in firmware...\n");
                fclose(con);
        }

        return 0;
}