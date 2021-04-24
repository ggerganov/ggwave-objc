//
//  ViewController.h
//  ggwave-objc
//
//  Created by Georgi Gerganov on 24.04.21.
//

#import <UIKit/UIKit.h>

#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioQueue.h>

#define NUM_BUFFERS 3

typedef struct
{
    int ggwaveId;
    bool isCapturing;
    UILabel * labelReceived;

    AudioQueueRef queue;
    AudioStreamBasicDescription dataFormat;
    AudioQueueBufferRef buffers[NUM_BUFFERS];
} StateInp;

typedef struct
{
    bool isPlaying;
    int ggwaveId;
    int offset;
    int totalBytes;
    NSMutableData * waveform;
    UILabel * labelStatus;

    AudioQueueRef queue;
    AudioStreamBasicDescription dataFormat;
    AudioQueueBufferRef buffers[NUM_BUFFERS];
} StateOut;

@interface ViewController : UIViewController
{
    StateInp stateInp;
    StateOut stateOut;
}

@end
