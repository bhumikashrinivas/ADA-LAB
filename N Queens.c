#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
int board[MAX][MAX];
int N;
void printBoard() {
    int i, j;
    printf("\nSolution:\n\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(board[i][j] == 1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}
int isSafe(int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return 0;
    }
    for(i = row - 1, j = col - 1;
        i >= 0 && j >= 0;
        i--, j--) {
        if(board[i][j] == 1)
            return 0;
    }
    for(i = row - 1, j = col + 1;
        i >= 0 && j < N;
        i--, j++) {
        if(board[i][j] == 1)
            return 0;
    }
    return 1;
}
int solveNQueens(int row) {
    if(row == N)
        return 1;
    int col;
    for(col = 0; col < N; col++) {
        if(isSafe(row, col)) {
            board[row][col] = 1;
            if(solveNQueens(row + 1))
                return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}
int main() {
    int i, j;
    printf("Enter value of N: ");
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    clock_t start, end;
    start = clock();
    if(solveNQueens(0)) {
        printBoard();
    }
    else {
        printf("No solution exists.\n");
    }
    end = clock();
    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution Time: %f seconds\n", time_taken);
    return 0;
}
