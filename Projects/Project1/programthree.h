/********************************************************************
*
* @file programthree.h
* @brief This program does bitwise operations on a given value and tests
*          the results
*
* @author Kyle Bryan
* @date September 13 2019
* version 1.0
*
***********************************************************************/

#ifndef __PROGRAMTHREE_H__
#define __PROGRAMTHREE_H__

#include <stdint.h>

/**
* @brief prints the binary of an integer value and tests last 4 bits
*
* This function takes in an integer value and prints out its value in binary
* as well as tests whether the binary value has 3 out of 4 of its last 4 bits
* being 1s
*
*@param value Value that will be converted to binary and tested
*
*@return void
*/
void toBinaryAndTest(int value);

#endif /* __PROGRAMTHREE_H__ */
