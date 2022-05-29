#include <stdio.h>

int main(void) {    
    int N, n, ok = 1, atual = 1;
    scanf("%d", &N); 
    getchar(); 

    for (n = 0; n < N; n++)
    {
        int valor;
        scanf("%d", &valor); 
        getchar();

        if (valor > atual) ok = 0;
        for (;atual < valor; atual++) printf("%d\n", atual);
        atual++;
    }
    if (ok) printf("bom trabalho\n");
    return 0;
}