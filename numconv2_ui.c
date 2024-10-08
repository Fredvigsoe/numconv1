#include <stdio.h>
#include "numconv2.h"  

void print_menu() {
    printf("Vælg et talsystem:\n");
    printf("1. Decimal\n");
    printf("2. Binær\n");
    printf("3. Hexadecimal\n");
    printf("4. Octal\n");
    printf("Indtast valg: ");
}

int main() {
    char input[100];
    int num;
    char output[100];

    print_menu();
    int choice;
    scanf("%d", &choice);

    printf("Indtast tal: ");
    scanf("%s", input);

    switch (choice) {
        case 1:  // Decimal
            num = dec_to_int(input);
            break;
        case 2:  // Binær
            num = bin_to_int(input);
            break;
        case 3:  // Hexadecimal
            num = hex_to_int(input);
            break;
        case 4:  // Octal
            num = oct_to_int(input);
            break;
        default:
            printf("Ugyldigt valg!\n");
            return 1;
    }

    // Kalder alle konverteringsfunktioner og udskriver dem
    int_to_dec(num, output);
    printf("Decimal: %s\n", output);
    
    int_to_bin(num, output);
    printf("Binær: %s\n", output);
    
    int_to_hex(num, output);
    printf("Hexadecimal: %s\n", output);
    
    int_to_oct(num, output);
    printf("Octal: %s\n", output);

    return 0;  
}
