#include <unistd.h>
#include <stdio.h>

int main()
{
    printf ("the program is running.sleeping for 5 seconds...");
    sleep(5);
        printf ("the program is resuming after 5 seconds...");
        return 0;
}
