#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/datetime.h"

int
main(int argc, char *argv[])
{
  struct rtcdate r;

  if(datetime(&r) < 0) {
    printf("datetime failed\n");
    exit(1);
  }

  printf("Current date and time:\n");
  printf("Year: %d\n", r.year);
  printf("Month: %d\n", r.month);
  printf("Day: %d\n", r.day);
  printf("Hour: %d\n", r.hour);
  printf("Minute: %d\n", r.minute);
  printf("Second: %d\n", r.second);

  exit(0);
}
