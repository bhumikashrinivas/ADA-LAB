#include <stdio.h>
#include <time.h>

#define MAX 20


int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
int kruskal(int n, int cost[MAX][MAX], int T[MAX][2]) {
    int mincost = 0;
    int edges = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    while (edges < n - 1) {
        int min = 999;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (find(u) != find(v)) {
            T[edges][0] = u;
            T[edges][1] = v;

            mincost += min;
            unionSet(u, v);
            edges++;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    return mincost;
}

int main() {
    int n, cost[MAX][MAX], T[MAX][2];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    start = clock();

    int mincost = kruskal(n, cost, T);

    end = clock();
    cpu_time_used = ((double)(end - start))*1000 / CLOCKS_PER_SEC;

    printf("\nEdges in MST (u - v):\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d - %d\n", T[i][0], T[i][1]);
    }

    printf("\nMinimum cost = %d\n", mincost);
    printf("Execution time = %f seconds\n", cpu_time_used);

    return 0;
}
