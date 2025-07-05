#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

// Stack implementation for string reversal
typedef struct {                                            //typedefinition
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character for empty stack
    }
    return stack->data[stack->top--];
}

void reversestring(char* str) {
    int length = strlen(str);
    Stack stack;
    initialize(&stack);

    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}

// Function to convert decimal to binary and return as a string
char* decimalToBinary(int decimal) {
    Stack stack;
    initialize(&stack);
    while (decimal) {
        push(&stack, '0' + (decimal & 1));
        decimal >>= 1;
    }

    char* binary = (char*)malloc(33);
    if (binary == NULL) {
        return NULL;
    }
    int i = 0;
    while (!isEmpty(&stack)) {
        binary[i++] = pop(&stack);
    }
    binary[i] = '\0';
    return binary;
}

// Function to convert binary to decimal and return as an integer
int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

// Function to convert decimal to octal and return as a string
char* decimalToOctal(int decimal) {
    char* octal = (char*)malloc(12);
    if (octal == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    sprintf(octal, "%o", decimal);
    return octal;
}

// Function to convert octal to decimal and return as an integer
int octalToDecimal(char octal[]) {
    int decimal = 0;
    int length = strlen(octal);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 8 + (octal[i] - '0');
    }
    return decimal;
}

// Function to convert Decimal to hexadecimal using a stack

void decimalToHex(int decimalNum, char hexResult[]) {
    Stack stack;
    initialize(&stack);
    char hexChars[] = "0123456789ABCDEF";
    int remainder;
    int i = 0;

    if (decimalNum == 0) {
        hexResult[i++] = '0';
    } else {
        while (decimalNum > 0) {
            remainder = decimalNum % 16;
            push(&stack, hexChars[remainder]);
            decimalNum /= 16;
        }

        while (!isEmpty(&stack)) {
            hexResult[i++] = pop(&stack);
        }
    }

    hexResult[i] = '\0'; // Null-terminate the string
}
// Function to convert hexadecimal to decimal and return as a string
int hexToDecimal(char hexNum[]) {
    int decimalNum = 0;
    int power = 0;
    int i;
    int len = strlen(hexNum);

    for (i = len - 1; i >= 0; i--) {
        char c = hexNum[i]; // Directly access the character
        int value;

        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            return -1; // Invalid hexadecimal character
        }

        decimalNum += value * pow(16, power);
        power++;
    }

    return decimalNum;
}

// Function to convert binary to BCD
char* binaryToBCD(char binary[]) {
    int decimal = binaryToDecimal(binary);
    if (decimal == 0) return strdup("0000"); // Special case for 0

    char bcd[100] = "";
    char temp[5];
    char tempBCD[100] = "";

    int digits[10];
    int numDigits = 0;

    // Split decimal into digits
    while (decimal > 0) {
        digits[numDigits++] = decimal % 10;
        decimal /= 10;
    }

    // Process digits in reverse (most significant first)
    for (int i = numDigits - 1; i >= 0; i--) {
        int digit = digits[i];
        for (int j = 3; j >= 0; j--) {
            temp[3 - j] = ((digit >> j) & 1) + '0';
        }
        temp[4] = '\0';
        strcat(tempBCD, temp);
    }

    return strdup(tempBCD);
}
// Function to convert BCD to binary
char* BCDToBinary(char bcd[]) {
    int length = strlen(bcd);
    if (length % 4 != 0) {
        return strdup("Invalid BCD");
    }

    // char binary[100] = "";
    char temp[5];
    int decimal = 0;
    int power = 1;

    for (int i = length - 4; i >= 0; i -= 4) {
        strncpy(temp, bcd + i, 4);
        temp[4] = '\0';
        int digit = binaryToDecimal(temp);
        decimal = decimal + digit * power;
        power = power * 10;
    }

    return decimalToBinary(decimal);
}

