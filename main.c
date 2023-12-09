#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TI_aes.h"

int main(int argc, char *argv[]) {
    unsigned char ikey[] = {0xa1, 0xa2, 0xa3, 0xb4, 0xa5, 0xa6, 0xa7, 0xa8, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8};

    // Reading the plain text from command line
    char *plain_text;

        printf("Enter the message to encrypt: ");
        // Memory allocation 1 MB = 2 * 1024 * 1024
	
        plain_text = (char *)malloc(2 * 1024 * 1024 * sizeof(char));
        fgets(plain_text,2*1024*1024, stdin);
        plain_text[strcspn(plain_text, "\n")] = '\0';
        int msg_len = strlen(plain_text);


    printf("Plain Text Before Encryption TXT  : '%s'\n", plain_text);
    printf("Plain Text Before Encryption HEX  : ");
    for (int j = 0; j < msg_len; j++)
        printf("0x%x ", plain_text[j]);

    // Encrypt the message
    aes_encrypt((unsigned char *)plain_text, ikey);

    // Print the cipher text
    printf("\nCipher Text After Encryption      : ");
    for (unsigned int j = 0; j < msg_len; j++)
        printf("0x%x ", plain_text[j]);

    // Decrypt the message
    aes_decrypt((unsigned char *)plain_text, ikey);

    // Print the decrypted text
    printf("\nPlain Text After Decryption       : '%s'\n", plain_text);
    printf("Plain Text After Decryption HEX   : ");
    for (unsigned int j = 0; j < msg_len; j++)
        printf("0x%x ", plain_text[j]);

    printf("\n");

    // Free dynamically allocated memory
    if (argc <= 1) {
        free(plain_text);
    }

    return 0;
}
