/* 
 * manipFunctions.c
 * 
 * This source file defines all the functions used to bit manipulate
 * by: Huy Do
 */

#include "manipFunctions.h"

int hasAOne(int num) {
  return num && 1;  //using num && 420 creates an error in Mac, but not at school computer
}

int hasAZero(int num) {
  return ~num && 1;
}

int leastSigHasAOne(int num) {
  return (num<<24) && 1;
}

int negate(int num) {
  return (~num)+1;
}

int isNegativeInt(int num) {
  return (num>>31)||0;
}

int isNegativeLong(long num) {
  return (num>>63)||0;
}

int isNegativeChar(char num) {
  return (num>>7)||0;
}
