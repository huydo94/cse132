/* 
 * manipFunctions.h
 * 
 * This header file declares all of the functions used to bit manipulate.
 *
 */

/* returns `1` if any bit in `num` is `1` */
int hasAOne(int num);

/* returns `1` if any bit in `num` is `0` */
int hasAZero(int num);

/* returns `1` if any bit of least-significant byte of `num` is `1` */
int leastSigHasAOne(int num);

/* returns `num`, but with the opposite sign.
   NOTE: this is assuming an `int`, but the program reads a long.
 */
int negate(int num);

/* returns `1` if `num` is negative, for different types: */
int isNegativeInt(int num);
int isNegativeLong(long num);
int isNegativeChar(char num);
