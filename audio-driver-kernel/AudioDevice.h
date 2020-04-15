//
//  AudioDevice.h
//  test1
//
//  Created by la-hien.nguyen on 15.4.2020.
//  Copyright © 2020 la-hien.nguyen. All rights reserved.
//

#ifndef AudioDevice_h
#define AudioDevice_h


#include <IOKit/audio/IOAudioDevice.h>

#define AudioDevice com_osxkernel_AudioDevice

class AudioDevice : public IOAudioDevice
{
    OSDeclareDefaultStructors(AudioDevice);
    
    virtual bool initHardware(IOService *provider);
    bool createAudioEngine();
    
    // Control callbacks
    static IOReturn volumeChangeHandler(OSObject *target, IOAudioControl *volumeControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn volumeChanged(IOAudioControl *volumeControl, SInt32 oldValue, SInt32 newValue);
    
    static IOReturn outputMuteChangeHandler(OSObject *target, IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn outputMuteChanged(IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);
    
    static IOReturn gainChangeHandler(OSObject *target, IOAudioControl *gainControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn gainChanged(IOAudioControl *gainControl, SInt32 oldValue, SInt32 newValue);
    
    static IOReturn inputMuteChangeHandler(OSObject *target, IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);
    virtual IOReturn inputMuteChanged(IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue);
};



#endif /* AudioDevice_h */
