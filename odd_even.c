#include <stdio.h>
#include <unistd.h>
int main()
{
    int n;
    printf("Enter the no of elements:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i ++)
    {
        scanf("%d",&arr[i]);
    }
    int ev = 0, odd = 0;
    int x = fork();
    if(x != 0)
    {
        for(int i = 0; i < n; i ++)
        {
            if(arr[i] % 2 != 0)
                odd = odd + arr[i];
        }
        printf("Process ID: %d has calculated the sum: %d\n",getpid(),odd);
    }
    else
    {
        for(int i = 0; i < n; i ++)
        {
            if(arr[i] % 2 == 0)
                ev = ev + arr[i];
        }
        printf("Process ID: %d has calculated the sum: %d\n",getpid(),ev);
    }
    return 0;
}
