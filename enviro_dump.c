#include "debug.h"

enum bool { FALSE = 0, TRUE = 1 };
enum bool veryTrue = 2; /* This may throw a compile-time error if the compiler range checks enum values (see K&R section 2.3) */

int main(int argc, char *argv) {
	printf("EnviroDump\n");
	printf("==========\n");
	printf("Integer division rounding (result of -5/3 as per MISRA:2004 Rule 3.3): %d\n", -5/3);
	return 0;
}