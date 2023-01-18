#include "stdio.h"

int main()
{
    char code[16];
    gets(code);
    if ((code[0] == 'G')&&(code[1] == 'I')&&(code[2] == 'V')&&(code[3] == 'E')&&(code[6] == 'M')&&(code[7] == 'O')&&(code[8] == 'N')&&(code[9] == 'E')&&(code[10] == 'Y'))
    {
        printf("coins: ");
        if (code[11] != '/0') {
            printf("%c", code[11]);
        }
       if (code[12] != '/0') {
            printf("%c", code[12]);
        }
        if (code[13] != '/0') {
            printf("%c", code[13]);
        }
        if (code[14] != '/0') {
            printf("%c", code[14]);
        }
    }
    else
    {
        printf("coins: 0");
    }
}

