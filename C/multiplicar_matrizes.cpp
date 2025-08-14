#include <stdio.h>

int main() {
    
    int A[2][3] = { 
        {1, 2, 3}, 
        {3, 1, 4}
    };
    
    int B[3][2] = {
        {3, 2}, 
        {5, 4}, 
        {6, 1}
    };
    
    int R[2][2];

    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 2; j ++) {
            R[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i ++) { // Linhas de A
        for (int j = 0; j < 2; j++) { //Colunas de B
            for (int k = 0; k < 3; k++) {  //Elementos
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j ++) {
            printf("%d\n", R[i][j]);
        }
    }
return 0;
}