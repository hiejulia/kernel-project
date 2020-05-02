# Storage system 
- IOBLOCKSTORAGEDEVICE INTERFACE

- IOStorage
- IO registry 




## Building a RAM disk device 
- allocate memory buffer provide storage for the disk device 
- Instantiating the IOBlockStorageDevice Nub from the RAM Disk Transport Driver
- run : `diskutil list`
    /dev/disk1
   #:   TYPE                    NAME            SIZE            IDENTIFIER
   0:   GUID_partition_scheme                   *16.8 MB        disk1
   1:   Apple_HFS               VolumeName      16.7 MB         disk1s1


## Partition scheme 
- Implementing a Sample Partition Scheme
- Sample Matching Dictionary from the Property List of a Partition Scheme Driver
- partition scheme driver 
- Method to Detect the Presence of a Sample Partition Table on a Disk and to Instantiate IOMedia Objects for that Partition Table
- A Method to Instantiate IOMedia Objects That Represent an Individual Disk Partition



- stop() and free() Methods for a Partition Scheme Driver

## Media Filter Driver
- read async 
    - provide completion callback saved to a allocation a structure in memory using `IOMalloc`
- set up `IOStorageCompletion`
- read from encrypted `IOMedia` object
- encryption filter scheme write operation 
- create custom GUID Partition table 
    - driver in storage stack   
    - disk image 
    - write an HFS file system to encrypted volume 
    - `hdiutil`
    - `hdiutil create -megabytes 25 -layout NONE EncryptedImage.dmg`
    - `hdiutil attach -nomount EncryptedImage.dmg`
    - `gpt create /dev/diskN`
    - `gpt add -t 8D7FD0BB-39A8-43C0-9432-F4E1A269F070 /dev/diskN`
    - create HFS file system on the volume 
        - `newfs_hfs -v MyVolumeName /dev/diskNs1s1`


<a href="https://imgur.com/brP63Zc"><img src="https://i.imgur.com/brP63Zc.png" title="source: imgur.com" /></a>
