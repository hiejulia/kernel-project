# Storage system 







## Media Filter Driver
- read async 
    - provide completion callback saved to a allocation a structure in memory using `IOMalloc`
- set up `IOStorageCompletion`
- read from encrypted `IOMedia` object
- encryption filter scheme write operation 
- create custom GUID Partition table 
    