#include <stdio.h>
#include <time.h>

float fractionalKnapsack(int remcap, int w[], int p[], float x[], int n)
{
    float maxprofit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (remcap >= w[i])
        {
            remcap = remcap - w[i];
            maxprofit = maxprofit + p[i];
        }
        else
        {
            maxprofit = maxprofit + x[i] * remcap;
            break;
        }
    }

    return maxprofit;
}

void sort(int w[], int p[], float x[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] < x[j])
            {
                float temp = x[i];
                x[i] = x[j];
                x[j] = temp;

                int tempw = w[i];
                w[i] = w[j];
                w[j] = tempw;

                int tempp = p[i];
                p[i] = p[j];
                p[j] = tempp;
            }
        }
    }
}

int main()
{
    int n, remcap;
    clock_t start, end;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int w[n], p[n];
    float x[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &w[i], &p[i]);

        x[i] = (float)p[i] / w[i];
    }

    sort(w, p, x, n);

    printf("Enter the capacity: ");
    scanf("%d", &remcap);

    start = clock();

    float maxp = fractionalKnapsack(remcap, w, p, x, n);

    end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMaximum Profit = %.2f\n", maxp);
    printf("Execution Time = %lf seconds\n", time_taken);

    return 0;
}
