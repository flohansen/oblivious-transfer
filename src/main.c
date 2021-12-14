#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crypto/rsa.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    int pk, sk, n;
    RSA_keygen(&pk, &sk, &n);

    printf("Public key: %d\nSecret key: %d\n Modulus: %d\n", pk, sk, n);
    return 0;
}