/* Implement system call
inside linux-5.1/kernel.
sys.c
*/

SYSCALL_DEFINE1(sysinfo, struct sysinfo __user *, info){
  struct sysinfo val;
  do_sysinfo(&val);
  if(copy_to_user(info, &val, sizeof(struct sysinfo)))
    return -EFAULT;
  return 0;
}
//Project 3 Lab Implement System Call
SYSCALL_DEFINE0(helloworld){
  printk("helloworld");
  return 0;
}

