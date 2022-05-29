#include <stdio.h>

int main(void) {
    int N, n, I = 0, II = 0, III = 0, IV = 0;
    scanf("%d", &N);
    getchar();

    for (n = 0; n < N; n++) {
        int x, y;
        scanf("%d %d", &x, &y);
        getchar();

        if (x > 0 && y > 0) I++;
        if (x > 0 && y < 0) II++;
        if (x < 0 && y < 0) III++;
        if (x < 0 && y > 0) IV++;
    }

    printf("I = %d\n", I);
    printf("II = %d\n", II);
    printf("III = %d\n", III);
    printf("IV = %d\n", IV);
    return 0;
}