/*
 * manip.c
 *
 * Name: Huy Do
 * Email: huy.do@wustl.edu
 * Lab Partner:
 * Lab Section: CS132 Section B
 */

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "manipFunctions.h"

typedef enum {
  INT,
  LONG,
  CHAR
} type;

void usage(char* name) {
  printf("Welcome to manip!\n\n");

  printf("Usage:\n");
  printf("%s [arguments] num\n\n", name);

  printf("Arguments:\n");
  printf("\t-h\tPrint this help text\n");
  printf("\t-s shft\tShift the number you entered `shft` bits left\n");
  printf("\t-i\tTreat number as numinteger (default)\n");
  printf("\t-l\tTreat number as long\n");
  printf("\t-c\tTreat number as char\n");
}

int main(int argc, char **argv) {
  int shift = 0;
  type numType = 0;

  if(argc == 1) {
    printf("Congratulations! You have sucessfully compliled your program.\n");
    usage(argv[0]);

    return 0;
  }

  // Use `getopt()` to parse command-line arguments for us.
  // If `getopt()` returns `-1`, we have read all our arguments.
  char flag;
  while((flag = getopt(argc, argv, "hs:ilc")) != -1) {
    switch(flag) {
    case 'h':
      usage(argv[0]);
      break;
    case 's':
      shift = atoi(optarg);
      break;
    case 'i': 
      numType = INT;
      break; 
    case 'l': 
      numType = LONG;
      break;
    case 'c': 
      numType = CHAR;
      break;
    default:
      printf("Invalid argument.\n");
      return 0;
      break;
    }
  }

  // Warn user if they did not include a number.
  if(argv[optind] == NULL) {
    printf("Please include a number to manipulate.\n\n");
    printf("Like this:\n");
    printf("%s [arguments] number\n", argv[0]);
    return 0;
  }

  // TODO read num from argv[optind] and shift it appropriately.
  // Read number and shift, as appropriate.
  long num = strtol(argv[optind], NULL, 10);
  long shifted = num<<shift;

  printf("Number:  %li\t%#08lx\n", num, num);
  printf("as int:  %i\t%#08x\n", (int)num, (int)num);
  if(shift) {
    printf("Shifted: %li\t%#08lx\n", shifted, shifted);
  }
  printf("Treating number as %d (0: int; 1: long; 2: char)\n", numType);

  /* TODO uncomment the following lines until the next TODO */
   printf("Function        \tOutput\tHex\n");
   printf("hasAZero:       \t%d\t%#x\n", hasAZero(shifted), hasAZero(shifted));
   printf("hasAOne:        \t%d\t%#x\n", hasAOne(shifted), hasAOne(shifted));
   printf("leastSigHasAOne:\t%d\t%#x\n", 
     leastSigHasAOne(shifted), 
     leastSigHasAOne(shifted));
   printf("negate:         \t%d\t%#x\n", negate(shifted), negate(shifted));

   switch(numType) {
   case INT:
     printf("isNegativeInt:  \t%d\t%#x\n", 
       isNegativeInt(shifted),
       isNegativeInt(shifted));
     break;
   case LONG:
     printf("isNegativeLong: \t%d\t%#x\n", 
       isNegativeLong(shifted),
       isNegativeLong(shifted));
     break;
   case CHAR:
     printf("isNegativeChar: \t%d\t%#x\n", 
       isNegativeChar(shifted),
       isNegativeChar(shifted));
     break;
   }
   printf("\n");
  /* TODO uncomment everything above until the previous TODO */

  return 0;
}
