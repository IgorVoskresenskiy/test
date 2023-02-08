#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "head.h"
#include "stdlib.h"

int main()
{
	printf("choose action");
	printf("\n");
	printf("1 - activate cheatcode");
	printf("\n");
	printf("2 - access mac storage");
	printf("\n");

	uint8_t commandInput[3] = { 0 };
	gets_s(commandInput, 3);
	uint8_t command = atoi(commandInput);

	if (command == 1)
	{
		cheatcode_activation();
	}
	if (command == 2)
	{
		mac_manage(array);
	}
}