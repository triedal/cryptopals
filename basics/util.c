#include "util.h"
#include <string.h>
#include <stdlib.h>

char *fixed_xor(const char* str1, const char* str2, int length)
{
    char *result = (char *)malloc(length * sizeof(char));
    
    for (int i=0; i < length; i++) {
        result[i] = str1[i] ^ str2[i];
    }
    return result;
}

int htoi(const char* ptr)
{
    int value = 0;
    char val = *ptr;

    while (val == ' ' || val == '\t')
        val = *(++ptr);

    for (;;) {
        if (val >= '0' && val <= '9')
            value = (value << 4) + (val - '0');
        else if (val >= 'A' && val <= 'F')
            value = (value << 4) + (val - 'A' + 10);
        else if (val >= 'a' && val <= 'f')
            value = (value << 4) + (val - 'a' + 10);
        else
            return value;
        val = *(++ptr);
    }
}

char itob64(int val)
{
    char b64;
    
    // A-Z
    if (val >= 0 && val <= 25)
        b64 = (char) (val + 'A');
    // a-z    
    else if (val >= 26 && val <= 51)
        b64 = (char) (val + 71);
    // 0-9    
    else if (val >= 52 && val <= 61)
        b64 = (char) (val - 4);
    else if (val == 62)
        b64 = '+';
    else if (val == 63)
        b64 = '/';
    // nul
    else
        b64 = (char) (0);
    
    return b64;
}

char *decode_hex(char *hex_str)
{
    int hex_str_len = strlen(hex_str);
    // Two hex values to byte of data
    char *decoded = (char *)malloc((hex_str_len / 2) * sizeof(char));
    
    char *ch = hex_str;

    for (int i=0; i < hex_str_len / 2; i++) {
        int val = 0;
        char hex_buf[3];
        
        // Copy two hex values into buffer
        strncpy(hex_buf, ch, 2);
        hex_buf[2] = '\0';
        
        val = htoi(hex_buf);
        decoded[i] = val;
        ch += 2;
    }
    
    return decoded;
}

char *encode_b64(char *data)
{
    // 4 chars represent 3 bytes
    int data_length = strlen(data);
    int encoded_buf_length = (4 * strlen(data) / 3) + 1;
    char *encoded = (char *)malloc(encoded_buf_length * sizeof(char));
    encoded[encoded_buf_length] = '\0';
    
    for (int i=0; i < data_length / 3; i++) {
        int bytes = 0;
        bytes += data[3 * i] << 16;
        bytes += data[3 * i + 1] << 8;
        bytes += data[3 * i + 2];
        encoded[4 * i] = itob64(bytes >> 18);
        encoded[4 * i + 1] = itob64(bytes >> 12 & 63);
        encoded[4 * i + 2] = itob64(bytes >> 6 & 63);
        encoded[4 * i + 3] = itob64(bytes & 63);
    }
    
    return encoded;
}