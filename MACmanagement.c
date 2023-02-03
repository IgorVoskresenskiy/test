#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "head.h"

#define ASCII_0_DIGIT_OFFSET 0x30
#define ASCII_9_DIGIT_OFFSET 0x39
#define ASCII_A_DIGIT_OFFSET 0x41
#define ASCII_F_DIGIT_OFFSET 0x46
#define ASCII_a_DIGIT_OFFSET 0x61
#define ASCII_f_DIGIT_OFFSET 0x66
#define ASCII_UPPERCASE_HEX_CONVERSION 0x37
#define ASCII_TO_UPPERCASE_CONVERSION 0x20

bool is_input_correct(char* input)
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

void lowercase_to_uppercase(char* input)
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

void mac_to_array(char* input, int* array)
{
	int firstDigit = 0, secondDigit = 0;
	int counter = 0;
	for (int i = 0; i < 12; i += 2)
	{
		if (((int)input[i] >= ASCII_0_DIGIT_OFFSET) && ((int)input[i] <= ASCII_9_DIGIT_OFFSET))
		{
			firstDigit = ((int)input[i] - ASCII_0_DIGIT_OFFSET);
		}
		if (((int)input[i] >= ASCII_A_DIGIT_OFFSET) && ((int)input[i] <= ASCII_F_DIGIT_OFFSET))
		{
			firstDigit = ((int)input[i] - ASCII_UPPERCASE_HEX_CONVERSION);
		}

		if (((int)input[i + 1] >= ASCII_0_DIGIT_OFFSET) && ((int)input[i + 1] <= ASCII_9_DIGIT_OFFSET))
		{
			secondDigit = ((int)input[i + 1] - ASCII_0_DIGIT_OFFSET);
		}
		if (((int)input[i + 1] >= ASCII_A_DIGIT_OFFSET) && ((int)input[i + 1] <= ASCII_F_DIGIT_OFFSET))
		{
			secondDigit = ((int)input[i + 1] - ASCII_UPPERCASE_HEX_CONVERSION);
		}

		array[counter] = firstDigit * 16 + secondDigit;
		counter++;
	}
}

void insert_mac_by_index(int* mac, int* array)
{
	int index;
	scanf_s("%i", &index);
	array[index * 6] = mac[0];
	array[index * 6 + 1] = mac[1];
	array[index * 6 + 2] = mac[2];
	array[index * 6 + 3] = mac[3];
	array[index * 6 + 4] = mac[4];
	array[index * 6 + 5] = mac[5];
}

void insert_mac_in_first_unoc(int* mac, int* array)
{
	int firstFreeIndex = 0;
	for (int i = 0; i < 120; i += 6)
	{
		if (array[i] == 0)
		{
			firstFreeIndex = i / 6;
			break;
		}
	}
	array[firstFreeIndex * 6] = mac[0];
	array[firstFreeIndex * 6 + 1] = mac[1];
	array[firstFreeIndex * 6 + 2] = mac[2];
	array[firstFreeIndex * 6 + 3] = mac[3];
	array[firstFreeIndex * 6 + 4] = mac[4];
	array[firstFreeIndex * 6 + 5] = mac[5];
}

void delete_mac_by_index(int* mac, int* array)
{
	int index;
	scanf_s("%i", &index);
	array[index * 6] = 0;
	array[index * 6 + 1] = 0;
	array[index * 6 + 2] = 0;
	array[index * 6 + 3] = 0;
	array[index * 6 + 4] = 0;
	array[index * 6 + 5] = 0;
}

void delete_mac_by_address(int* mac, int* array)
{
	for (int i = 0; i < 120; i += 6)
	{
		if (array[i] == mac[0])
		{
			if (array[i + 1] == mac[1] && array[i + 2] == mac[2] && array[i + 3] == mac[3] && array[i + 4] == mac[4] && array[i + 5] == mac[5])
			{
				array[i] = 0;
				array[i + 1] = 0;
				array[i + 2] = 0;
				array[i + 3] = 0;
				array[i + 4] = 0;
				array[i + 5] = 0;
				break;
			}
		}
	}
}

void delete_all_mac(int* array)
{
	for (int i = 0; i < 120; i++)
	{
		array[i] = 0;
	}
}

void print_mac_by_index(int* array)
{
	int index;
	scanf_s("%i", &index);
	if (array[index * 6] != 0)
	{
		printf("%i", array[index * 6]);
		printf("%i", array[index * 6 + 1]);
		printf("%i", array[index * 6 + 2]);
		printf("%i", array[index * 6 + 3]);
		printf("%i", array[index * 6 + 4]);
		printf("%i", array[index * 6 + 5]);
	}
}

int find_mac_by_address(int* mac, int* array)
{
	for (int i = 0; i < 120; i += 6)
	{
		if (array[i] == mac[0])
		{
			if (array[i + 1] == mac[1] && array[i + 2] == mac[2] && array[i + 3] == mac[3] && array[i + 4] == mac[4] && array[i + 5] == mac[5])
			{
				return i;
			}
		}
	}
	return 0;
}