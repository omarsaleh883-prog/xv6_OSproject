#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "kernel/datetime.h"

uint64
sys_datetime(void)
{
    uint64 addr;
    struct rtcdate r;

    // Get the user-space address
    argaddr(0, &addr);

    // Since xv6-riscv doesn't have real RTC, simulate it using ticks
    acquire(&tickslock);
    uint ticks_value = ticks;
    release(&tickslock);

    // Convert ticks to a mock date/time
    r.second = (ticks_value / 100) % 60;
    r.minute = (ticks_value / 6000) % 60;
    r.hour = (ticks_value / 360000) % 24;
    r.day = 1 + (ticks_value / 8640000) % 30;
    r.month = 1 + (ticks_value / 259200000) % 12;
    r.year = 2024;

    // Copy the date structure to user space
    if(copyout(myproc()->pagetable, addr, (char*)&r, sizeof(r)) < 0)
        return -1;

    return 0;
}
