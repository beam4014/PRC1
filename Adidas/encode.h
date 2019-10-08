#ifndef ENCODE_H
#define ENCODE_H

FILE readTxtFile(char inputFileName[], char outputFileName[]);
uint8_t addEvenParityToHex(uint8_t str);
uint8_t randBitFlip(uint8_t str,int *count);


#endif /* ENCODE_H */

