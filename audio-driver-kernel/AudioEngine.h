//
//  AudioEngine.h
//  test1
//
//  Created by la-hien.nguyen on 15.4.2020.
//  Copyright © 2020 la-hien.nguyen. All rights reserved.
//

#ifndef AudioEngine_h
#define AudioEngine_h



#include <IOKit/audio/IOAudioEngine.h>

#include "AudioDevice.h"

#define AudioEngine com_osxkernel_AudioEngine

class AudioEngine : public IOAudioEngine
{
    OSDeclareDefaultStructors(AudioEngine)

public:
    virtual void free();
    
    virtual bool initHardware(IOService *provider);
    virtual void stop(IOService *provider);
    
    virtual IOAudioStream *createNewAudioStream(IOAudioStreamDirection direction, void *sampleBuffer, UInt32 sampleBufferSize);
    
    virtual IOReturn performAudioEngineStart();
    virtual IOReturn performAudioEngineStop();
    
    virtual UInt32 getCurrentSampleFrame();
    
    virtual IOReturn performFormatChange(IOAudioStream *audioStream, const IOAudioStreamFormat *newFormat, const IOAudioSampleRate *newSampleRate);
    
    virtual IOReturn clipOutputSamples(const void *mixBuf, void *sampleBuf, UInt32 firstSampleFrame, UInt32 numSampleFrames, const IOAudioStreamFormat *streamFormat, IOAudioStream *audioStream);
    virtual IOReturn convertInputSamples(const void *sampleBuf, void *destBuf, UInt32 firstSampleFrame, UInt32 numSampleFrames, const IOAudioStreamFormat *streamFormat, IOAudioStream *audioStream);
    
private:
    IOTimerEventSource*     fAudioInterruptSource;
    SInt16                  *fOutputBuffer;
    SInt16                    *fInputBuffer;
    
    static void             interruptOccured(OSObject* owner, IOTimerEventSource* sender);
    void                    handleAudioInterrupt();
    
    UInt32                  fInterruptCount;
    
    SInt64                  fNextTimeout;

};



#endif /* AudioEngine_h */
