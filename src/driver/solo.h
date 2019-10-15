
int solo_select(unsigned char* pk, unsigned char* path, unsigned int len);
int solo_sign(unsigned char* msg, int ilen, unsigned char* path, unsigned int plen, unsigned char* sign);
int solo_format();
int solo_generate(unsigned char* seed);
int solo_pubkey(unsigned char* pk, unsigned char* path, unsigned int plen);
int solo_import(unsigned char* seed, unsigned int ilen);