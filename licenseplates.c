#include <stdio.h>

char getChar(int ascii)
{
    return (char)ascii;
}

int isNumber(char chr)
{
    switch (chr)
    {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': return 1;
        default: return 0;
    }
}

int isLetter(char chr)
{
    switch (chr)
    {
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': 
        case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': 
        case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': 
        case 'V': case 'W': case 'X': case 'Y': case 'Z': 
            return 1;
        default: return 0;
    }
}

int main(void)
{
    int c1, c2, c3, c4, c5, c6, c7;
    while (scanf("%d %d %d %d %d %d %d", &c1, &c2, &c3, &c4, &c5, &c6, &c7) != EOF)
    {
        char c1_ = getChar(c1);
        char c2_ = getChar(c2);
        char c3_ = getChar(c3);
        char c4_ = getChar(c4);
        char c5_ = getChar(c5);
        char c6_ = getChar(c6);
        char c7_ = getChar(c7);

        if (isLetter(c1_) && isLetter(c2_) && isLetter(c3_) && isNumber(c4_) && isLetter(c5_) && isNumber(c6_) && isNumber(c7_)) 
            printf("MERCOSUL\n");
        else if (isLetter(c1_) && isLetter(c2_) && isLetter(c3_) && isNumber(c4_) && isNumber(c5_) && isNumber(c6_) && isNumber(c7_)) 
            printf("ANTIGA\n");
        else printf("ERRO\n");
    }
    return 0;
}