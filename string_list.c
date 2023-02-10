#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#define INSERT_STRING_INTO_LIST 1
#define PRINT_LIST 2
#define EXIT_COMMAND 3

typedef struct Node
{
    char value[12];
    struct Node* next;
} Node;

Node* head = NULL;

bool push(Node** head, char* data)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp != NULL)
    {
        tmp->value[0] = data[0];
        tmp->value[1] = data[1];
        tmp->value[2] = data[2];
        tmp->value[3] = data[3];
        tmp->value[4] = data[4];
        tmp->value[5] = data[5];
        tmp->value[6] = data[6];
        tmp->value[7] = data[7];
        tmp->value[8] = data[8];
        tmp->value[9] = data[9];
        tmp->value[10] = data[10];
        tmp->value[11] = '\0';
        tmp->next = (*head);
        (*head) = tmp;
        return true;
    }
    else
    {
        return false;
    }
}

void print_list(Node* head)
{
    int stringSymbolCount;
    Node* tmp = head;
    while (tmp != NULL)
    {
        stringSymbolCount = 0;
        printf("\"");
        while (tmp->value[stringSymbolCount] != '\0')
        {
            printf("%c", tmp->value[stringSymbolCount]);
            stringSymbolCount++;
        }
        printf("\"");

        if (tmp->next != NULL)
        {
            printf(", ");
        }
        tmp = tmp->next;
    }
}

void string_list()
{
    printf("choose action with string list");
    printf("\n");
    printf("1 - insert string into list");
    printf("\n");
    printf("2 - print list");
    printf("\n");
    printf("3 - exit");
    printf("\n");

    uint8_t commandInput[3] = { 0 };
    gets_s(commandInput, 3);
    uint8_t command = atoi(commandInput);
    commandInput[0] = 0;
    commandInput[1] = 0;
    commandInput[2] = 0;

    while (command != EXIT_COMMAND)
    {
        char string[12] = {'\0'};
        if (command == INSERT_STRING_INTO_LIST)
        {
            printf("input string: ");
            gets_s(string, 12);
            printf("\n");
            if (push(&head, string))
            {
                printf("successfully inserted");
                printf("\n");
            }
            else
            {
                printf("there is no free memory");
                printf("\n");
            }
        }

        if (command == PRINT_LIST)
        {
            print_list(head);
        }

        gets_s(commandInput, 3);
        command = atoi(commandInput);
        commandInput[0] = 0;
        commandInput[1] = 0;
        commandInput[2] = 0;
    }

}