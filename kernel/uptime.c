#include "syscall.h"
int
uptime(void)
{
    return syscall(SYS_uptime);
}
