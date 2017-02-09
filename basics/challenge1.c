// Compile Cmd: gcc -g -o challenge1.o challenge1.c util.c
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char *expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    int hex_len = strnlen(hex, 100);
    
    // Two hex values per byte of data
    char hex_decoded[(hex_len / 2) + 1];
    // 4 chars represent 3 bytes of data
    int b64_len = (4 * (hex_len / 2) / 3) + 1;
    char b64_encoded[b64_len]; 
    
    if (decode_hex(hex, hex_decoded, hex_len) == 0) {
        printf("Message: %s\n", hex_decoded);
    } else {
        printf("Invalid hex string length. Exiting.\n");
        exit(1);
    }    
    
    encode_b64(hex_decoded, b64_encoded, b64_len);
    
    if (strcmp(b64_encoded, expected) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }        
    
    return 0;
}