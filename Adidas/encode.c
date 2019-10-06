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



