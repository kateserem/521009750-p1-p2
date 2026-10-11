#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  // //check default priority
  // printf("Default priority: %d\n", getpriority());

  // //change to the highest priority
  // printf("Set priority to 0: %d\n", setpriority(0));
  // printf("Current priority: %d\n", getpriority());

  // //change to the lowest priority
  // printf("Set priority to 2: %d\n", setpriority(2));
  // printf("Current priority: %d\n", getpriority());

  // //test invalid priority level
  // printf("Set priority to -1: %d\n", setpriority(-1));
  // printf("Current priority: %d\n", getpriority());

  // //test if a child inherits parent priority level
  // setpriority(2);

  // int pid = fork();

  // if (pid < 0) {
  // printf("Fork failed\n");
  // } 
  // else if (pid == 0) {
  // //child process
  // printf("Child priority: %d\n", getpriority());
  // exit(0);
  // } 
  // else {
  // //parent process
  // wait(0);
  // printf("Parent priority: %d\n", getpriority());
  // }

  // //Test if round-robin scheduling works when processes have the same priority level
  // //creating three child processes
  // for (int i = 0; i < 3; i++) {
  //   int pid = fork();

  //   if (pid < 0) {
  //     printf("Fork failed\n");
  //     exit(1);
  //   }

  //   if (pid == 0) {
  //     //set to default priority level 1
  //     setpriority(1);

  //     // Keep the child busy so the scheduler can switch processes
  //     for (volatile int j = 0; j < 100000000; j++) {
  //       if (j % 20000000 == 0) {
  //         printf("Child %d is running\n", i);
  //       }
  //     }

  //     exit(0);
  //   }
  // }

  // //parent waits for all three children to finish
  // for (int i = 0; i < 3; i++) {
  //   wait(0);
  // }

  // printf("All children finished\n");
  // exit(0);

  //Test when processes have different priority levels
  for (int i = 0; i < 3; i++) {
    int pid = fork();

    if (pid < 0) {
      printf("Fork failed\n");
      exit(1);
    }

    if (pid == 0) {
      //setting a different priority level for each child process
      setpriority(i);

      printf("Child %d has priority %d\n", i, getpriority());

      //Keeping the process busy to give scheduler enough time to switch between processes
      for (volatile int j = 0; j < 100000000; j++) {
      }

      printf("Child %d finished\n", i); 
      exit(0);
    }
  }

  //wait for all three child processes to finish
  for (int i = 0; i < 3; i++) {
    wait(0);
  }

  printf("Priority scheduling test finished\n");
}

