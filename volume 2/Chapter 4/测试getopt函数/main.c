#include <stdio.h>
#include <unistd.h>

int main(int argc, char * const argv[]) {
	int opt;
	while ((opt=getopt(argc, argv, "ab:c::")) != -1) {
		switch (opt) {
			case 'a' : printf("no argument\n"); break;
			case 'b' : printf("one argument\n"); break;
			case 'c' : printf("optional\n"); break;
			case '?' : printf("invalid option %c\n", optopt); break;
			case ':' : printf("-%c expected argument\n", optopt); break;
 		}
	}
	return 0;
}