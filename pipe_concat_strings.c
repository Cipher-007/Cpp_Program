// Write a program using pipe() and fork() in which parent process takes string1 as input.
// The same is provided to the child process using pipe1. Now, child process will take
// string2 as input and read string1 from pipe1. Then, child will concatenate string1 with
// string2. After the concatenation is complete, the child process will send it to the parent
// process using pipe2. Subsequently, parent will read the concatenated string and
// displays it.
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFERSIZE 1024

int main() {
    int pipefds1[2], pipefds2[2];

    char string1[BUFFERSIZE], string2[BUFFERSIZE], message[BUFFERSIZE];

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
        scanf("%[^\n]",string1);

        write(pipefds1[1], string1, sizeof(string1));
        read(pipefds2[0], message, sizeof(message));

        printf("Reversed: %s\n", message);
    } else {
        // close the unused end of the pipe
        close(pipefds1[1]);  
        close(pipefds2[0]);

        read(pipefds1[0], message, sizeof(message));
        printf("Original: %s\n", message);
        printf("Enter the string: ");
        scanf("%[^\n]",string2);

        // concatenate the two strings
        strcat(message, string2);
        
        printf("Concatenated string: %s\n", message);
        write(pipefds2[1], message, sizeof(message));
    }
    return 0;
}
