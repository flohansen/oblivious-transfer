void OBTF_keygen(int* publicKey, int* secretKey, int* n);
int OBTF_generate_decision_cipher(int* x, int e, int n, int b, int* k);
void OBTF_generate_message_ciphers(int* messages, unsigned int messages_length, int v, int* x, int d, int n, int* ciphers);
int OBTF_obtain_message(int* message_ciphers, int b, int k);