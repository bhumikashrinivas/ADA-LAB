#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int p[n], dir[n];

    // Initialize permutation and directions
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i] = -1;   // -1 = left, 1 = right
    }

    // Print first permutation
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");

    while(1) {
        int mobile = 0, pos;

        // Find largest mobile element
        for(int i = 0; i < n; i++) {
            if(dir[p[i]-1] == -1 && i > 0 && p[i] > p[i-1] && p[i] > mobile) {
                mobile = p[i];
                pos = i;
            }
            if(dir[p[i]-1] == 1 && i < n-1 && p[i] > p[i+1] && p[i] > mobile) {
                mobile = p[i];
                pos = i;
            }
        }

        if(mobile == 0)
            break;

        // Swap according to direction
        if(dir[mobile-1] == -1) {
            int temp = p[pos];
            p[pos] = p[pos-1];
            p[pos-1] = temp;
            pos--;
        } else {
            int temp = p[pos];
            p[pos] = p[pos+1];
            p[pos+1] = temp;
            pos++;
        }

        // Reverse direction of elements greater than mobile
        for(int i = 0; i < n; i++)
            if(p[i] > mobile)
                dir[p[i]-1] *= -1;

        // Print permutation
        for(int i = 0; i < n; i++)
            printf("%d ", p[i]);
        printf("\n");
    }

    return 0;
}
