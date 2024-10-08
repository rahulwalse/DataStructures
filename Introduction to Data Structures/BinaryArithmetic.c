//  This C program is an implementation of exercise 1.1.5 to perform binary arithmetic 
//  operations (add, subtract and multiply) on strings of 1s and 0s.
//
//  NOTE: The subtract and multiply operations are not implemented.

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
    char summed_binary_digit = ZERO;
    int size = strlen(first_number);
    char* result = (char*)malloc((size * sizeof(char)) + 1);

    // Start adding from right most digit (LSB)
    for(int index = size - 1; index >= 0; index--)
    {
        if(first_number[index] == ZERO && second_number[index] == ZERO)
        {
            summed_binary_digit = carry;
            carry = ZERO;
            result[index] = summed_binary_digit;
        }
        else if(first_number[index] == ONE && second_number[index] == ONE)
        {
            summed_binary_digit = carry;
            carry = ONE;
            result[index] = summed_binary_digit;
        }
        else
        {
            summed_binary_digit = carry == ZERO ? ONE : ZERO;
            result[index] = summed_binary_digit;
        }

    }
    result[size] = '\0';    // Append with NULL character

    // Add the carry for MSB and resize the result string
    if(carry == ONE)
        result = resize(result);

    return result;
}

// Method to resize the string in case of a carry generated for MSB
char* resize(char* original_result)
{
    int original_size = strlen(original_result);
    char* new_result = (char*)malloc(original_size + 1);
    new_result[0] = ONE;
    strcpy(new_result + 1, original_result);

    // Release the memory for original result
    if(original_result != NULL)
        free(original_result);

    return new_result;
}