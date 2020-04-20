//Declare system call in the header file
/*Project 3 Lab Syscall */
asmlinkage long sys_helloworld(void);


//Register system call into syscall_64.tbl
//cd arch/x86/entry/syscalls/syscall_64.tbl
//Project 3 Lab Syscall
//335  common helloworld       __x64_sys_helloworld

