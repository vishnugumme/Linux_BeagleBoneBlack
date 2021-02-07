# Creating Kernel Modules
Refer [Link](https://medium.com/@ssreehari/implementing-a-system-call-in-linux-kernel-4-7-1-6f98250a8c38).<br>
  1. Make seprate foler in `~/bbb_build/bb_kernel/KERNEL/user_kernel_folder`<br>
  2. Add above two files to `user_kernel_folder`<br>
  3. Add this folder entry to the kernel Makefile present in `/bbb_build/bb_kernel/KERNEL/`<br>
  4. Add syscall entry to the syscall table.<br>
  5. Add function declaration in include file of linux.<br>
# Rebuild Kernel
  1. `cd ~/bbb_buld/bb_kernel/`
  2. `./tools/rebuld.sh'
  After this boot the kernel into the BBB.
