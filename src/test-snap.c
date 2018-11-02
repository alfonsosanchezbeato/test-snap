#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
    int fd, ret;

    printf("Start\n");

    fd = open("/dev/kmsg", O_RDWR);
    if (fd < 0) {
        printf("open error %d\n", errno);
        exit(1);
    }

    ret = write(fd, "xx\n", 3);
    if (ret < 0) {
        printf("write error %d\n", errno);
        exit(1);
    }

    ret = close(fd);
    if (ret < 0) {
        printf("close error %d\n", errno);
        exit(1);
    }

    printf("End\n");

    return 0;
}
