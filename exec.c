#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    pid_t pid = fork();
    if (pid == 0) {
        char *binaryPath = "/bin/ls";
        char *arg1 = "-lh";

        execl(binaryPath, binaryPath, arg1, NULL);
    }
    wait(NULL);
    
	pid_t pid2 = fork();
    if (pid2 == 0) {
        char *binary = "ls";
        char *arg1 = "-lh";

        execlp(binary, binary, arg1, NULL);
    }
    wait(NULL);
    
	pid_t pid3 = fork();
    if (pid3 == 0) {
        char* argv[] = {"/bin/ls", "-lh", NULL};
        
        execv(argv[0], argv);
    }
    printf("parent finished! waiting for children\n", pid);
    wait(NULL);
    
	return 0;
}
