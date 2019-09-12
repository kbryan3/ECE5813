/**
*
* @file ProgramOne.c
* @brief Generates a table of values in different bases, based off a given input values
*
* @author Kyle Bryan
*
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * toBinary(int value, int radix, int operandSize);
void signedOnesComp(int *value, int operandSize, _Bool pos, _Bool signedOverflow);
void signedTwosComp(int *value, int operandSize, _Bool pos, _Bool signedOverflow);
void signedMagnitude(int *value, int operandSize, _Bool pos, _Bool signedOverflow);

int main (void)
{
    int input[33] = {-6, 10, 4, -6, 9, 4, -6, 10, 5, -9, 10, 8, 237, 10, 8,
                     0354, 8, 8, 0xEB, 16, 8, -125, 10, 8, 65400, 01, 8, 65400,
                     10, 16, -32701, 10, 16};
    _Bool positive = 0;
    int radix = 0;
    int value = 0;
    int operandSize = 0;
    int *pbinaryNum;
    int absValue = 0;
    int maxValue = 0;
    int pbinaryNumTemp[16];
    _Bool signedOverflow = 0;
    for(int k = 0; k<(sizeof(input)/sizeof(input[0])); k=k+3)
    {
      value = input[k];
      radix = input[(k+1)];
      operandSize = input[(k+2)];
      positive = (value > 0) ? 1 : 0;
      absValue = abs(value);
      maxValue = pow(2, operandSize)-1;
      if(positive)
      {
        signedOverflow = (absValue > maxValue/2) ? 1: 0;
      }
      else
      {
        signedOverflow = (absValue > (maxValue/2+1)) ? 1: 0;
      }
      if(radix == 8)
      {
        printf("Input: Value %o     Radix %d     OperandSize %d\n", value, radix, operandSize);
      }
      else if (radix == 16)
      {
        printf("Input: Value %#X     Radix %d     OperandSize %d\n", value, radix, operandSize);/* code */
      }
      else
      {
        printf("Input: Value %d     Radix %d     OperandSize %d\n", value, radix, operandSize);
      }
      if(radix != 8 && radix !=10 && radix !=16)
      {
        printf("Invalid Radix Value");
        printf("\n");
        printf("\n");
        continue;
      }
      if(operandSize != 4 && operandSize !=8 && operandSize != 16)
      {
        printf("Invalid Operand Size Value");
        printf("\n");
        printf("\n");
        continue;
      }
      printf("Output:                 Value        Maximum       Minimum\n");
      printf("Binary (abs)           0b");
      pbinaryNum = toBinary(absValue, radix, operandSize);
      printf("\n");
      printf("Octal (abs)             %#o             %#o         0", absValue, maxValue);
      printf("\n");
      printf("Decimal (abs)            %d             %d         0", absValue, maxValue);
      printf("\n");
      printf("Hexadecimal (abs)        %#X             %#X         0", absValue, maxValue);
      printf("\n");
      printf("Signed One's Complement   0b");
      signedOnesComp(pbinaryNum, operandSize, positive, signedOverflow);
      printf("\n");
      printf("Signed Two's Complement   0b");
      signedTwosComp(pbinaryNum, operandSize, positive, signedOverflow);
      printf("\n");
      printf("Signed Magnitude          0b");
      signedMagnitude(pbinaryNum, operandSize, positive, signedOverflow);
      printf("\n");
      printf("\n");
    }
}

//conversion to binary from https://www.geeksforgeeks.org/program-decimal-binary-conversion/
int * toBinary(int value, int radix, int operandSize)
{
    static int binaryValue[16];
    int temp =0;
    for(int i = 0; i < 16; i++)
    {
        binaryValue[i] = temp;
    }
    int n =0;
    while (value > 0)
    {
        // storing remainder in binary array
        binaryValue[n] = value % 2;
        value = value / 2;
        n++;
    }

    for(int i = operandSize-1; i >= 0; i--)
    {
        printf("%d",binaryValue[i]);
    }
    printf("   0b");
    for(int i = 0; i <operandSize; i++)
    {
      printf("1");
    }
    printf("  0b");
    for(int i = 0; i <operandSize; i++)
    {
      printf("0");
    }
    return binaryValue;
}

void signedOnesComp(int *value, int operandSize, _Bool pos, _Bool signedOverflow)
{
  if(signedOverflow)
  {
    printf("ERROR!!");
    printf("     ");
  }
  else
  {
    if(pos)
    {
      for(int i = operandSize-1; i >= 0; i--)
      {
          printf("%d",(value[i]));
      }
    }
    else
    {
      for(int i = operandSize-1; i >= 0; i--)
      {
          printf("%d",!(value[i]));
      }
    }
    printf("     ");
  }

// print maximum value
  for(int i = operandSize-1; i >= 0; i--)
  {
    if(i==(operandSize-1))
    {
      printf("0b0");
    }
    else
    {
      printf("1");
    }
  }
  printf("     ");
  // print minimum value
    for(int i = operandSize-1; i >= 0; i--)
    {
      if(i==(operandSize-1))
      {
        printf("0b1");
      }
      else
      {
        printf("0");
      }
    }
}

void signedTwosComp(int *value, int operandSize, _Bool pos, _Bool signedOverflow)
{
  int temp;
  int temp2;
  int flag = 0;
  int j = 0;
  if(signedOverflow)
  {
    printf("ERROR!!");
    printf("     ");
  }
  else
  {
    if(pos)
    {
      for(int i = operandSize-1; i >= 0; i--)
      {
          printf("%d",(value[i]));
      }
    }
    else
    {
      for(int i = 0; i<16; i++)
      {
        int temp = value[i];
        value[i] = !temp;
      }

      while(flag == 0)
      {
        temp2 = value[j];
        value[j] = !temp2;
        if(value[j] == 1)
        {
          flag = 1;
        }
        j++;
      }
      for(int i = operandSize-1; i >= 0; i--)
      {
          printf("%d",(value[i]));
      }
    }
    printf("     ");
  }

// print maximum value
  for(int i = operandSize-1; i >= 0; i--)
  {
    if(i==(operandSize-1))
    {
      printf("0b0");
    }
    else
    {
      printf("1");
    }
  }
  printf("     ");
  // print minimum value
    for(int i = operandSize-1; i >= 0; i--)
    {
      if(i==(operandSize-1))
      {
        printf("0b1");
      }
      else
      {
        printf("0");
      }
    }
}

void signedMagnitude(int *value, int operandSize, _Bool pos, _Bool signedOverflow)
{
  if(signedOverflow)
  {
    printf("ERROR!!");
    printf("     ");
  }
  else
  {
    if(pos)
    {
      for(int i = operandSize-1; i >= 0; i--)
      {
          printf("%d",(value[i]));
      }
    }
    else
    {
      for(int i = operandSize-1; i >= 0; i--)
      {
          if(i == (operandSize-1))
          {
            printf("1");
          }
          else
          {
            printf("%d",(value[i]));
          }

      }
    }
    printf("     ");
  }

// print maximum value
  for(int i = operandSize-1; i >= 0; i--)
  {
    if(i==(operandSize-1))
    {
      printf("0b0");
    }
    else
    {
      printf("1");
    }
  }
  printf("     0b");
  // print minimum value
  for(int i = operandSize-1; i >= 0; i--)
    {
        printf("1");
    }
}
