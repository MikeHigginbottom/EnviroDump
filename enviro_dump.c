#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include "debug.h"

int main(int argc, char *argv) {
	printf("EnviroDump\n");
	printf("==========\n");

	/* This may throw a compile-time error if the compiler range checks enum values (see K&R section 2.3) */
	enum bool { FALSE = 0, TRUE = 1 };
	enum bool veryTrue = 2;

	/* Attempt to change a const may throw a compile time error (see K&R section 2.4) */
	const int ci = 0;
	/* ci = 1; */

	/* Print the include file search paths */
	system("touch test.c");
	system("gcc -v -E test.c");
	system("rm test.c");

	/* Test arithmetic behaviour */
	int divResult = -5/3;
	printf("Negative integer division rounding (result of -5/3 as per MISRA:2004 Rule 3.3): %d ", divResult);
	if (divResult == -1)
		printf("(rounds towards zero)\n");
	else
		printf("(rounds away from zero)\n");

	int modResult = -3%2;
	printf("Negative integer modulus sign (result of -3%%2 as per K&R section 2.5): %d\n", modResult);

	/* Print ranges of types */
	printf("Min value for signed char: %d\n", SCHAR_MIN);
	printf("Max value for signed char: %d\n", SCHAR_MAX);
	printf("Max value for unsigned char: %d\n", UCHAR_MAX);
	#ifdef __CHAR_UNSIGNED__
		printf("Chars are unsigned by default\n");
	#else
		printf("Chars are signed by default\n");
	#endif
	printf("Min value for char: %d\n", CHAR_MIN);
	printf("Max value for char: %d\n", CHAR_MAX);

	printf("Min value for signed short int: %d\n", SHRT_MIN);
	printf("Max value for signed short int: %d\n", SHRT_MAX);
	printf("Max value for unsigned short int: %d\n", USHRT_MAX);

	printf("Min value for signed int: %d\n", INT_MIN);
	printf("Max value for signed int: %d\n", INT_MAX);
	printf("Max value for unsigned int: %u\n", UINT_MAX);


	printf("Wordsize: %d\n", __WORDSIZE);

	printf("Min value for signed long int: %ld\n", LONG_MIN);
	printf("Max value for signed long int: %ld\n", LONG_MAX);
	printf("Max value for unsigned long int: %lu\n", ULONG_MAX);

	#ifdef __USE_ISOC99
		printf("Using ISO C99 - long long type is available\n");
		printf("Min value for signed long long int: %lld\n", LLONG_MIN);
		printf("Max value for signed long long int: %lld\n", LLONG_MAX);
		printf("Max value for unsigned long long int: %llu\n", ULLONG_MAX);
	#endif

	printf("Min value for float: %f\n", FLT_MIN);
	printf("Max value for float: %f\n", FLT_MAX);

	printf("Min value for double: %lf\n", DBL_MIN);
	printf("Max value for double: %lf\n", DBL_MAX);

	printf("Min value for long double: %Lf\n", LDBL_MIN);
	printf("Max value for long double: %Lf\n", LDBL_MAX);

	/* Test type conversions */
	char c = 255;
	int i = c;
	printf("Char with high bit = 1, converted to int: %d\n", i);

	return 0;
}