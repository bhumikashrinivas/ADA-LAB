#include <stdio.h>
#include <time.h>
int partition(int a[100], int low, int high){
    int i, j, key, temp;
    i = low + 1;
    j = high;
    key = a[low];
    while(1){
        while(a[i] <= key && i < high) i++;
        while(a[j] > key) j--;
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else{
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quicksort(int a[100], int low, int high){
    int j;
    if(low < high){
        j = partition(a, low, high);
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);
    }
}

int main(){
    int low, high, i;
    clock_t start, end;
    double time_taken;

    printf("Enter low: ");
    scanf("%d",&low);

    printf("Enter high: ");
    scanf("%d",&high);

    int a[100];

    printf("Enter %d elements:\n",(high - low) + 1);
    for(i = low; i <= high; i++){
        scanf("%d",&a[i]);
    }

    start = clock();

    quicksort(a, low, high);

    end = clock();

    printf("Sorted array:\n");
    for(i = low; i <= high; i++){
        printf("%d ", a[i]);
    }

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken = %f seconds", time_taken);

    return 0;
}


