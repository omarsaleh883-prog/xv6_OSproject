#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(void) {
    int t = uptime();
    printf("Uptime in ticks: %d\n", t);
    return 0;
}
