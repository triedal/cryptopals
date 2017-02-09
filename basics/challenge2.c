// Compile Cmd: gcc -g -o challenge2.o challenge2.c util.c
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *hex1 = "1c0111001f010100061a024b53535009181c";
    char *hex2 = "686974207468652062756c6c277320657965";
    char *expected = "746865206b696420646f6e277420706c6179";
    
    char *hex1_decoded = decode_hex(hex1);
    char *hex2_decoded = decode_hex(hex2);
    char *expected_decoded = decode_hex(expected);
    
    char *xor_result = fixed_xor(hex1_decoded, hex2_decoded, strlen(hex2_decoded));
    
    if (strcmp(xor_result, expected_decoded) == 0)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
    free(hex1_decoded);
    free(hex2_decoded);  
    free(expected_decoded);  
}