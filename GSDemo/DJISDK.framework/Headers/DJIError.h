//
//  DJIError.h
//
//  Copyright (c) 2015年 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ERR_Successed                         0x00

#define ERR_NotSupport                        0x01
#define ERR_NotActivation                     0x02
#define ERR_ActivationFailed                  0x03
#define ERR_NoPermission                      0x04

#define ERR_InvalidSSID                       0x10
#define ERR_SendFailed                        0x11
#define ERR_ConnectFailed                     0x12
#define ERR_InvalidParameter                  0x13
#define ERR_CommandExecuteFailed              0x14

#define ERR_RCModeError                       0xD0
#define ERR_MCModeError                       0xD1
#define ERR_NoMission                         0xD2
#define ERR_MissionParameterError             0xD3
#define ERR_MissionAcrossLimitFlyArea         0xD5
#define ERR_MissionEstimateTimeTooLong        0xD6
#define ERR_ExecutingHighPriorityMission      0xD7
#define ERR_GPSSignalWeak                     0xD8
#define ERR_LowBattery                        0xD9

#define ERR_NotSupportedCommand               0xE0
#define ERR_Timeout                           0xE1
#define ERR_MemoryAllocFailed                 0xE2
#define ERR_InvalidCommand                    0xE3
#define ERR_NotSupportNow                     0xE4
#define ERR_TimeNotSync                       0xE5
#define ERR_ParameterSetFailed                0xE6
#define ERR_ParameterGetFailed                0xE7
#define ERR_SDCardNotInserd                   0xE8
#define ERR_SDCardFull                        0xE9
#define ERR_SDCardError                       0xEA
#define ERR_SensorError                       0xEB
#define ERR_SystemError                       0xEC
#define ERR_NotDefined                        0xFF

#define ERR_InvalidData                       0x100
#define ERR_NetworkAbortByApp                 0x101
#define ERR_NetworkAbortByServer              0x102


@class DJIError;

extern DJIError *DJIErrorFor(NSUInteger errorCode);

typedef NS_ENUM(NSUInteger, DJIErrorCode){
    DJIErrorCode_None = 0x00,
    
    DJIErrorCode_Timeout = 0xf0,
    DJIErrorCode_Failed = 0xf1,
    DJIErrorCode_NotSupport = 0xf2,
    DJIErrorCode_InvalidParameter = 0xf3,
};

/**
 *  Error Class.Subclasses need to define the error code corresponding to the description.
 */
@interface DJIError : NSObject
{
    NSUInteger _code;
    NSString *_content;
}
/**
 *  Error code.
 */
@property (assign,nonatomic,readonly) NSUInteger errorCode;

/**
 *  Error description.
 */
@property (strong,nonatomic,readonly) NSString *errorDescription;

+ (instancetype)errorWithErrorCode:(NSUInteger)errorCode;

- (id)initWithErrorCode:(NSUInteger)errCode;

@end

#define NewErrorObject(code) [[DJIError alloc] initWithErrorCode:(code)]
