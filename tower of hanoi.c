#include<stdio.h>
int tower(int n,char f,char a,char t)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        tower(n-1,f,a,t);
        printf("disk %d moved from %c to %c\n",n,f,t);
        tower(n-1,a,t,f);
    }
}
int main()
{
    int n;
    printf("Enter the number of disk:\n");
    scanf("%d",&n);
    tower(n,'A','C','B');
    return 0;
}
