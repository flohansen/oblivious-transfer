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

void RSA_encrypt(const int* message, const int* cipher, const int* publicKey, const int* n) {

}

void RSA_decrypt(const int* cipher, const int* message, const int* privateKey) {

}

int RSA_generate_random_public_key(int totient) {
    int coprime;

    do {
        coprime = rand();
    } while (gcd(totient, coprime) != 1);

    return coprime;
}

int RSA_generate_random_secret_key(int publicKey, int n) {
    int secret;

    do {
        secret = rand();
    } while (((secret * publicKey) % n) != 1);

    return secret;
}

int RSA_miller_test(int d, int n) {
    int a = 2 + rand() % (n - 4); 
    int x = RSA_fast_power(a, d, n); // a^d mod n

    if (x == 1 || x == n-1)
        return 1;

    while (d != n-1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return 0;
        else if (x == n-1) return 1;
    }

    return 0;
}

int RSA_is_prime(int n, int k) {
    // Find d such that n = 2^r * d + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!RSA_miller_test(d, n))
            return 0;

    return 1;
}

int RSA_fast_power(int x, unsigned int y, int p) {
    // Initialize the result
    int res = 1;

    // Make sure x is modulus p
    x = x % p;

    while (y > 0) {
        // If y is odd, multiply x with the result
        if (y % 2 != 0)
            res = (res * x) % p;

        // Now y must be even
        y = y / 2;
        x = (x*x) % p;
    }

    return res;
}