#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // fork
    pid_t pid = fork();
    if (pid == 0) {
        // child
        // sum of all even numbers till n
        int sum = 0;
        for (int i = 2; i <= n; i += 2) {
            sum += i;
        }
        printf("Sum of all even numbers till %d is %d\n", n, sum);
    } else {
        // parent
        // sum of all odd numbers till n
        int sum = 0;
        for (int i = 1; i <= n; i += 2) {
            sum += i;
        }
        printf("Sum of all odd numbers till %d is %d\n", n, sum);
        wait(NULL);
    }
    return 0;
}