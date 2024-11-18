#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd1 = open("test.txt", O_RDWR | O_CREAT);
    if (fd1 == -1)
    {
        printf("File 1 failed to open\n");
        return (1);
    }
    else
        printf("fd1 : %d\n", fd1);
    char buffer1[1024];
    buffer1[6] = '\0';
    int bs1 = read(fd1, buffer1, 5);
    printf("the fd1 : %d\n", fd1);
    printf("bytes read the first time : %d\n", bs1);
    printf("the buffer from the first read : %s\n", buffer1);
    printf("-------------------------------------\n");

    int fd2 = open("test.txt", O_RDWR | O_CREAT);
    if (fd2 == -1)
    {
        printf("File 2 failed to open\n");
        return (1);
    }
    else
        printf("fd2 : %d\n", fd2);
    char buffer2[1024];
    buffer2[6] = '\0';
    int bs2 = read(fd2, buffer2, 5);
    printf("the fd2 : %d\n", fd2);
    printf("bytes read the second time : %d\n", bs2);
    printf("the buffer from the second read : %s\n", buffer2);
    return 0;
}
