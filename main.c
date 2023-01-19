#include "stdio.h"

int inputCheck(char input[])
{
    if ((input[0] == 'G') && (input[1] == 'I') && (input[2] == 'V') && (input[3] == 'E') &&
        (input[6] == 'M') && (input[7] == 'O') && (input[8] == 'N') && (input[9] == 'E') && (input[10] == 'Y'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char code[16];
    for (int i = 0; i < 16; i++)
        code[i] = '\0';
    fgets(code, 15, stdin);
    if (inputCheck(code))
    {
        printf("coins: ");
        if (code[11] != '\0')
        {
            printf("%c", code[11]);
        }
        if (code[12] != '\0')
        {
            printf("%c", code[12]);
        }
        if (code[13] != '\0')
        {
            printf("%c", code[13]);
        }
        if (code[14] != '\0')
        {
            printf("%c", code[14]);
        }
    }
    else
    {
        printf("coins: 0");
    }
}

