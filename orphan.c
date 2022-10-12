// Write a program to implement Orphan process

#include <stdio.h>
#include <unistd.h>

int main()
{
    int x = fork();
    if(x == 0)
    {
        printf("Child\n");
        sleep(5);
        printf("Child process ID: %d\n",getpid());
        printf("Child process show(its Parent ID): %d\n",getppid());
    }
    else
    {
        printf("Parent\n");
        printf("Parent process ID: %d\n",getpid());
    }

    return 0;
}
