#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"

#define ASCII_0_DIGIT_OFFSET 0x30
#define ASCII_9_DIGIT_OFFSET 0x39
#define ASCII_A_DIGIT_OFFSET 0x41
#define ASCII_F_DIGIT_OFFSET 0x46
#define ASCII_a_DIGIT_OFFSET 0x61
#define ASCII_f_DIGIT_OFFSET 0x66
#define ASCII_LOWERCASE_HEX_CONVERSION 0x57
#define ASCII_UPPERCASE_HEX_CONVERSION 0x37
#define ASCII_TO_UPPERCASE_CONVERSION 0x20

static bool is_input_correct(char* input)
{
	for (int i = 0; i < 12; i++)
	{
		if (((int)input[i] >= ASCII_0_DIGIT_OFFSET) && ((int)input[i] <= ASCII_9_DIGIT_OFFSET) ||
			((int)input[i] >= ASCII_A_DIGIT_OFFSET) && ((int)input[i] <= ASCII_F_DIGIT_OFFSET) ||
			((int)input[i] >= ASCII_a_DIGIT_OFFSET) && ((int)input[i] <= ASCII_f_DIGIT_OFFSET))
		{
			return true;
		}
		else return false;
	}
}

static int lowercase_to_uppercase(char* input)
{
	for (int i = 0; i < 12; i++)
	{
		if (((int)input[i] >= ASCII_a_DIGIT_OFFSET) && ((int)input[i] <= ASCII_f_DIGIT_OFFSET))
		{
			char upperCaseLetter = (int)input[i] - ASCII_TO_UPPERCASE_CONVERSION;
			input[i] = upperCaseLetter;
		}
	}
}

static int mac_to_array(char* input, int* array)
{
	int firstDigit, secondDigit;
	int counter = 0;
	for (int i = 0; i < 12; i+2)
	{
		if (((int)input[i] >= ASCII_0_DIGIT_OFFSET) && ((int)input[i] <= ASCII_9_DIGIT_OFFSET))
		{
			firstDigit = ((int)input[i] - ASCII_0_DIGIT_OFFSET);
		}
		if (((int)input[i] >= ASCII_A_DIGIT_OFFSET) && ((int)input[i] <= ASCII_F_DIGIT_OFFSET))
		{
			firstDigit = ((int)input[i] - ASCII_UPPERCASE_HEX_CONVERSION);
		}
		
		if (((int)input[i+1] >= ASCII_0_DIGIT_OFFSET) && ((int)input[i+1] <= ASCII_9_DIGIT_OFFSET))
		{
			secondDigit = ((int)input[i+1] - ASCII_0_DIGIT_OFFSET);
		}
		if (((int)input[i+1] >= ASCII_A_DIGIT_OFFSET) && ((int)input[i+1] <= ASCII_F_DIGIT_OFFSET))
		{
			secondDigit = ((int)input[i+1] - ASCII_UPPERCASE_HEX_CONVERSION);
		}

		array[counter] = firstDigit * 16 + secondDigit;
		counter++;
	}
}