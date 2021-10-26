#include <stdio.h>
#include <stdlib.h>

int digitCount(int number) { // the chars the number would take (not including the null char)
    int i = 1;
    while(number >= 10){
        number /= 10;
        i++;
    }
    return i;
}

void printNumber(char* numberBuffer, int num, int maxChars) {
    sprintf(numberBuffer, "%d", num); 
    int whiteSpaceChars = maxChars - digitCount(num);
    while(whiteSpaceChars-- > 0) {
        putchar(' ');
    }
    printf("%s", numberBuffer);
}

int main() {
    int rows = 0;
    int columns = 0;

    int bufferSize = sizeof(char) * 32;
    char* buffer = (char*)malloc(bufferSize); // the cast is needed for a compiler

    printf("Input the number of columns: ");
    scanf("%s", buffer);
    if(sscanf(buffer, "%d", &columns) == 0) { 
        printf("Failed to parse number of columns, using default value: 5\n");
        columns = 5;
    }

    printf("Input the number of rows: ");
    scanf("%s", buffer);
    if(sscanf(buffer, "%d", &rows) == 0) {
        printf("Failed to parse number of rows, using default value: 5\n");
        rows = 5;
    }

    putchar('\n');


    int max = rows * columns;
    int digitsPerNumber = digitCount(max);
    int rowDigits = digitCount(rows);
    // check if the max number digits is bigger than the buffer
    if((digitsPerNumber + 1) * sizeof(char) > bufferSize) {
        bufferSize = (digitsPerNumber + 1) * sizeof(char); // digit count +1 for the null character
        char* temp = (char*)realloc(buffer, bufferSize);
        if(temp == NULL) { // memory reallocation failed
            free(buffer);
            printf("Failed to reallocate memory.");
            return -1;
        }
        buffer = temp;
    }
    
    // the columns line
    // " | n1  n2  n3 ..."
    putchar(' '); // extra space before row number
    for(int i = 0; i < rowDigits; i++) {  
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
    int d = rowDigits 
        + 1 + 2 // the space before the number and the " |"
        + (digitsPerNumber + 1) * columns
        + 1; // an extra "-"
    while(d-- > 0) {
        putchar('-');
    }
    
    putchar('\n');
    
    // y | x * y
    for(int j = 1; j <= rows; j++) {
        // " y |"
        putchar(' '); // space before the row number
        printNumber(buffer, j, rowDigits);
        putchar(' ');
        putchar('|');
        // x * y
        for(int i = 1; i <= columns; i++) {
            putchar(' ');
            printNumber(buffer, i * j, digitsPerNumber);
        }
        putchar('\n');
    }

    free(buffer);

    return 0;
}