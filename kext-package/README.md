# Loading & unload kernel extension 
- copy /System/Library/Extensions
- `sudo chown -R root:wheel HelloWorld.kext`
- `sudo kextload HelloWorld.kext`
- log file : /var/log/kernel.log
