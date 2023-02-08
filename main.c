#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "head.h"

uint8_t array[120] = { 0 };

int main()
{
	printf("choose action");
	printf("\n");
	printf("1 - activate cheatcode");
	printf("\n");
	printf("2 - access mac storage");
	printf("\n");

	uint8_t commandToConvert[2] = { 0 };
	fgets(commandToConvert, 2, stdin);
	uint8_t command = commandToConvert[0];
	commandToConvert[0] = 0;

	if (command == '1')
	{
		cheatcode_activation();
	}
	if (command == '2')
	{
		mac_manage(array);
	}
}