#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h> 
 

//binary to decimal
int binary_to_decimal(char binary_string[]) { 
int counter = strlen(binary_string) - 1; 
int total = 0; 

for(int i = 0; binary_string[i] != '\0'; i++){
    char temp[2] = {binary_string[i], '\0' };
    total = total + (atoi(temp)) * (pow(2,counter)); 
    counter = counter - 1;
} 
return total; 
}

void decimal_to_binary(int n) {
    // Array to store binary digits
    //char binaryNum[33];
    int counter = 0;
    
    while (pow(2, counter) <= n) {
        counter++;
    }
    counter = counter - 1;

    int i = 0;
    char binaryNum[counter+1];
    while (counter >= 0) {
        int y = pow(2, counter);
        if (y <= n) {
            binaryNum[i] = '1';
            n = n - y;
        } else {
            binaryNum[i] = '0';
        }
        counter = counter - 1;
        i = i + 1;
    }
    binaryNum[counter] = '\0';  // Null-terminate the string

    printf("%s", binaryNum);
}

int main() {
    // // Test binary_to_decimal
    char binary_string[] = "1111";
    int decimal_value = binary_to_decimal(binary_string);
    printf("Binary: %s => Decimal: %d\n", binary_string, decimal_value);

    //Test decimal_to_binary
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary representation: ");
    decimal_to_binary(decimal);
    printf("\n");

    return 0;
}
