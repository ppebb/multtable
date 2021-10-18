#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int digitCount(int number) {
    return (int)( ceil(log10(number)) ) * sizeof(char); // the ammount of chars the number would take (not including the null char)
}

int printNumber(char* numberBuffer, int num, int maxChars) {
    sprintf(numberBuffer, "%d", num); 
    int whiteSpaceChars = maxChars - strlen(numberBuffer);
    while(whiteSpaceChars-- > 0) {
        putchar(' ');
    }
    printf(numberBuffer);
    return 0;
}

int main() {
    int rows = 0;
    int columns = 0;

    int bufferSize = sizeof(char) * 32;
    char* buffer = (char*)malloc(bufferSize); // the cast is needed for a compiler

    printf("Input number of columns: ");
    scanf("%s", buffer);
    if(sscanf(buffer, "%d", &columns) == 0) { 
        printf("Failed to parse number of columns, using default value: 5\n");
        columns = 5;
    }

    printf("Input number of rows: ");
    scanf("%s", buffer);
    if(sscanf(buffer, "%d", &rows) == 0) {
        printf("Failed to parse number of rows, using default value: 5\n");
        rows = 5;
    }

    putchar('\n');
    

    int max = rows * columns;
    int digitsPerNumber = digitCount(max);
    if((digitsPerNumber + 1) * sizeof(char) > bufferSize) {
        bufferSize = (digitsPerNumber + 1) * sizeof(char); // digit count +1 for the null character
        char* temp = (char*)realloc(buffer, bufferSize);
        if(temp == NULL) { // memory reallocation failed
            free(buffer);
            printf("Failed to reallocate memory.");
            return -1;
        }
    }
    
    // the columns line
    // " | n1  n2  n3 ..."
    for(int i = 0; i < digitsPerNumber; i++) {
        putchar(' ');
    }
    putchar(' ');
    putchar('|');
    for(int i = 1; i <= columns; i++) {
        putchar(' ');
        printNumber(buffer, i, digitsPerNumber);
    }
    putchar('\n');

    // --------------------------------------------
    int d = digitsPerNumber 
        + sizeof(char) * 2 // " |"
        + (digitsPerNumber + 1) * columns;
    while(d-- > 0) {
        putchar('-');
    }
    
    putchar('\n');
    
    // y | x * y
    for(int j = 1; j <= rows; j++) {
        printNumber(buffer, j, digitsPerNumber);
        putchar(' ');
        putchar('|');
        for(int i = 1; i <= columns; i++) {
            putchar(' ');
            printNumber(buffer, i * j, digitsPerNumber);
        }
        putchar('\n');
    }

    free(buffer);
    return 0;
}