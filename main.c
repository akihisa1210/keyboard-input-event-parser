#include <assert.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#define TARGET_DEVICE "/dev/input/event15"

void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char* argv[])
{
	int fd = open(TARGET_DEVICE, O_RDONLY);
    if (fd == -1) {
        die("failed to open the target device");
    }

	for (;;) {
		struct input_event event;
        assert(read(fd, &event, sizeof(event)) == sizeof(event));
        printf("tv_sec: %lu, type: %04x, code: %04x, value: %08x\n", event.time.tv_sec, event.type, event.code, event.value);
        fflush(stdout);
    }
    close(fd);
}
