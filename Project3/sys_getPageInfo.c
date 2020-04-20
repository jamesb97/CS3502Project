//User test program for sys_getPageInfo
/*System will take the pid of a process as input and outputs
of the following information of start address vm_start
in each vm_area_struct which the process has
Memory disk, Referenced or not, dirty or not. */

#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define __NR_getPageInfo 339

int main(int argc, char *argv[]){
  int pid = 0;

  pid = atoi(argv[1]); //pid the process pid=123
  syscall(__NR_getPageInfo, pid);

  return 0;
}
