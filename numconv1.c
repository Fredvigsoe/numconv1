#include <stdio.h>
#include "numconv1.h"

// Hjælpefunktioner
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_bin_digit(char c) {
    return c == '0' || c == '1';
}

int is_oct_digit(char c) {
    return c >= '0' && c <= '7';
}

int is_hex_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

// Konverter hex-tegn til integer værdi
int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

// Funktion til at konvertere decimal-streng til integer
int dec_to_int(char str[]) {
    int sign = 1, i = 0;
    if (str[0] == '-') {  // Tjek for negativt fortegn
        sign = -1;
        i = 1;
    }
    int result = 0;
    for (; str[i] != '\0'; i++) {
        if (!is_digit(str[i])) return 0;  // Ugyldigt input
        result = result * 10 + (str[i] - '0');
    }
    return sign * result;
}

// Funktion til at konvertere binær-streng til integer
int bin_to_int(char str[]) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_bin_digit(str[i])) return 0;  // Ugyldigt input
        result = result * 2 + (str[i] - '0');
    }
    return result;
}

// Funktion til at konvertere octal-streng til integer
int oct_to_int(char str[]) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_oct_digit(str[i])) return 0;  // Ugyldigt input
        result = result * 8 + (str[i] - '0');
    }
    return result;
}

// Funktion til at konvertere hexadecimal-streng til integer
int hex_to_int(char str[]) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_hex_digit(str[i])) return 0;  // Ugyldigt input
        result = result * 16 + hex_char_to_int(str[i]);
    }
    return result;
}

// Funktion til at konvertere integer til decimal-streng
void int_to_dec(int num, char str[]) {
    int i = 0;
    int is_negative = 0;
    
    // Håndter negativt tal
    if (num < 0) {
        is_negative = 1;
        num = -num;  // Gør tallet positivt for at arbejde med det
    }

    // Konverter tallet til en streng
    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    // Tilføj minus-tegn hvis negativt
    if (is_negative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    // Vend strengen om (reverse)
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

// Funktion til at konvertere integer til binær-streng
void int_to_bin(int num, char str[]) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num > 0) {
            str[i++] = (num % 2) + '0';
            num /= 2;
        }
    }
    str[i] = '\0';

    // Vend strengen om (reverse)
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

// Funktion til at konvertere integer til octal-streng
void int_to_oct(int num, char str[]) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num > 0) {
            str[i++] = (num % 8) + '0';
            num /= 8;
        }
    }
    str[i] = '\0';

    // Vend strengen om (reverse)
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

// Funktion til at konvertere integer til hexadecimal-streng
void int_to_hex(int num, char str[]) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num > 0) {
            int remainder = num % 16;
            if (remainder < 10) {
                str[i++] = remainder + '0';
            } else {
                str[i++] = (remainder - 10) + 'a';  // Brug små bogstaver
            }
            num /= 16;
        }
    }
    str[i] = '\0';

    // Vend strengen om (reverse)
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}