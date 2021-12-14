void RSA_keygen(int* publicKey, int* privateKey, int* n);
void RSA_encrypt(const int* message, const int* publicKey, const int* n);
void RSA_decrypt(const int* cipher, const int* privateKey);
int RSA_generate_random_public_key(int number);
int RSA_generate_random_secret_key(int publicKey, int n);