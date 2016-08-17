#include <stdio.h>

int main() {
	char buff[100];
	FILE *fp = popen("uname", "r");
	fgets(buff, fp);
	fputs(buff, stdout);
	return 0;
}