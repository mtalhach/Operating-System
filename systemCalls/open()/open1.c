#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a filename as a command-line argument.\n");
        return 1;
    }

    int n, fd;
    char buff[50];
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int output_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (output_fd == -1) {
        printf("Failed to create the output file.\n");
        return 1;
    }

    n = read(fd, buff, 10);
    write(output_fd, buff, n);

    close(fd);
    close(output_fd);

    return 0;
}

