#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
   if (argc != 2) {
        printf("fact uses two args\n");
        exit(1);
    }

  if (argv[1][0] == '-') {
    exit(1);
}
 if(argv[1][0] >= 'a' || argv[1][0] >= 'z')
  {
      exit(3);
  }

  if(argv[1][0] >= 'A' || argv[1][0] >= 'Z')
  {
      exit(3);
  }

int n=atoi(argv[1]);



if(n==0)
{
  printf("%d",n+1);
  exit(0);
}

for(int i=n-1;i>=1;i--){
  n=n*i;
}
printf("%d",n);
exit(0);




}
