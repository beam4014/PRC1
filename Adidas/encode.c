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
    
    char result;
    char p2 = (str >> 1)^0x00 ;
    if (p2 > 0 ){
        p2 = 1;
    }
    char p1 = (((str& 0x08)>>1)|(str&0x03)) ^ 0;
    if (p1 > 0 ){
        p1 = 1;
    }
    char p0 = (str & 0x07)^ 0;
    if (p0 > 0 ){
        p0 = 1;
    }
    
    result = (str<<3)|(p2<<2)|(p1<<1)|p0;
//    p2 is d3 d2 d1  >>1          0 1 0  ^0  then <<2
//p1 is d3 d1 d0  (&8)>>1|(&3) 0 0 0  ^0  then <<1
//p0 is d2 d1 d0  & 7          1 0 0  ^0  
    return result;
}



