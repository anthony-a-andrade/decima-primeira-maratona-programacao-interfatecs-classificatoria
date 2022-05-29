#include <stdio.h>
#include <string.h>

int index_of(char str[], char chr) {
    int i;
    for (i = 0; i < 26; i++)
        if (str[i] == chr)
            return i;
    return -1;
}

int main(void) {
    char entrada[201], nums_[401], sinal = '\0', alfa[] = "abcdefghijklmnopqrstuvwxyz";
    int nums[400], i, indexNum = 0, i_ = 0;

    scanf("%s", entrada);
    getchar();

    scanf("%s", nums_);
    getchar();

    for(i = 0; i < strlen(nums_); i++) {
        char num = nums_[i];
        if (num == '-' || num == '+') sinal = num;
        else {
            int valor = num - '0';
            if (sinal == '-') valor *= -1;
            nums[indexNum] = valor;
            indexNum++;
        }
    }

    for (i = 0; i < strlen(entrada); i++) {
        char letra = entrada[i];
        if (letra == 'w') {
            printf(" ");
            continue;
        }
        int posicao = index_of(alfa, letra);
        posicao += nums[i_];
        i_++;
        if (posicao > 25) posicao -= 26;
        if (posicao < 0) posicao += 26;
        printf("%c", alfa[posicao]);
    }
    printf("\n");
    return 0;
}