// Function to convert binary to gray code
char* binaryToGray(char binary[]) {
    int length = strlen(binary);
    char* gray = (char*)malloc(length + 1); // +1 for null terminator
    if (gray == NULL) {
        return NULL; // Memory allocation failed
    }

    gray[0] = binary[0]; // MSB of gray code is same as MSB of binary

    for (int i = 1; i < length; i++) {
        gray[i] = ((binary[i - 1] - '0') ^ (binary[i] - '0')) + '0';
    }
    gray[length] = '\0'; // Null-terminate the string

    return gray;
}

// Function to convert gray code to binary
char* grayToBinary(char gray[]) {
    int length = strlen(gray);
    char* binary = (char*)malloc(length + 1); // +1 for null terminator
    if (binary == NULL) {
        return NULL; // Memory allocation failed
    }

    binary[0] = gray[0]; // MSB of binary is same as MSB of gray

    for (int i = 1; i < length; i++) {
        binary[i] = ((binary[i - 1] - '0') ^ (gray[i] - '0')) + '0';
    }
    binary[length] = '\0'; // Null-terminate the string

    return binary;
}

int main() {
    int choice;
    while (1) 
    {
        printf("-----------------THIS IS A BASE CONVERTER----------------------");
        printf("\n                        Menu:                   \n");
        printf("********Choose the conversion from the types********\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Decimal to hexadecimal\n");
        printf("6. Hexadecimal to decimal\n");
        printf("7. Binary to BCD\n");
        printf("8. BCD to Binary\n");
        printf("9. Binary to Gray\n");
        printf("10. Gray to Binary\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 11) {
            printf("Goodbye!\n");
            break;
        }

        char input[100]; // Buffer for user input
        char binaryInput[100];
        char grayInput[100];
        char* grayResult;
        char* binaryResult;
        char* result;
        int intResult;
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &intResult);
                    result = decimalToBinary(intResult);
                    if(result != NULL){
                        printf("Decimal to Binary: %s\n", result);
                        free(result);
                    }else{
                        printf("Memory allocation failure.\n");
                    }
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", input);
                intResult = binaryToDecimal(input);
                printf("Binary to Decimal: %d\n", intResult);
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &intResult);
                
                result = decimalToOctal(intResult);
                printf("Decimal to Octal: %s\n", result);
                free(result);
                break;
            case 4:
                printf("Enter an octal number: ");
                scanf("%s", input);
                intResult = octalToDecimal(input);
                printf("Octal to Decimal: %d\n", intResult);
                break;
            case 5:
            {
                int decimalNum;
                char hexResult[MAX_STACK_SIZE];
                printf("Enter decimal number: ");
                scanf("%d", &decimalNum);
                decimalToHex(decimalNum, hexResult);
                printf("Hexadecimal: %s\n", hexResult);
                break;
            }
            case 6:
            {
                char hexNum[MAX_STACK_SIZE];
                printf("Enter hexadecimal number: ");
                scanf("%s", hexNum);
                intResult = hexToDecimal(hexNum);
                printf("Decimal: %d\n", intResult);
                break;
            }
            case 7:
            printf("Enter a binary number: ");
            scanf("%s", input);
            result = binaryToBCD(input);
            if(result != NULL){
            printf("Binary to BCD: %s\n", result);
            free(result);
            }
            break;
            case 8:
                printf("Enter a BCD number: ");
                scanf("%s", input);
                result= BCDToBinary(input);
                if (result != NULL) {
                    printf("BCD to Binary: %s\n", result);
                    free(result);
                }
                break;
            case 9:
                // Binary to Gray conversion
                printf("Enter a binary number: ");
                scanf("%s", binaryInput);

                grayResult = binaryToGray(binaryInput);
                if (grayResult != NULL) {
                    printf("Gray code: %s\n", grayResult);
                    free(grayResult);
                } else {
                    printf("Memory allocation failed.\n");
                }
                break;
            case 10:
                printf("Enter a gray code number: ");
                scanf("%s", grayInput);

                binaryResult = grayToBinary(grayInput);
                if (binaryResult != NULL) {
                    printf("Binary code: %s\n", binaryResult);
                    free(binaryResult);
                } else {
                    printf("Memory allocation failed.\n");
                }
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
