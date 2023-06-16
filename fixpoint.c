#include "fixpoint.h"

void printFix(int32_t i) {
			// Prints a signed 16.16 fixed point number
			if ((i & 0x80000000) != 0) { // Handle negative numbers
				printf("-");
				i = ~i + 1;
			}
			printf("%ld.%04ld", i >> 16, 10000 * (uint32_t)(i & 0xFFFF) >> 16);
			// Print a maximum of 4 decimal digits to avoid overflow
		}

int32_t expand(int32_t i) {
	// Converts an 18.14 fixed point number to 16.16
	return i << 2;
}

int32_t sinus(int deg){
		return SIN[deg & 0x1FF]; //0x1FF i hex svarer til 0b111111111
}

int32_t cosinus(int deg){
	return SIN[deg + 128 & 0b111111111]; // cos(a) = sin(a+90grader), hvor 90 grader er lig 90/360*512 = 128 = 2^7
}
