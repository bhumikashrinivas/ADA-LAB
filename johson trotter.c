#include <stdio.h>
#include <time.h>

int main()
{
    int n;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int p[n], dir[n];

    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        dir[i] = -1;
    }

    start = clock();

    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");

    while (1)
    {
        int mobile = 0, pos = -1;

        for (int i = 0; i < n; i++)
        {
            if (dir[p[i] - 1] == -1 &&
                i > 0 &&
                p[i] > p[i - 1] &&
                p[i] > mobile)
            {
                mobile = p[i];
                pos = i;
            }

            if (dir[p[i] - 1] == 1 &&
                i < n - 1 &&
                p[i] > p[i + 1] &&
                p[i] > mobile)
            {
                mobile = p[i];
                pos = i;
            }
        }

        if (mobile == 0)
            break;

        if (dir[mobile - 1] == -1)
        {
            int temp = p[pos];
            p[pos] = p[pos - 1];
            p[pos - 1] = temp;
            pos--;
        }
        else
        {
            int temp = p[pos];
            p[pos] = p[pos + 1];
            p[pos + 1] = temp;
            pos++;
        }

        for (int i = 0; i < n; i++)
        {
            if (p[i] > mobile)
                dir[p[i] - 1] *= -1;
        }

        for (int i = 0; i < n; i++)
            printf("%d ", p[i]);
        printf("\n");
    }

    end = clock();

    time_taken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

    printf("\nExecution Time: %lf ms\n", time_taken);
    printf("Time Complexity: O(n * n!)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}
