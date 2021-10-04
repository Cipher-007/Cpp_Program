// Write a program using pipe() and fork() in which parent process takes one string as
// input. The same is sent to the child using pipe1 and child will reverse it. After the
// reversing is complete, the child process will send it (reversed string) to parent process
// using pipe2. Subsequently, parent process will read the string and displays it.
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFERSIZE 1024

int main() {
    int pipefds1[2], pipefds2[2];

    char string1[BUFFERSIZE], string_rev[BUFFERSIZE], message[BUFFERSIZE];

    if (pipe(pipefds1) == -1) {
        printf("Unable to create pipe 1 \n");
        return 1;
    }

    if (pipe(pipefds2) == -1) {
        printf("Unable to create pipe 2 \n");
        return 1;
    }

    if (fork() != 0) {
        // close the unused end of the pipe
        close(pipefds1[0]);  
        close(pipefds2[1]);

        printf("Enter the string: ");
        fgets(string1, BUFFERSIZE, stdin);

        write(pipefds1[1], string1, sizeof(string1));
        read(pipefds2[0], message, sizeof(message));

        printf("Reversed: %s", message);
    } else {
        // close the unused end of the pipe
        close(pipefds1[1]);  
        close(pipefds2[0]);

        read(pipefds1[0], message, sizeof(message));

        int i = strlen(message) - 2; // omit the \n
        int j = 0;

        while (i >= 0) {
            string_rev[j] = message[i];
            i--;
            j++;
        }
        string_rev[j] = '\n';

        write(pipefds2[1], string_rev, sizeof(string_rev));
    }
    return 0;
}
