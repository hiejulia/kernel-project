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
- Kernal Audio driver 

# Scripting 
+ Cryptographic Hash Function for random data & String manipulation 
+ Transform data / data process/ reporting
    + Cut and awk script : open network port 
    + sort & uniq
    + parsing log file 
+ Network scripting & automation of distributed system 
    + config a mini network and script for remote system 
+ test env : Vagrant & Virtual box Centos7 `vagrant up`
# Mac OSX and ioS 
+ FreeBSD 
+ kernel extension 
+ The XNU kernel (doc : /docs/xnu-kernel.md)

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


<a href="https://imgur.com/8AA7FKO"><img src="https://i.imgur.com/8AA7FKO.png" title="source: imgur.com" /></a>

<a href="https://imgur.com/H7PCoiz"><img src="https://i.imgur.com/H7PCoiz.png" title="source: imgur.com" /></a>

<a href="https://imgur.com/8Qi4QXj"><img src="https://i.imgur.com/8Qi4QXj.png" title="source: imgur.com" /></a>

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
<a href="https://imgur.com/a35XdK1"><img src="https://i.imgur.com/a35XdK1.png" title="source: imgur.com" /></a>
<a href="https://imgur.com/E02Gnj7"><img src="https://i.imgur.com/E02Gnj7.png" title="source: imgur.com" /></a>

#### IO kit framework 
    - kernel framework
    - IOkit framework 
- THE I/O KIT MODEL 
    - hardware 
    - usb device 
<a href="https://imgur.com/enuOLoG"><img src="https://i.imgur.com/enuOLoG.png" title="source: imgur.com" /></a>
<a href="https://imgur.com/AaBLcGt"><img src="https://i.imgur.com/AaBLcGt.png" title="source: imgur.com" /></a>
- THE INFO.PLIST FILE
    - list of drivers 
    - probe score 
    
- THE KERNEL LIBRARY: LIBKERN
    - os object 
    - tracking mem leaks 
    - container class
    - query a container for object



## Universal serial bus 
- USB specification and architecture
- USB subsystem provided by I/O Kit
- 

## Networking 
- BSD layer 
- socketAPI 
- protocol handler 
- network interface 
- network kernel extension NKE 
- Network memory buffer 
- IO Kit : write driver for network hardware 


## Audio driver 
- IOKit Audio Support 
- SamplePCIAudioDevice
- IOAudioDevice
- IOAudioStream

- MyAudioEngine
- Driver & hardware init
- audio driver's IOAudioDevice subclass
- config hardware device provider 
    - PCI & Thunderbolt, IO region 
    - USB devices 

- register audio control `IOKit/audio/AudioDefines.h.`


- create input mute control `IOAudioToggleControl::createMuteControl`

- implement Audio Engine 
    -  I/O in an audio driver
    - Allocate sample buffers and associated IOAudioStream instances.
    - `performAudioEngineStart()`
    - Header File for the MyAudioEngine Class

- I/O Engine Initialization
- Creating and Initializing Audio Streams
- Starting and Stopping the Audio Engine

- Engine Operation: Handling Interrupts and Timestamps

## Storage system 
- Physical connection 
- command protocol 
- Transport layer driver
- Building a RAM disk device 
- Partition scheme 
- Media filter driver 
    - Develop a filter scheme for encryption 



## POSIX standard 
- process 
- signal 
- fs
- pipe
- C 
- IO 



## Stack 
- C/C++ 
- Go arsenal CGO 
- OpenSSL 






# Docs / Reference 
+ https://en.wikipedia.org/wiki/Kernel_(operating_system)
+ https://docs.01.org/clearlinux/latest/guides/kernel/kernel-development.html 
- Darwin kernel (mirror): https://github.com/apple/darwin-xnu
- Apple opensource : https://developer.apple.com/opensource/


<a href="https://imgur.com/gmWahEy"><img src="https://i.imgur.com/gmWahEy.jpg" title="source: imgur.com" /></a>


