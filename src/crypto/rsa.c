#include <stdio.h>
#include <stdlib.h>
#include "rsa.h"
#include "../math/algorithms.h"

void RSA_keygen(int* publicKey, int* privateKey, int* n) {
    // Choose random primes p, q
    int p = rand();
    int q = rand();


    int modulus = p * q;
    int totient = ((p - 1) * (q - 1)) % modulus;

    int e = RSA_generate_random_public_key(totient); 
    int d = RSA_generate_random_secret_key(e, modulus);

    *n = modulus;
    *publicKey = e;
    *privateKey = d;
}

void RSA_encrypt(const int* message, const int* publicKey, const int* n) {

}

void RSA_decrypt(const int* cipher, const int* privateKey) {

}

int RSA_generate_random_public_key(int number) {
    printf("Searching for a random number, which is co-prime to %d...\n", number);
    int coprime = rand();

    while (gcd(number, coprime) != 1) {
        coprime = rand();
    }

    printf("Found co-prime: %d!\n", coprime);
    return coprime;
}

int RSA_generate_random_secret_key(int publicKey, int n) {
    int secret = rand();

    while (((secret * publicKey) % n) != 1) {
        secret = rand();
    }

    return secret;
}