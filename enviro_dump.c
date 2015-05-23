#include "debug.h"

int main(int argc, char *argv) {
	printf("EnviroDump\n");
	printf("==========\n");
	printf("Integer division rounding (result of -5/3 as per MISRA:2004 Rule 3.3): %d\n", -5/3);
	return 0;
}