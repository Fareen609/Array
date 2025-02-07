#include <stdio.h>

void convertToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }
    
    int binary[32]; 
    int index = 0;

    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }

    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void convertToOctal(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int octal[32]; 
    int index = 0;

    while (num > 0) {
        octal[index] = num % 8;
        num = num / 8;
        index++;
    }

    printf("Octal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n");
}

void convertToHexadecimal(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    char hexadecimal[32]; 
    int index = 0;

    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hexadecimal[index] = remainder + '0'; 
        } else {
            hexadecimal[index] = remainder - 10 + 'A'; 
        }
        num = num / 16;
        index++;
    }

    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    convertToBinary(decimal);
    convertToOctal(decimal);
    convertToHexadecimal(decimal);

    return 0;
}

