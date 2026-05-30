#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void heapify(int a[], int n, int i)
{
    int c, item;
    int p=i;
    item=a[p];
    c=2*p+1;
    while(c<=n-1){
        if(c+1<=n-1){
            if(a[c]<a[c+1]) c++;
        }
        if(item<a[c]){
            a[p]=a[c];
            p=c;
            c=2*p+1;
        }
        else break;
    }
    a[p]=item;
}
void buildheap(int a[],int n){
    int i;
    for(i=(n-1)/2;i>=0;i--){
        heapify(a,n,i);
    }
}
void heapSort(int a[], int n)
{
    int i, temp;
    buildheap(a,n);
    for(i=n-1;i>0;i--){
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}

int main()
{
    int n;
    clock_t start, end;
    double cpu_time;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    start = clock();
    heapSort(a, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted elements are:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\nTime taken = %f seconds\n", cpu_time);
    return 0;
}
