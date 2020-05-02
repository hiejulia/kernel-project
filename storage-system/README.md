# Storage system 







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

    