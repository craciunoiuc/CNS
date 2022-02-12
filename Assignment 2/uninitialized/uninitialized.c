
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int verify_idx(char *buf, char *str)
{
	int n; // need to overwrite with strlen(buf) == 19

	return strncmp(buf, str, strlen(buf + n)) == 0;
}

int verify(char *str)
{
	char buf[2048] = "Where is the flag?";

	return verify_idx(buf, str);
}

void foo()
{
	char buf[1024];
	char num[8];
	int n;

	// Read offset (offset on the stack to overwrite n@verify_idx)
	fgets(num, 6, stdin);
	n = atoi(num);

	// Read data into n@verify_idx (at -2148)
	if (fgets(buf + n, 16, stdin) == NULL) {
		perror("fgets");
		exit(EXIT_FAILURE);
	}

	if (verify(buf)) {
		FILE *f = fopen("/home/ctf/flag", "r");
		char flag[32];

		fscanf(f, "%s", flag);
		printf("%s\n", flag);
		fclose(f);
	}
}

int main(void)
{
	foo();

	return 0;
}
