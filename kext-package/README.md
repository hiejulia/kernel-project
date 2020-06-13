# Loading & unload kernel extension 
- copy /System/Library/Extensions
- `sudo chown -R root:wheel HelloWorld.kext`
- `sudo kextload HelloWorld.kext`
- log file : /var/log/kernel.log

<a href="https://imgur.com/rCSkxxf"><img src="https://i.imgur.com/rCSkxxf.png" title="source: imgur.com" /></a>

<a href="https://imgur.com/bFyRC5R"><img src="https://i.imgur.com/bFyRC5R.png" title="source: imgur.com" /></a>