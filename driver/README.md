<a href="https://imgur.com/Rnkzzry"><img src="https://i.imgur.com/Rnkzzry.png" title="source: imgur.com" /></a>

# Interact with driver 
- iterate all connected USB hardware devices
- polling method/ notification callback to register to receive notifications when USB device is connected 



# Observe device removal 
- install callback function to receive a notification when a driver terminate 

# Modify driver properties 
- read property table of USB device


# State base interaction from application to driver 




# notifications from the driver 
- `IONotificationPortCreate() `
- allocate a port on which appliation can receive notification when async operation complete
- run loop 
- user client implement of async operation 


