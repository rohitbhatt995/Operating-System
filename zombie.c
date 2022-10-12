#include <stdio.h>
#include <unistd.h>

int main()
{
    int x = fork();
    if(x == 0)
    {
        printf("Child\n");
        printf("Child's process ID: %d\n",getpid());
        printf("Child's process show(Parent ID): %d\n",getppid());
    }
    else
    {
        printf("Parent\n");
        sleep(5);
        printf("Parent's process ID: %d\n",getpid());
    }
    return 0;
}