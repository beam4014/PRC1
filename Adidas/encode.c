/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>   
#include "string.h"
#include "encode.h"
#include "parityValue.h"
FILE *fp;
FILE readTxtFile(char inputFileName[], char outputFileName[]){
    fp = fopen(inputFileName,"r");
    if(fp == NULL)
    {
        printf("error opening file %s", inputFileName);
    }
//    while(reading the file)
    return *fp;
}
uint8_t addEvenParityToHex(uint8_t str){
    uint8_t d3 = str >> 3;
    uint8_t d2 = ((str&4) >> 2);
    uint8_t d1 = ((str&2) >> 1);
    uint8_t d0 = str&1;
    
    uint8_t p2 = d3 ^ d2 ^ d1 ;
    uint8_t p1 = d3 ^ d1 ^ d0 ;
    uint8_t p0 = d2 ^ d1 ^ d0;
    
    uint8_t result = (str<<3)|(p2<<2)|(p1<<1)|p0;
    uint8_t final = result;
    return final;
}
uint8_t randBitFlip(uint8_t str,int *count){
    /* Intialize random number generator */
    //random bit after add parity
    int mask;
    srand(time(NULL)); 
    for(int i = 0; i<5; i++) 
    mask =  pow(2, rand()% 8);
    str ^= mask;
    *count = *count+1;
    return str;
}



