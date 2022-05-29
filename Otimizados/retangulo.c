#include <stdio.h>

int main(void) {
    int QL, QC, L, C, l, c, qc, ql;
    scanf("%d %d", &QL, &QC); getchar();
    scanf("%d %d", &L, &C); getchar();

    unsigned long long Matriz[25][25] = { 0 };
    for (l = 0; l < QL; l++) Matriz[l][0] = 3;
    for (c = 0; c < QC; c++) Matriz[QL - 1][c] = 2;
    for (l = 0; l < QL; l++) Matriz[l][QC - 1] = 1;
    for (c = 0; c < QC; c++) Matriz[0][c] = 0;

    for (l = 1; l < L; l++)
        for (c = 1; c < C; c++)
            Matriz[l][c] = Matriz[l - 1][c - 1] + Matriz[l - 1][c] + Matriz[l][c - 1];
    
    printf("%llu\n", Matriz[L - 1][C - 1]);
    return 0;
}