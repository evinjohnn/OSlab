#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("This is the child process. PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    else if (pid > 0)
    {
        // Parent process
        printf("This is the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
    }
    else
    {
        // Fork failed
        printf("Fork failed.\n");
    }

    return 0;
}
