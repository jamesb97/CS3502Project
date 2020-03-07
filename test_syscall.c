#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#define __NR_helloworld 335

//Main function implementation:
int main(int argc, char *argv[])
{
  syscall(__NR_helloworld);
  return 0;
}

