/**
*
* @file programtwo.c
* @brief Outputs how a value maps to ASCII
*
* Given an array of integer values this program displays the character type as
* well as the character value for each of the array values.
* Note that Control characters are also considered white space in this program
*
* @author Kyle Bryan
* @date September 13 2019
* version 1.0
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main (void)
{
  int input[20] = {66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};
  char *type[] = {"Lower Case", "Upper Case", "Digit", "White Space",
                  "Special Character", "Unknown Character"};
  int code = 0;
  int typeIndex;

  for(int i = 0; i<(sizeof(input)/sizeof(input[0])); i++)
  {
    code = input[i];

    //decide character type
    if(islower(code) != 0)
    {
      typeIndex = 0;
    }
    else if(isupper(code) != 0)
    {
      typeIndex = 1;
    }
    else if(isdigit(code) != 0)
    {
      typeIndex = 2;
    }
    else if((isspace(code) != 0) || (iscntrl(code) != 0) )
    {
      typeIndex = 3;
    }
    else if(ispunct(code) != 0)
    {
      typeIndex = 4;
    }
    else
    {
      typeIndex = 5;
    }

    //print the character type
    printf("Code:%d     Type:%s  ASCII Char:%c\n\n",code, type[typeIndex], code);
  }
}
