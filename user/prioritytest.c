#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  //check default priority
  printf("Default priority: %d\n", getpriority());

  //change to the highest priority
  printf("Set priority to 0: %d\n", setpriority(0));
  printf("Current priority: %d\n", getpriority());

  //change to the lowest priority
  printf("Set priority to 2: %d\n", setpriority(2));
  printf("Current priority: %d\n", getpriority());

  //test invalid priority level
  printf("Set priority to -1: %d\n", setpriority(-1));
  printf("Current priority: %d\n", getpriority());

  exit(0);
}