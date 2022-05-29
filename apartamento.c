#include <stdio.h>

int main(void)
{
    double C, M, i;
    scanf("%lf", &C);
    getchar();
    scanf("%lf", &M);
    getchar();
    scanf("%lf", &i);
    getchar();
    
    int n = 0;
    while (C < M)
    {
        C *= 1 + (i / 100.0);
        n++;
    }

    if (n == 0) printf("pode comprar agora\n");
    else if (n == 1) printf("possivel em 1 mes\n");
    else printf("possivel em %d meses\n", n);

    return 0;
}