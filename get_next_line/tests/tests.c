#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../src/get_next_line.h"

#define TEST(path) {\
   	int fd = open(path, O_RDONLY); \
    int line_count = 1;            \
	for (int i = 0; i < line_count; i++) \
    {               \
		char *line = get_next_line(fd);   \
		if (line) printf("Line %d: %s", i, line);  \
    	if (line) free(line);                \
	}                \
}

int main() {
	// disable stdout buffering
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("=== TESTS | BUFFER_SIZE=%d ===\n", BUFFER_SIZE);
//	TEST("tests/test1.txt");
//	TEST("tests/test2.txt");
//	TEST("tests/test3.txt");
//	TEST("tests/41_no_nl");
	TEST("tests/simple.txt");
//	TEST("tests/41_with_nl");
//	get_next_line(1000);
//	get_next_line(0);

    return 0;
}
