/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: User
 *
 * Created on September 25, 2019, 11:05 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "parityValue.h"
#include "encode.h"


/*
 * 
 */
int main(void) {
printf ("PRC assignment 'Adidas'\n");
    int choice = -1;
    while (choice != 0)
    {
        char c = 'q';
        int i = (int)c;
        printf("%c \n",i);
        int FLIP_COUNT = 0;
        char msbParity = addEvenParityToHex(HI_NIBBLE(i));
        char lsbParity = addEvenParityToHex(LO_NIBBLE(i));
        printf("%c\n",msbParity);
        printf("%c\n",lsbParity);
        printf ("\nMENU\n====\n");
        printf ("1: ./encode \n");
        printf ("2: ./channel \n");
        printf("%c\n" ,randBitFlip(msbParity,&FLIP_COUNT));
        printf("Numbers of bit flip: %d\n", FLIP_COUNT);
        printf ("3: ./decode \n");
        printf ("0: quit \n");
             
        scanf ("%d", &choice);
//        switch (choice)
//        {
//        }
    }
    
    return (EXIT_SUCCESS);
}

