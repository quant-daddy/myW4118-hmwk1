#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	while (1) {
		printf("$");
		read = getline(&line, &len, stdin);
	}
	free(line);
	return 0;
}