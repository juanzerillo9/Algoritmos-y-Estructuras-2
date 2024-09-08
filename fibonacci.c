#include <stdio.h>
#include <stdlib.h>

int fibonachi(int n);

int main()
{
    int n = 10;
    for(int i = 0; i < 10; i++)
    {
        printf("%d \n", fibonachi(i));
    }    
    return 0;
}


int fibonachi(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    else
    {
        return(fibonachi(n-1) + fibonachi(n - 2));
    }
}