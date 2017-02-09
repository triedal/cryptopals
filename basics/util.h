#ifndef UTIL_H
#define UTIL_H

char *fixed_xor(const char* str1, const char* str2, int length);

int htoi(const char* ptr);
char itob64(int val);

int decode_hex(char *hex_str, char *hex_decoded, int length);
void encode_b64(char *data, char *b64_encoded, int length);

#endif