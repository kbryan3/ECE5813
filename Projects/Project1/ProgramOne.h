/********************************************************************
*
* @file ProgramOne.h
* @brief Functions to convert values to different binary formats
*
* @author Kyle Bryan
* @date September 13 2019
* version 1.0
*
***********************************************************************/

#ifndef __PROGRAMONE_H__
#define __PROGRAMONE_H__

#include <stdint.h>

/**
* @brief converts an integer value to an array of binary bits
*
* This function will return an array, whose sizes is depended on a given
* operand size, of binary bits that is equivalent to the inputted values
*
*@param value Value that will be converted to binary
*@param operandSize Number of bits to be represented in the binary array
*
*@return int* a pointer to an int(array) of binary bits
*/
int * toBinary(int value, int operandSize);

/**
* @brief Converts binary array to signed Ones Complement
*
* This function will print the signed ones complement bit string for a given
* binary array value.  IT also prints the maximum and minimum possible signed
* ones compement value depending on the operand size

*@param value Pointer to a binary value
*@param operandSize Number of bits to be represented in the binary array
*@param pos Whether or not initial value was positive or negative
*@param signedOverflow Whether or not initial value is too high for signed binary
*
*@return void
*/
void signedOnesComp(int *value, int operandSize, _Bool pos, _Bool signedOverflow);

/**
* @brief Converts binary array to signed twos Complement
*
* This function will print the signed twos complement bit string for a given
* binary array value.  It also prints the maximum and minimum possible signed
* twos compement value depending on the operand size
*
*@param value Pointer to a binary value
*@param operandSize Number of bits to be represented in the binary array
*@param pos Whether or not initial value was positive or negative
*@param signedOverflow Whether or not initial value is too high for signed binary
*
*@return void
*/
void signedTwosComp(int *value, int operandSize, _Bool pos, _Bool signedOverflow);

/**
* @brief Converts binary array to signed magnitude format
*
* This function will print the signed magnitude bit string for a given
* binary array value.  It also prints the maximum and minimum possible signed
* twos compement value depending on the operand size
*
*@param value Pointer to a binary value
*@param operandSize Number of bits to be represented in the binary array
*@param pos Whether or not initial value was positive or negative
*@param signedOverflow Whether or not initial value is too high for signed binary
*
*@return void
*/
void signedMagnitude(int *value, int operandSize, _Bool pos, _Bool signedOverflow);

#endif /* __PROGRAMONE_H__ */
