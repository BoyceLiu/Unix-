#include <stdio.h>

int main() {
	char buff[100];
	FILE *fp = popen("uname", "r");
	fgets(buff, 100, fp);
	fputs(buff, stdout);
	return 0;
}
