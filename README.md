# Kernel development project 
- Implement processes, thread, scheduler, synchronisation, VM, Virtual file system , Unix OS
- Use QEMU emulator to run and GDB for debugging 
- Kernel module which 
- Develop filesystem in linux kernel to detect files containing bad patterns 
- System call handle malicious cases and prevents memory leaks and unnessary memory allocation
- FIle encrytion, decryption in Linux using CryptoAPI
- Kernel locking, Producer-Consumer, Netlink sockets and throttling 
- Developed a kernel module which when loaded instantiates a producer-consumer work queue and a kernel thread to process the queue. The queue contains various job requests such as  Contenation of multiple files etc.
- Decipher process scheduling and understand effective capacity utilization under general and real-time dispositions
- Understand concurrent execution on SMP platforms through kernel synchronization and locking techniques
- Clock subsystem
- Process communication techniques through signals and IPC mechanisms



# Mac OSX and ioS 
+ FreeBSD 
+ kernel extension 
+ 

# Hardware & firmware 
+ Extensible firmware interface 
+ hardware

+ Kernel space : XNU kernel: BSD, Mach, IO 
+ Quartz, OpenGL, Core Animation, Core Image, Audio , Text, Quicktime
+ XNU kernel 
+ Kernel extension 
+ kernel address space management 
+ Memory Allocation in Mach 
`kern_return_t kmem_alloc(vm_map_t map, vm_offset_t *addrp, vm_size_t  size);

kern_return_t kmem_alloc_contig(vm_map_t map, vm_offset_t *addrp,
                                vm_size_t size, vm_offset_t mask, int flags);

void kmem_free(vm_map_t map, vm_offset_t addr, vm_size_t size);`

+ BSD layer 
+ Network kernel extension 
+ Virtual file syste 
+ Unified Buffer Cache
+ The Libkern Library 




<a href="https://imgur.com/H7PCoiz"><img src="https://i.imgur.com/H7PCoiz.png" title="source: imgur.com" /></a>


# XCode and Kernel development env
+ Cocoa framework 
+ C++ 
+ XCode 
    + Compiler for c/c++, objective c 
    + sourcecode debug
    + API + header files - used for kernel dev 
    + profiling tools - measure code execution time + app dev + performance bottleneck 
+ kernel extension 
+ kernel extension template 
+ logfile /var/log/kernel.log 