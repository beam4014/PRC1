/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>   
#include "string.h"
#include "decode.h"
#include "parityValue.h"
uint8_t errorCorrection(uint8_t strByte){
    
    uint8_t significantBits = (strByte & 120) >> 3; //get 
    uint8_t par = strByte & 7;
    
    uint8_t par2 = par >> 2;
    uint8_t par1 = (par & 2)>> 1;
    uint8_t par0 = par & 1;
    
    uint8_t d3 = significantBits >> 3;
    uint8_t d2 = ((significantBits&4) >> 2);
    uint8_t d1 = ((significantBits&2) >> 1);
    uint8_t d0 = significantBits&1;
    
    uint8_t expectp2 = d3 ^ d2 ^ d1 ;
    uint8_t expectp1 = d3 ^ d1 ^ d0 ;
    uint8_t expectp0 = d2 ^ d1 ^ d0;
    
    if(strByte&127 == 1){
        
        return strByte^= 128;//most front is flip
        
    }
    else if(par2 != expectp2 && par1 != expectp1){
        
        return strByte^= 64;//d3 is flip
        
    }
    else if(par2 != expectp2 && par0 != expectp0)
    {
        return strByte^= 32;//d2 is flip
        
    }
    else if(par1 != expectp1 && par0 != expectp0){
            
        return strByte^= 8;//d0 is flip
        
    }
    else if (par2 != expectp2 && par1 != expectp1 && par0 != expectp0){
        
        return strByte^= 16;//d1 is flip
        
    }    
    else if (par0 != expectp0){
        
        return strByte^= 1;//p0 is flip
        
    }
    else if(par1 != expectp1){
        
        return strByte^= 2;//p1 is flip
        
    }
    else if(par2 != expectp2){
        
        return strByte^= 4;//p2 is flip
        
    }
    else
    {
        return strByte;
    }
}
