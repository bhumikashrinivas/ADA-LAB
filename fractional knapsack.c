#include <stdio.h>
#include <time.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int knapsackDP(int n, int M, int W[], int P[])
{
    int i, j;
    int Table[n + 1][M + 1];

    for (i = 0; i <= n; i++)
        Table[i][0] = 0;

    for (j = 0; j <= M; j++)
        Table[0][j] = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (j < W[i - 1])
            {
                Table[i][j] = Table[i - 1][j];
            }
            else
            {
                Table[i][j] = max(
                    Table[i - 1][j],
                    P[i - 1] + Table[i - 1][j - W[i - 1]]
                );
            }
        }
    }

    return Table[n][M];
}

int main()
{
    int n, M;
    clock_t start, end;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int W[n], P[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &W[i]);

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &P[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &M);

    start = clock();

    int result = knapsackDP(n, M, W, P);

    end = clock();

    printf("Maximum Profit = %d\n", result);

    double time_taken =
        ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

    printf("Execution Time = %lf ms\n", time_taken);

    return 0;
}
