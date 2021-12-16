#include <stdlib.h>
#include "obtf.h"
#include "rsa.h"

void OBTF_keygen(int* publicKey, int* secretKey, int* n) {
    RSA_keygen(publicKey, secretKey, n);
}

int OBTF_generate_decision_cipher(int* x, int e, int n, int b, int* k) {
    int message = x[b];
    *k = rand() % n;
    return message + RSA_fast_power(*k, e, n);
}

void OBTF_generate_message_ciphers(int* messages, unsigned int messages_length, int v, int* x, int d, int n, int* ciphers) {
    for (unsigned int i = 0; i < messages_length; i++) {
        int k_i = RSA_fast_power(v - x[i], d, n);
        ciphers[i] = messages[i] + k_i;
    }
}

int OBTF_obtain_message(int* message_ciphers, int b, int k) {
    return message_ciphers[b] - k;
}