/*
    C program to perform binary arithmetic (add, subtract and multiply) on
    strings of 1s and 0s.

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ZERO '0'
#define ONE '1'

char* add(char* first_number, char* second_number)
{
    char carry = ZERO;
    char binary_digit = ZERO;
    char* result = (char*)malloc(SIZE * sizeof(char));

    for(int index = SIZE - 2; index >= 0; index--)
    {
        if(first_number[index] == ZERO && second_number[index] == ZERO)
        {
            binary_digit = carry;
            carry = ZERO;
            result[index] = binary_digit;
        }
        else if(first_number[index] == ONE && second_number[index] == ONE)
        {
            binary_digit = carry;
            carry = ONE;
            result[index] = binary_digit;
        }
        else
        {
            binary_digit = carry == ZERO ? ONE : ZERO;
            carry = binary_digit;
            result[index] = binary_digit;
        }

    }
    result[SIZE - 1] = '\0';

    return result;
}

int main()
{
    char first_number[SIZE] = "0001";
    char second_number[SIZE] = "0001";
    char* result = NULL;

    printf("\nTwo numbers are: %s and %s", first_number, second_number);

    result = add(first_number, second_number);
    printf("\nAddition: %s", result);

    if(result != NULL)
        free(result);

    return 0;
}