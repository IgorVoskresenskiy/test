#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "head.h"
#include "stdlib.h"

#define ASCII_0_DIGIT_OFFSET 0x30
#define ASCII_9_DIGIT_OFFSET 0x39
#define ASCII_A_DIGIT_OFFSET 0x41
#define ASCII_F_DIGIT_OFFSET 0x46
#define ASCII_a_DIGIT_OFFSET 0x61
#define ASCII_f_DIGIT_OFFSET 0x66
#define ASCII_UPPERCASE_HEX_CONVERSION 0x37
#define ASCII_TO_UPPERCASE_CONVERSION 0x20

uint8_t array[120] = { 0 };

bool mac_mgmt_is_input_correct(char* macAddr)
{
	uint8_t correctSymbolCounter = 0;
	for (uint8_t i = 0; i < 12; i++)
	{
		if (((int)macAddr[i] >= ASCII_0_DIGIT_OFFSET) && ((int)macAddr[i] <= ASCII_9_DIGIT_OFFSET) ||
			((int)macAddr[i] >= ASCII_A_DIGIT_OFFSET) && ((int)macAddr[i] <= ASCII_F_DIGIT_OFFSET) ||
			((int)macAddr[i] >= ASCII_a_DIGIT_OFFSET) && ((int)macAddr[i] <= ASCII_f_DIGIT_OFFSET))
		{
			correctSymbolCounter++;
		}
	}
	if (correctSymbolCounter == 12)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void mac_mgmt_convert_to_uppercase(char* macAddr)
{
	for (uint8_t i = 0; i < 12; i++)
	{
		if (((int)macAddr[i] >= ASCII_a_DIGIT_OFFSET) && ((int)macAddr[i] <= ASCII_f_DIGIT_OFFSET))
		{
			char upperCaseLetter = (int)macAddr[i] - ASCII_TO_UPPERCASE_CONVERSION;
			macAddr[i] = upperCaseLetter;
		}
	}
}

void mac_mgmt_convert_string_to_byte_array(char* macAddr, int* macAddrArray)
{
	uint8_t firstDigit = 0, secondDigit = 0;
	uint8_t counter = 0;
	for (uint8_t i = 0; i < 12; i += 2)
	{
		if (((int)macAddr[i] >= ASCII_0_DIGIT_OFFSET) && ((int)macAddr[i] <= ASCII_9_DIGIT_OFFSET))
		{
			firstDigit = ((int)macAddr[i] - ASCII_0_DIGIT_OFFSET);
		}
		if (((int)macAddr[i] >= ASCII_A_DIGIT_OFFSET) && ((int)macAddr[i] <= ASCII_F_DIGIT_OFFSET))
		{
			firstDigit = ((int)macAddr[i] - ASCII_UPPERCASE_HEX_CONVERSION);
		}

		if (((int)macAddr[i + 1] >= ASCII_0_DIGIT_OFFSET) && ((int)macAddr[i + 1] <= ASCII_9_DIGIT_OFFSET))
		{
			secondDigit = ((int)macAddr[i + 1] - ASCII_0_DIGIT_OFFSET);
		}
		if (((int)macAddr[i + 1] >= ASCII_A_DIGIT_OFFSET) && ((int)macAddr[i + 1] <= ASCII_F_DIGIT_OFFSET))
		{
			secondDigit = ((int)macAddr[i + 1] - ASCII_UPPERCASE_HEX_CONVERSION);
		}

		macAddrArray[counter] = firstDigit * 16 + secondDigit;
		counter++;
	}
}

void mac_mgmt_insert_mac_by_index(int* macAddr, int index, int* array)
{
	array[index * 6] = macAddr[0];
	array[index * 6 + 1] = macAddr[1];
	array[index * 6 + 2] = macAddr[2];
	array[index * 6 + 3] = macAddr[3];
	array[index * 6 + 4] = macAddr[4];
	array[index * 6 + 5] = macAddr[5];
}

void mac_mgmt_insert_in_free_cell(int* macAddr, int* array)
{
	uint8_t firstFreeIndex = 0;
	for (int i = 0; i < 120; i += 6)
	{
		if (array[i] == 0)
		{
			firstFreeIndex = i / 6;
			break;
		}
	}
	array[firstFreeIndex * 6] = macAddr[0];
	array[firstFreeIndex * 6 + 1] = macAddr[1];
	array[firstFreeIndex * 6 + 2] = macAddr[2];
	array[firstFreeIndex * 6 + 3] = macAddr[3];
	array[firstFreeIndex * 6 + 4] = macAddr[4];
	array[firstFreeIndex * 6 + 5] = macAddr[5];
}

void mac_mgmt_delete_mac_by_index(int index, int* array)
{
	array[index * 6] = 0;
	array[index * 6 + 1] = 0;
	array[index * 6 + 2] = 0;
	array[index * 6 + 3] = 0;
	array[index * 6 + 4] = 0;
	array[index * 6 + 5] = 0;
}

void mac_mgmt_delete_mac_by_address(int* macAddr, int* array)
{
	for (uint8_t i = 0; i < 120; i += 6)
	{
		if (array[i] == macAddr[0])
		{
			if (array[i + 1] == macAddr[1] && array[i + 2] == macAddr[2] && array[i + 3] == macAddr[3] && array[i + 4] == macAddr[4] && array[i + 5] == macAddr[5])
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

void mac_mgmt_delete_all_mac(int* array)
{
	for (uint8_t i = 0; i < 120; i++)
	{
		array[i] = 0;
	}
}

void mac_mgmt_print_mac_by_index(int index, int* array)
{
	if (array[index * 6] != 0)
	{
		printf("%i", array[index * 6]);
		printf("%i", array[index * 6 + 1]);
		printf("%i", array[index * 6 + 2]);
		printf("%i", array[index * 6 + 3]);
		printf("%i", array[index * 6 + 4]);
		printf("%i", array[index * 6 + 5]);
	}
	else
	{
		printf("there is no mac under this index");
	}
}

bool mac_mgmt_check_if_mac_in_array(int* macAddr, int* array)
{
	for (uint8_t i = 0; i < 120; i += 6)
	{
		if (array[i] == macAddr[0])
		{
			if (array[i + 1] == macAddr[1] && array[i + 2] == macAddr[2] && array[i + 3] == macAddr[3] && array[i + 4] == macAddr[4] && array[i + 5] == macAddr[5])
			{
				return true;
			}
		}
	}
	return false;
}

void mac_manage(int* array)
{
	printf("choose action with mac");
	printf("\n");
	printf("1 - insert mac by index");
	printf("\n");
	printf("2 - insert mac in first free cell");
	printf("\n");
	printf("3 - delete mac by index");
	printf("\n");
	printf("4 - delete mac by address");
	printf("\n");
	printf("5 - delete all mac");
	printf("\n");
	printf("6 - print mac by index if exists");
	printf("\n");
	printf("7 - check if mac in array");
	printf("\n");
	printf("8 - exit");
	printf("\n");

	uint8_t commandInput[3] = { 0 };
	gets_s(commandInput, 3);
	uint8_t command = atoi(commandInput);
	commandInput[0] = 0;
	commandInput[1] = 0;
	commandInput[2] = 0;

	while (command != 8)
	{
		char macInput[12] = { 0 };
		char mac[6] = { 0 };
		uint8_t indexInput[3] = { 0 };
		
		if (command == 1)
		{
			uint8_t index = 0;
			printf("input mac: ");
			gets_s(macInput, 13);
			printf("\n");
			printf("input index: ");
			gets_s(indexInput, 3);
			index = atoi(indexInput);
			indexInput[0] = 0;
			indexInput[1] = 0;
			indexInput[2] = 0;
			printf("\n");

			if (mac_mgmt_is_input_correct(macInput))
			{
				mac_mgmt_convert_to_uppercase(macInput);
				mac_mgmt_convert_string_to_byte_array(macInput, mac);
				mac_mgmt_insert_mac_by_index(mac, index, array);
			}
			else
			{
				printf("incorrect input\n");
			}
		}

		if (command == 2)
		{
			printf("input mac: ");
			gets_s(macInput, 13);
			printf("\n");

			if (mac_mgmt_is_input_correct(macInput))
			{
				mac_mgmt_convert_to_uppercase(macInput);
				mac_mgmt_convert_string_to_byte_array(macInput, mac);
				mac_mgmt_insert_in_free_cell(mac, array);
			}
			else
			{
				printf("incorrect input\n");
			}
		}

		if (command == 3)
		{
			uint8_t index = 0;
			printf("input index: ");
			gets_s(indexInput, 3);
			index = atoi(indexInput);
			indexInput[0] = 0;
			indexInput[1] = 0;
			indexInput[2] = 0;
			printf("\n");

			mac_mgmt_delete_mac_by_index(index, array);
		}

		if (command == 4)
		{
			printf("input mac: ");
			gets_s(macInput, 13);
			printf("\n");

			if (mac_mgmt_is_input_correct(macInput))
			{
				mac_mgmt_convert_to_uppercase(macInput);
				mac_mgmt_convert_string_to_byte_array(macInput, mac);
				mac_mgmt_delete_mac_by_address(mac, array);
			}
			else
			{
				printf("incorrect input");
				printf("\n");
			}
		}

		if (command == 5)
		{
			mac_mgmt_delete_all_mac(array);
		}

		if (command == 6)
		{
			uint8_t index = 0;
			printf("input index: ");
			gets_s(indexInput, 3);
			index = atoi(indexInput);
			indexInput[0] = 0;
			indexInput[1] = 0;
			indexInput[2] = 0;
			printf("\n");

			mac_mgmt_print_mac_by_index(index, array);

		}

		if (command == 7)
		{
			printf("input mac: ");
			gets_s(macInput, 13);
			printf("\n");

			if (mac_mgmt_is_input_correct(macInput))
			{
				mac_mgmt_convert_to_uppercase(macInput);
				mac_mgmt_convert_string_to_byte_array(macInput, mac);
				if (mac_mgmt_check_if_mac_in_array(mac, array))
				{
					printf("mac is in array");
					printf("\n");
				}
				else
				{
					printf("mac is not in array");
					printf("\n");
				}
			}
			else
			{
				printf("incorrect input");
				printf("\n");
			}
		}

		gets_s(commandInput, 3);
		command = atoi(commandInput);
		commandInput[0] = 0;
		commandInput[1] = 0;
		commandInput[2] = 0;
	}
}