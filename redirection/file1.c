#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    pid_t pid;
    int fd[2];

    if(pipe(fd) == -1) {
        perror("Unable to create pipe");
        return 1;
    }

    if((pid = fork()) == -1) {
        perror("Unable to create child");
        return 1;
    }

    if(pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execl("/usr/bin/ls", "ls", NULL);
    }

    // Open the output file
    int outfile = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (outfile == -1) {
        perror("Unable to open file");
        return 1;
    }

    // Redirect the output to the file
    dup2(outfile, STDOUT_FILENO);
    close(outfile);
    close(fd[1]);

    // Read the input from the pipe
    char buf[PIPE_BUF];
    ssize_t nread;
    while ((nread = read(fd[0], buf, PIPE_BUF)) > 0) {
        write(STDOUT_FILENO, buf, nread);
    }

    close(fd[0]);
    return 0;
}
