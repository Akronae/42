#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../src/get_next_line.h"

#define TEST(path) {\
   	int fd = open(path, O_RDONLY); \
    int line_count = 13;            \
	for (int i = 0; i < line_count; i++) \
    {               \
		char *line = get_next_line(fd);   \
		printf("Line %d: %s", i, line);  \
    	if (line) free(line);                \
	}                \
}

int main() {
	// disable stdout buffering
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("=== TESTS | BUFFER_SIZE=%d ===\n", BUFFER_SIZE);
	TEST("tests/test1.txt");

    return 0;
}
