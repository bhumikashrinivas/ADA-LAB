#include <stdio.h>
#include <time.h>
#define MAX 10
int graph[MAX][MAX], visited[MAX], stack[MAX];
int n, top = -1;
void dfs(int v)
{
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
    stack[++top] = v;
}
void topologicalSort()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    printf("Topological Ordering: ");
    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main()
{
    clock_t start, end;
    double time_taken;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix row by row:\n");
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            printf("graph[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    start = clock();
    topologicalSort();
    end = clock();
    time_taken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Execution Time: %lf ms\n", time_taken);
    return 0;
}
