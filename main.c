#include "stdio.h"

int check_input(char* input)
{
    int inputLength = strlen(input);
    if ((inputLength>=12)&&(inputLength<=16)&&(input[0] == 'G') && (input[1] == 'I') && (input[2] == 'V') && (input[3] == 'E') &&
        ((int)input[4] <= 57) && ((int)input[4] >= 48) && ((int)input[5] >= 48) && ((int)input[5] <= 57) &&
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
    int multiplyer = 1, multiplyerCheck, digitCount=0, coinAmount=0;
    char code[16] = { '\0' };
    fgets(code, 16, stdin);
    if (check_input(code))
    {
        printf("coins: ");
        multiplyerCheck = ((int)code[4] - 48) * 10 + ((int)code[5] - 48);
        if (multiplyerCheck > 0 && (multiplyerCheck & (multiplyerCheck - 1)) == 0)
        {
            multiplyer = 2;
        }
        for (int i = 12; i <= 15; i++)
        {
            if (code[i] != '\0')
            {
                digitCount += 1;
            }
        }
        if (digitCount == 1)
        {
            coinAmount = ((int)code[11]-48) * multiplyer;
            printf("%d", coinAmount);
        }
        if (digitCount == 2)
        {
            coinAmount = (((int)code[11]-48) * 10 + ((int)code[12]-48)) * multiplyer;
            printf("%d", coinAmount);
        }
        if (digitCount == 3)
        {
            coinAmount = (((int)code[11]-48) * 100 + ((int)code[12]-48) * 10 + ((int)code[13]-48)) * multiplyer;
            printf("%d", coinAmount);
        }
        if (digitCount == 4)
        {
            coinAmount = (((int)code[11]-48) * 1000 + ((int)code[12]-48) * 100 + ((int)code[13]-48) * 10 + ((int)code[14]-48)) * multiplyer;
            printf("%d", coinAmount);
        }
    }
    else
    {
        printf("coins: 0");
    }
}