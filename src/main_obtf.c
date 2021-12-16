#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crypto/obtf.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    int e, d, n;
    OBTF_keygen(&e, &d, &n);
    printf("Public key: %d\nSecret key: %d\nModulus: %d\n", e, d, n);
    printf("------------\n");

    // Choose two random messages.
    int x[2];
    for (unsigned int i = 0; i < 2; i++) {
        x[i] = rand() % n;
        printf("x_%d: %d\n", i, x[i]);
    }
    printf("------------\n");

    // Bob chooses a random bit now.
    int k;
    int b = rand() % 2;
    int v = OBTF_generate_decision_cipher(x, e, n, b, &k);
    printf("Bob chose bit b = %d and generated the decision cipher v = %d\n", b, v);
    printf("------------\n");

    // Alice generates the message ciphers.
    int m[2];
    for (unsigned int i = 0; i < 2; i++) {
        m[i] = rand() % n;
        printf("m_%d: %d\n", i, m[i]);
    }

    int m_prime[2];
    OBTF_generate_message_ciphers(m, 2, v, x, d, n, m_prime);

    for (unsigned int i = 0; i < 2; i++) {
        printf("m_%d': %d\n", i, m_prime[i]);
    }
    printf("------------\n");


    // Now Bob can obtain the message.
    int m_b = OBTF_obtain_message(m_prime, b, k);
    printf("The message Bob chose was m = %d\n", m_b);

    return 0;
}