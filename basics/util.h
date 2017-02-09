#ifndef UTIL_H
#define UTIL_H

char *fixed_xor(const char* str1, const char* str2, int length);

int htoi(const char* ptr);
char itob64(int val);

char *decode_hex(char *hex_str);
char *encode_b64(char *data);

#endif