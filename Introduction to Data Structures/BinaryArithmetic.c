/*
    C program to perform binary arithmetic (add, subtract and multiply) on
    strings of 1s and 0s.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
#define ZERO '0'
#define ONE '1'

char* add(char*, char*);
char* resize(char*);

int main()
{
    char first_number[SIZE];
    char second_number[SIZE];
    char* result = NULL;

    // Read the numbers from user
    printf("\nEnter the two %d digit binary numbers to add:", SIZE - 1);
    printf("\n#1: ");
    scanf("%s", first_number);
    printf("#2: ");
    scanf("%s", second_number);

    printf("\nTwo numbers are: %s and %s", first_number, second_number);

    result = add(first_number, second_number);
    printf("\nAddition: %s", result);

    if(result != NULL)
        free(result);

    return 0;
}

// Method to add two binary strings
char* add(char* first_number, char* second_number)
{
    char carry = ZERO;
    char binary_digit = ZERO;
    char* result = (char*)malloc(SIZE * sizeof(char));

    // Start adding from right most digit (LSB)
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
            result[index] = binary_digit;
        }

    }
    result[SIZE - 1] = '\0';    // Append with NULL character

    // Add the carry for MSB and resize the result string
    if(carry == ONE)
        result = resize(result);

    return result;
}

// Method to resize the string in case of a carry generated for MSB
char* resize(char* result)
{
    int original_size = strlen(result);
    char* new_result = (char*)malloc(original_size + 1);
    new_result[0] = ONE;
    strcpy(new_result + 1, result);

    // Release the memory for original result
    if(result != NULL)
        free(result);

    return new_result;
}