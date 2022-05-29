#include <stdio.h>

int main(void) {
    double tara, peso, valor;
    scanf("%lf", &tara); getchar();
    scanf("%lf", &peso); getchar();
    scanf("%lf", &valor); getchar();
    double result = valor * (peso - tara);
    printf("%.2f\n", result);
}