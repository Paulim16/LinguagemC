#include <stdio.h>

#define NMAX 20

int n;
int col[NMAX], diag1[2*NMAX], diag2[2*NMAX], pos[NMAX];
int total = 0;

void solve_row(int r) {

    if (r == n) {
        total++;
        return;
    }
    
    for (int c = 0; c < n; c++) {
        
        int d1 = r - c + n; 
        int d2 = r + c;
        
        if (!col[c] && !diag1[d1] && !diag2[d2]) {
           
            pos[r] = c;
            col[c] = diag1[d1] = diag2[d2] = 1;
           
            solve_row(r + 1);
            
            col[c] = diag1[d1] = diag2[d2] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
   
    solve_row(0);

    printf("%d\n", total);

    return 0;
}