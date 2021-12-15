#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crypto/rsa.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    int pk, sk, n;
    RSA_keygen(&pk, &sk, &n);
    printf("Public key: %d\nSecret key: %d\nModulus: %d\n", pk, sk, n);
    printf("------------\n");

    // Choose random message.
    int message = rand() % n;
    printf("Random message: %d\n", message);

    // Encrypt the message.
    int cipher;
    RSA_encrypt(&message, &cipher, &pk, &n);
    printf("Encrypted message: %d\n", cipher);
    printf("------------\n");

    // Decrypt the message.
    int dec_message;
    RSA_decrypt(&cipher, &dec_message, &sk, &n);
    printf("Decrypted message: %d\n", dec_message);

    return 0;
}