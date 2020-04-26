# Simple ethernet controller driver 
- IO Kit networking 
- Implement virtual ethernet driver 
- connect to Mac thunderbolt port 
- Virtual network interface - BSD layer 
- send and receive packets and test with Ethernet driver on mac that send a packet with a fake source address 

- en0 : enable promiscuous mode 
- virtual Ethernet bridge/ switch 



- Code implementation 
    - MyEthernetDriver header file 

- Driver init and set up     
- IOService lifecycle 

- allocate and config IOInteruppEventSource or IOTimerEventSource 
- attachInterface() - instruct to expose driver to kernel network layer 
- record of received/ transmitted packet, collision and other events 


- create dict for device capabilites to BSD stacl 
- Method for Publishing Details about Supported Ethernet Media

- Configuring the Device Hardware Address

- Transmitting Network Packets
    - createOutputQueue()
    - inject the received packet to the slave device's output queue
    
    - pre-allocated physically allocated buffer || create a scatter/gather list directly from the mbuf, using a variant of IOMbufMemoryCursor, which will avoid performing an extra copy.

- Receiving Packets

- Handling Incoming Packets from the Slave Device and Raising Virtual Interrupts

- Taking MyEthernetDriver for a Test-Drive
    - kextload
    - IORegisteryExplorer showing MyEthernetDriver
    - `sudo ifconfig en5 inet 192.168.1.50 netmask 255.255.255.0`
    - `ifconfig en5`
    - `ping 192.168.1.50`
    - `netstat -i -I en5`



- DEBUGGING AND TESTING NETWORK EXTENSIONS
    - tcp-dump  `tcpdump -i en0`
    - netcat 
    - `nc –u 192.168.1.2 4040`









## Resource 
- https://opensource.apple.com/
