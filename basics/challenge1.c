// Compile Cmd: gcc -g -o challenge1.o challenge1.c util.c
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char *expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    
    char *hex_decoded = decode_hex(hex);
    printf("Message: %s\n", hex_decoded);
    
    char *b64_encoded = encode_b64(hex_decoded);
    
    if (strcmp(b64_encoded, expected) == 0)
        printf("PASS\n");
    else
        printf("FAIL\n");
        
    free(hex_decoded);
    free(b64_encoded);
    
    return 0;
}