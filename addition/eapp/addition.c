#include "eapp_utils.h"
#include "edge_call.h"
#include <syscall.h>

#define OCALL_PRINT_STRING 1
unsigned long ocall_print_string(char* str);


char* itoa(int value, char* str, int base);  // Déclaration de itoa
char* strcat_custom(char* dest, const char* src);  // Déclaration de strcat_custom

int main() {
    int a = 2, b = 3;
    int somme = a + b;

    char message[50];
    char num_str[10];

    strcat_custom(message, "la somme de ");  // Ajouter " la somme de " à message

    itoa(a, num_str, 10);  // Convertir 'a' en chaîne
    strcat_custom(message, num_str);  // Ajouter 'a' à message
    
    strcat_custom(message, " et ");  // Ajouter " et "
    
    itoa(b, num_str, 10);  // Convertir 'b' en chaîne
    strcat_custom(message, num_str);  // Ajouter 'b' à message
    
    strcat_custom(message, " est : ");  // Ajouter " est : "
    
    itoa(somme, num_str, 10);  // Convertir 'somme' en chaîne
    strcat_custom(message, num_str);  // Ajouter la somme à message
    
    // Appeler l'ocall pour afficher le message
    ocall_print_string(message);

    EAPP_RETURN(0);
}

unsigned long ocall_print_string(char* str) {
    unsigned long retval;
    ocall(OCALL_PRINT_STRING, str, strlen(str) + 1, &retval, sizeof(unsigned long));
    return retval;
}


char* itoa(int value, char* str, int base) {
    int i = 0;
    int isNegative = 0;

    if (value == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (value < 0 && base == 10) {
        isNegative = 1;
        value = -value;
    }

    while (value != 0) {
        int rem = value % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        value = value / base;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return str;
}

char* strcat_custom(char* dest, const char* src) {
    char* ptr = dest + strlen(dest);
    while (*src) {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
