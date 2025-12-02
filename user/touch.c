#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(2, "touch: missing file operand\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        char *filename = argv[i];

        // Try to open the file read-only
        int fd = open(filename, O_RDONLY);
        if (fd >= 0) {
            // File already exists
            close(fd);
            fprintf(2, "touch: %s already exists\n", filename);
            exit(1);
        }

        // File does not exist — create it
        fd = open(filename, O_CREATE | O_WRONLY);
        if (fd < 0) {
            fprintf(2, "touch: cannot create %s\n", filename);
            exit(1);
        }

        close(fd);
    }

    exit(0);
}
