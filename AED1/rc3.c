#include <stdio.h>

int n;
int lab[10][10];
int caminho[10][10];


int caminha(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return 0;
    }

    if (lab[i][j] == 0 || caminho[i][j] == 1) {
        return 0;
    }

    if (i == n - 1 && j == n - 1) {
        return 1;
    }

    caminho[i][j] = 1;

    if (caminha(i + 1, j)) return 1; 
    if (caminha(i, j + 1)) return 1; 
    if (caminha(i - 1, j)) return 1; 
    if (caminha(i, j - 1)) return 1; 
    
    return 0;
}

int main() {
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            scanf("%1d", &lab[i][j]);
            caminho[i][j] = 0;
        }
    }

    if (caminha(0, 0) == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}