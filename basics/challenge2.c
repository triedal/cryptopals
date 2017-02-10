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
    int hex1_len = strnlen(hex1, 50);
    int hex2_len = strnlen(hex2, 50);
    int expected_len = strnlen(expected, 50);
    
    //Two hex values per byte of data
    char hex1_decoded[(hex1_len / 2) + 1];
    char hex2_decoded[(hex2_len / 2) + 1];
    char expected_decoded[(expected_len / 2) + 1];
    
    if (decode_hex(hex1, hex1_decoded, hex1_len) != 0) {
        printf("Invalid hex1 string length. Exiting.\n");
        exit(1);
    }
    
    if (decode_hex(hex2, hex2_decoded, hex2_len) != 0) {
        printf("Invalid hex2 string length. Exiting.\n");
        exit(1);
    }
    
    if (decode_hex(expected, expected_decoded, expected_len) != 0) {
        printf("Invalid expected hex string lenght. Exiting.\n");
        exit(1);
    }  
    
    char *xor_result = fixed_xor(hex1_decoded, hex2_decoded, strlen(expected_decoded));
    
    if (strcmp(xor_result, expected_decoded) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }        
}