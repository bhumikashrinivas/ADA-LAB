#include <stdio.h>
#include <time.h>
#define MAX 20
#define INF 9999

void floyds(int n, int cost[MAX][MAX], int A[MAX][MAX]) {
    int i, j, k;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            A[i][j] = cost[i][j];
        }
    }

    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }

            }
        }
    }
}
int main() {
    int n;
    int cost[MAX][MAX], A[MAX][MAX];
    int i, j;

    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    printf("(Enter %d for INF / no direct edge)\n", INF);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    start = clock();

    floyds(n, cost, A);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nShortest Distance Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(A[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\nExecution Time: %f seconds\n", cpu_time_used);

    return 0;
}



