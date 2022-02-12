#include <stdio.h>
#include <inttypes.h>

char *string_xor_with_key(char *string, int len, int key)
{
	for (int i = 0; i < len; ++i) {
		string[i] ^= key;
	}

	return string;
}

int64_t array_sum(int *array, int len)
{
	int sum = 0;

	for (int i = 0; i < len; ++i) {
		sum += array[i];		
	}

	return sum;
}

