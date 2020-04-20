//Write a system call to display the current status of specific addresses
//in the virtual memory areas.

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/fs.h>
#include <asm/page.h>
#include <asm/mman.h>

asmlinkage int sys_vma_stats(int pid){
  struct task_struct *this_task;
  struct mm_struct *this_mem;
  struct vm_area_struct *all_vmas;
  struct vm_area_struct this_vma;

  int num_vmas;
  unsigned long prot=0;
  unsigned long start=0;
  int count=0;
  int total_size=0;
  char *name;

  this_task = find_task_by_vpid(pid);
  this_mem = this_task->active_mm;
  all_vmas = this_mem->mmap;
  num_vas = this_mem->map_count;
  this_vma = *all_vmas;
  start=this_vma.vm_start;

  printk("\nThere are %i virtual memory areas (VMAS).\n", num_vas);
  for(this_vma = *all_vmas; count < num_vmas; count++){
    printk("----------------------------\n");
    printk("VMA #%i:\n", count+1);
    printk("-> Start Address: 0x%1x\n", this_vma.vm_start);
    printk("-> End Address: 0x%1x\n", this_vma.vm_end);
    printk("-> Total Size (End - Start): %lu\n", this_vma.vm_end - this_vma.vm_start);

    prot = this_vma.vm_flags;
    printk("-> Access permissions:\n");
    printk("Read permission: %s \n", prot&PROT_READ?"yes":"no");
    printk("Write permission: %s \n", prot&PROT_WRITE?"yes":"no");
    printk("Execute permission: %s \n", prot&PROT_EXEC?"yes":"no");

    if(this_vma.vm_file != NULL){
      name = d_path(&this_vma.vm_file->f_path, (char*)__get_free_page(GFP_TEMPORARY),
		    PAGE_SIZE);
      printk("-> Mapped file: %s\n", name);
    }
    total_size += this_vma.vm_end - this_vma.vm_start;
    if(count != num_vmas-1) { this_vma = *(this_vma.vm_next); }
  }
  printk("\nTotal VMA Space Size (all VMAs): %i\n", total_size);
  return 1;
}

