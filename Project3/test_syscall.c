//Write user level for call
//System call cd linux-5.1/kernel/test_syscall.c

#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>x
#include <stdio.h>
#define __NR_helloworld 335

int main(int args, char *argv[]){
  syscall(__NR_helloworld);
  return 0;
}
//If syscall needs parameter, then:
//syscall(__NR_helloworld, a, b, c);

