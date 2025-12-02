// randtest.c (compile into user)
#include "user/user.h"
#include "kernel/types.h"

int
main(int argc, char *argv[])
{
  int i;
  for(i = 0; i < 10; i++){
    int r = random();
    printf("rand %d: %u\n", i, (unsigned)r);
  }
  exit(0);
}
