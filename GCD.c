#include<stdio.h>
int gcd(int a,int b);
int main()
{
    int a,b;
    printf("Enter the first element:\n");
    scanf("%d",&a);
    printf("Enter the second element:\n");
    scanf("%d",&b);
    int g=gcd(a,b);
    printf("GCD:%d",g);
    return 0;

}

int gcd(int a,int b)
{
    if (b=0)
    {
        return a;
    }
    while(b!=0)
    {
    int temp=b;
    b=a%b;
    a=temp;
    }
    return a;

}
