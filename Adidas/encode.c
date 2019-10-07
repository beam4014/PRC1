/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"
#include "encode.h"

#define HI_NIBBLE(b) (((b) >> 4) & 0x0F)
#define LO_NIBBLE(b) ((b) & 0x0F)

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
char addEvenParityToHex(char str){
    char d3 = str >> 3;
    char d2 = ((str&4) >> 2);
    char d1 = ((str&2) >> 1);
    char d0 = str&1;
    
    char p2 = d3 ^ d2 ^ d1 ;
    char p1 = d3 ^ d1 ^ d0 ;
    char p0 = d2 ^ d1 ^ d0;
    
    char result = (str<<3)|(p2<<2)|(p1<<1)|p0;
    return result;
}



