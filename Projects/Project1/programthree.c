/**
*
* @file programthree.c
* @brief Performs bit manipulation on a given input
*
* Given 0xCAFE 3 bit manipulations will be done and tested
*   1) Reverse byte order
*   2) Rotate value by four bits to the left
*   3) Rotate value by 8 bits to the right
* The results will also be printed after each manipulation
*
* The binary conversion algorithm in the toBinaryAndTest function was leveraged
* from: https://www.geeksforgeeks.org/program-decimal-binary-conversion/
*
* @author Kyle Bryan
* @date September 13 2019
* version 1.0
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "programthree.h"


int main (void)
{
  int value = 0xCAFE;

  printf("Original input in hexadecimal is: %#X\n\n", value);
  printf("First Test: ");
  toBinaryAndTest(value);
  //reverse byte order
  value = ((value & 0x00FF) << 8) | ((value & 0xFF00) >> 8);
  printf("Value after reversing byte order: %#X\n\n", value);
  printf("Second Test: ");
  toBinaryAndTest(value);
  //shift by 4 bits to the left
  value = ((value & 0x0FFF) << 4) | ((value & 0xF000) >> 12);
  printf("Value after shifting left by 4: %#X\n\n", value);
  printf("Third Test: ");
  toBinaryAndTest(value);
  //shift by 8 bits to the right
  value = ((value & 0x00FF) << 8) | ((value & 0xFF00) >> 8);
  printf("Value after rotating right by 8: %#X\n\n", value);
  printf("Fourth Test: ");
  toBinaryAndTest(value);
  printf("%ld",sizeof(int));
}

void toBinaryAndTest(int value)
{
    static int binaryValue[16];
    int temp =0;
    int testCount = 0;
    _Bool testPass = 0;
    //Test if 3 of last 4 bits are on
    if(value&0x0001)
    {
      testCount++;
    }
    if(value&0x0002)
    {
      testCount++;
    }
    if(value&0x0004)
    {
      testCount++;
    }
    if(value&0x0008)
    {
      testCount++;
    }
    if(testCount == 3)
    {
      testPass = 1;
    }
    else
    {
      testPass = 0;
    }
    //clear the array
    for(int i = 0; i < 16; i++)
    {
        binaryValue[i] = temp;
    }
    int n =0;
    //this while loop was taken from the "geeksforgeeks.org source"
    while (value > 0)
    {
        // storing remainder in binary array
        binaryValue[n] = value % 2;
        value = value / 2;
        n++;
    }
    for(int i = 15; i >= 0; i--)
    {
        printf("%d",binaryValue[i]);
    }
    //print test result
    if(testPass)
    {
      printf(" TRUE\n\n");
    }
    else
    {
      printf(" FALSE\n\n");
    }
  }
