#include <stdio.h>
#include "numconv2.h"

// Konverterer decimal-streng til integer
int dec_to_int(char *str) {
    int value = 0;
    int isNegative = 0;

    if (*str == '-') {
        str++;
        isNegative = 1;
    }

    while (is_digit(*str)) {
        value *= 10;
        value += *str - '0';
        str++;
    }

    if (isNegative == 1) {
        value *= -1;
    }

    return value;
}

// Konverterer integer til decimal-streng
void int_to_dec(int num, char *str) {
    int remain = num;
    char *start = str;

    if (num == 0) {
        *str++ = '0';
    } 
        else if (num < 0) {
         *str++ = '-';
         remain = -remain;
    }

    do {
        int digit = remain % 10;
        *str++ = digit + '0';
        remain /= 10;
    } while (remain > 0);

    *str = '\0';
    reverse_string(start, str);
}

// Konverterer binær-streng til integer
int bin_to_int(char *str) {
    int value = 0;

    while (is_bin_digit(*str)) {
        value <<= 1; // Shifter 1 bit til venstre
        value |= (*str - '0'); // Tilføjer binære værdier ved brug af OR
        str++;
    }

    return value;
}

// Konverterer integer til binær-streng
void int_to_bin(int num, char *str) {
    int remain = num;
    char *start = str;

    if (num == 0) {
        *str++ = '0';
    }

    while (remain > 0) {
        int digit = remain & 0b1; // Få den første bit
        *str++ = digit + '0';     // Konverter til '0' eller '1'
        remain >>= 1;             // Shifter 1 bit til højre
    }

    *str = '\0';
    reverse_string(start, str);
}

// Konverterer hexadecimal-streng til integer
int hex_to_int(char *str) {
    int value = 0;

    while (is_hex_digit(*str)) {
        value <<= 4; // Shifter 4 bits til venstre
        char c = *str;

        if (c > '9') {  // Hvis det er et bogstav
            c -= 7;     // Juster ASCII-værdien (A-F)
        }

        value += c & 0b1111; // Tilføjer værdien (0-15)
        str++;
    }

    return value;
}

// Konverterer integer til hexadecimal-streng
void int_to_hex(int num, char *str) {
    int remain = num;
    char *start = str;

    if (num == 0) {
        *str++ = '0';
    }

    while (remain > 0) {
        int digit = remain & 0xF; // Få de første fire bits
        if (digit < 10) {
            *str++ = digit + '0';   // Konverter til '0'-'9'
        } else {
            *str++ = digit - 10 + 'A'; // Konverter til 'A'-'F'
        }
        remain >>= 4; // Shifter 4 bits til højre
    }

    *str = '\0';
    reverse_string(start, str);
}

// Konverterer oktal-streng til integer
int oct_to_int(char *str) {
    int value = 0;

    while (is_oct_digit(*str)) {
        value <<= 3; // Shifter 3 bits til venstre
        value += *str - '0'; // Tilføjer oktal ciffer
        str++;
    }

    return value;
}

// Konverterer integer til oktal-streng
void int_to_oct(int num, char *str) {
    int remain = num;
    char *start = str;

    if (num == 0) {
        *str++ = '0';
    }

    while (remain > 0) {
        int digit = remain & 0b111; // Få de første tre bits
        *str++ = digit + '0'; // Konverter til '0'-'7'
        remain >>= 3; // Shifter 3 bits til højre
    }

    *str = '\0';
    reverse_string(start, str);
}

// Hjælpefunktion til at validere decimaltal
int is_digit(char c) {
    return (c >= '0' && c <= '9') ? 1 : 0;
}

// Hjælpefunktion til at validere binære tal
int is_bin_digit(char c) {
    return (c == '0' || c == '1') ? 1 : 0;
}

// Hjælpefunktion til at validere hexadecimale tal
int is_hex_digit(char c) {
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) ? 1 : 0;
}

// Hjælpefunktion til at validere oktale tal
int is_oct_digit(char c) {
    return (c >= '0' && c <= '7') ? 1 : 0;
}

// Hjælpefunktion til at vende en streng
void reverse_string(char *startPos, char *str) {
    int len = str - startPos;
    for (int i = 0; i < len / 2; i++) {
        char temp = startPos[i];
        startPos[i] = startPos[len - i - 1];
        startPos[len - i - 1] = temp;
    }
}


