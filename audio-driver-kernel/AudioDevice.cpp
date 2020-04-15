//
//  AudioDevice.cpp
//  test1
//
//  Created by la-hien.nguyen on 15.4.2020.
//  Copyright © 2020 la-hien.nguyen. All rights reserved.
//

#include "AudioDevice.hpp"
#include "AudioDevice.h"

#include <IOKit/audio/IOAudioControl.h>
#include <IOKit/audio/IOAudioLevelControl.h>
#include <IOKit/audio/IOAudioToggleControl.h>
#include <IOKit/audio/IOAudioDefines.h>

#include "AudioEngine.h"

#include <IOKit/IOLib.h>

#define super IOAudioDevice

OSDefineMetaClassAndStructors(AudioDevice, IOAudioDevice)
bool AudioDevice::initHardware(IOService *provider)
{
    bool result = false;
    
    IOLog("AudioDevice[%p]::initHardware(%p)\n", this, provider);
    
    if (!super::initHardware(provider))
        goto done;
        
    setDeviceName("Audio Device");
    setDeviceShortName("AudioDevice");
    setManufacturerName("osxkernel.com");
        
    if (!createAudioEngine())
        goto done;
    
    result = true;
    
done:
    return result;
}

#define CREATE_VOLUME_CONTROL(chanID, chanName, usage) \
    IOAudioLevelControl::createVolumeControl(65535, 0, 65535, 0, (-22 << 16) + (32768), chanID, chanName, 0, usage)

#define CREATE_MUTE_CONTROL(usage) \
    IOAudioToggleControl::createMuteControl(false, kIOAudioControlChannelIDAll, kIOAudioControlChannelNameAll, 0, usage)

#define ADD_CONTROL(control, callback) \
    if (!control) \
        goto done; \
    control->setValueChangeHandler(callback, this); \
    audioEngine->addDefaultAudioControl(control); \
    control->release();


bool AudioDevice::createAudioEngine()
{
    bool result = false;
    AudioEngine *audioEngine = NULL;
    IOAudioControl *control;
       
    audioEngine = new AudioEngine();
    if (!audioEngine)
        goto done;
    
    if (!audioEngine->init(NULL))
        goto done;
  
    control = CREATE_VOLUME_CONTROL(kIOAudioControlChannelIDDefaultLeft, kIOAudioControlChannelNameLeft, kIOAudioControlUsageOutput);
    ADD_CONTROL(control, volumeChangeHandler)
    
    control = CREATE_VOLUME_CONTROL(kIOAudioControlChannelIDDefaultRight, kIOAudioControlChannelNameRight, kIOAudioControlUsageOutput);
    ADD_CONTROL(control, volumeChangeHandler)
    
    control = CREATE_MUTE_CONTROL(kIOAudioControlUsageOutput);
    ADD_CONTROL(control, outputMuteChangeHandler)
    
    control = CREATE_VOLUME_CONTROL(kIOAudioControlChannelIDDefaultLeft, kIOAudioControlChannelNameLeft, kIOAudioControlUsageInput);
    ADD_CONTROL(control, gainChangeHandler)

    control = CREATE_VOLUME_CONTROL(kIOAudioControlChannelIDDefaultRight, kIOAudioControlChannelNameRight, kIOAudioControlUsageInput);
    ADD_CONTROL(control, gainChangeHandler)

    control = CREATE_MUTE_CONTROL(kIOAudioControlUsageInput);
    ADD_CONTROL(control, inputMuteChangeHandler)
    
    activateAudioEngine(audioEngine);
       audioEngine->release();
    result = true;
    
done:
   
    if (!result && (audioEngine != NULL)) {
        audioEngine->release();
    }

    return result;
}

IOReturn AudioDevice::volumeChangeHandler(OSObject *target, IOAudioControl *volumeControl, SInt32 oldValue, SInt32 newValue)
{
    IOReturn result = kIOReturnBadArgument;
    AudioDevice *audioDevice;
    audioDevice = (AudioDevice *)target;
    if (audioDevice)
        result = audioDevice->volumeChanged(volumeControl, oldValue, newValue);
    return result;
}

IOReturn AudioDevice::volumeChanged(IOAudioControl *volumeControl, SInt32 oldValue, SInt32 newValue)
{
    IOLog("AudioDevice[%p]::volumeChanged(%p, %d, %d)\n", this, volumeControl, (int)oldValue, (int)newValue);
    if (volumeControl)
        IOLog("\t-> Channel %u\n", (unsigned int)volumeControl->getChannelID());
        
    return kIOReturnSuccess;
}

IOReturn AudioDevice::outputMuteChangeHandler(OSObject *target, IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue)
{
    IOReturn result = kIOReturnBadArgument;
    AudioDevice *audioDevice;
    
    audioDevice = (AudioDevice*)target;
    if (audioDevice) {
        result = audioDevice->outputMuteChanged(muteControl, oldValue, newValue);
    }
    
    return result;
}

IOReturn AudioDevice::outputMuteChanged(IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue)
{
    IOLog("AudioDevice[%p]::outputMuteChanged(%p, %d, %d)\n", this, muteControl, (int)oldValue, (int)newValue);
        
    return kIOReturnSuccess;
}

IOReturn AudioDevice::gainChangeHandler(OSObject *target, IOAudioControl *gainControl, SInt32 oldValue, SInt32 newValue)
{
    IOReturn result = kIOReturnBadArgument;
    AudioDevice *audioDevice;
    
    audioDevice = (AudioDevice *)target;
    if (audioDevice) {
        result = audioDevice->gainChanged(gainControl, oldValue, newValue);
    }
    
    return result;
}

IOReturn AudioDevice::gainChanged(IOAudioControl *gainControl, SInt32 oldValue, SInt32 newValue)
{
    IOLog("AudioDevice[%p]::gainChanged(%p, %d, %d)\n", this, gainControl, (int)oldValue, (int)newValue);
    
    if (gainControl) {
        IOLog("\t-> Channel %u\n", (unsigned int)gainControl->getChannelID());
    }
        
    return kIOReturnSuccess;
}

IOReturn AudioDevice::inputMuteChangeHandler(OSObject *target, IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue)
{
    IOReturn result = kIOReturnBadArgument;
    AudioDevice *audioDevice;
    
    audioDevice = (AudioDevice *)target;
    if (audioDevice) {
        result = audioDevice->inputMuteChanged(muteControl, oldValue, newValue);
    }
    
    return result;
}

IOReturn AudioDevice::inputMuteChanged(IOAudioControl *muteControl, SInt32 oldValue, SInt32 newValue)
{
    IOLog("AudioDevice[%p]::inputMuteChanged(%p, %d, %d)\n", this, muteControl, (int)oldValue, (int)newValue);
        
    return kIOReturnSuccess;
}
