#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void server(int readfd, int writefd) {
	char buff[100];
	int len = read(readfd, buff, 100);
	filename[len] = 0;
	fputs(filename, stdout);
	write(writefd, buff, len);
}

void client(int readfd, int writefd) {
	char buff[100];
	fgets(buff, 100, stdin);
	int len = strlen(buff);
	write(writefd, buff, len);
	len = read(readfd, buff, 100);
	buff[len] = '\0';
	fputs(buff, stdout);
}

int main() {
	int cli_to_ser[2], ser_to_cli[2];
	pid_t pid;
	if (pipe(cli_to_ser) < 0) {
		fprintf(stderr, "pipe open error\n");
		exit(-1);
	}
	if (pipe(ser_to_cli) < 0) {
		close(cli_to_ser[0]);
		close(cli_to_ser[1]);
		fprintf(stderr, "pipe open error\n");
		exit(-1);
	}
	pid = fork();
	if (pid < 0) {
		fprintf(stderr, "fork error");
		exit(-1);
	}
    if (pid == 0) {
		close(cli_to_ser[1]);
		close(ser_to_cli[0]);
		server(cli_to_ser[0], ser_to_cli[1]);
		exit(0);
	}
	close(cli_to_ser[0]);
	close(ser_to_cli[1]);
	client(ser_to_cli[0], cli_to_ser[1]);
	waitpid(pid, NULL, 0);
	return 0;
}