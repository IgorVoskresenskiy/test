#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "head.h"

#define IS_NUMBER_POW_OF_TWO(number) ((((number) > 0) && ((number) & ((number) - 1))) == 0)
#define ASCII_0_DIGIT_OFFSET 0x30
#define ASCII_9_DIGIT_OFFSET 0x39
#define CHEAT_CODE_LENGTH 16

static int ascii_to_int(int asciiCode)
{
    return asciiCode - ASCII_0_DIGIT_OFFSET;
}

static bool check_input(char* input)
{
    int inputLength = strlen(input);
    bool isLengthOk = inputLength >= 12 && inputLength <= 16;

    bool isNumbersOk = (int)input[4] <= ASCII_9_DIGIT_OFFSET && (int)input[4] >= ASCII_0_DIGIT_OFFSET &&
        (int)input[5] >= ASCII_0_DIGIT_OFFSET && (int)input[5] <= ASCII_9_DIGIT_OFFSET;

    bool isMaskOk = input[0] == 'G' && input[1] == 'I' && input[2] == 'V' && input[3] == 'E' &&
        input[6] == 'M' && input[7] == 'O' && input[8] == 'N' && input[9] == 'E' && input[10] == 'Y';

    bool isCoinAmountCorrect = (int)input[11] <= ASCII_9_DIGIT_OFFSET && (int)input[11] >= ASCII_0_DIGIT_OFFSET &&
        (int)input[12] >= ASCII_0_DIGIT_OFFSET && (int)input[12] <= ASCII_9_DIGIT_OFFSET &&
        (int)input[13] >= ASCII_0_DIGIT_OFFSET && (int)input[13] <= ASCII_9_DIGIT_OFFSET &&
        (int)input[14] >= ASCII_0_DIGIT_OFFSET && (int)input[14] <= ASCII_9_DIGIT_OFFSET;

    if (isLengthOk && isNumbersOk && isMaskOk)
    {
        return true;
    }

    return false;
}

void cheatcode_activation()
{
    uint8_t multiplyer = 1;
    uint8_t cheatNumber;
    uint8_t digitCount = 0;
    uint16_t coinAmount = 0;
    char code[CHEAT_CODE_LENGTH] = { '\0' };
    gets_s(code, CHEAT_CODE_LENGTH);
    if (check_input(code))
    {
        printf("coins: ");
        cheatNumber = ascii_to_int(code[4]) * 10 + ascii_to_int(code[5]);
        if (IS_NUMBER_POW_OF_TWO(cheatNumber))
        {
            multiplyer = 2;
        }
        for (uint8_t i = 11; i < 15; i++)
        {
            if ((code[i] != '\0') && (code[i] != '\n') && (code[i] != 'þ'))
            {
                digitCount += 1;
            }
        }
        for (uint8_t i = 0; i < digitCount; i++)
        {
            coinAmount *= 10;
            coinAmount += ascii_to_int(code[11 + i]);
        }
        printf("%d", coinAmount * multiplyer);
    }
    else
    {
        printf("coins: 0");
    }
}