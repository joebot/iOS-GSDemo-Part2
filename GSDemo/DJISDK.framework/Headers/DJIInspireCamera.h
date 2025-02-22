//
//  DJIInspireCamera.h
//
//  Copyright (c) 2015 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <DJISDK/DJICamera.h>

typedef void (^DJIFileDownloadPreparingBlock)(NSString* fileName, NSUInteger fileSize, BOOL* skip);
typedef void (^DJIFileDownloadingBlock)(NSData* data, NSError* error);
typedef void (^DJIFileDownloadCompletionBlock)();

@interface DJIInspireCamera : DJICamera

/**
 *  Get the camera's firmware version
 *
 *  @return Return the firmware version of the camera.
 */
-(NSString*) getCameraVersion;

/**
 *  Take photo with mode, if the capture mode is CameraMultiCapture or CameraContinousCapture, you should call stopTakePhotoWithResult to stop photoing
 *
 *  @param captureMode Tell the camera what capture action will be do, if capture mode is multi capture or continuous capture, user should call the 'stopTakePhotWithResult' to stop catpture if need.
 *  @param block  The remote execute result.
 */
-(void) startTakePhoto:(CameraCaptureMode)captureMode withResult:(DJIExecuteResultBlock)block;

/**
 *  Stop the mutil capture or continous capture. should match the startTakePhoto action.
 *
 *  @param block       The remote execute result
 */
-(void) stopTakePhotoWithResult:(DJIExecuteResultBlock)block;

/**
 *  Start recording
 *
 *  @param block The remote execute result
 */
-(void) startRecord:(DJIExecuteResultBlock)block;

/**
 *  Stop recording
 *
 *  @param block The remote execute result
 */
-(void) stopRecord:(DJIExecuteResultBlock)block;

/**
 *  Start the system state updates.
 */
-(void) startCameraSystemStateUpdates;

/**
 *  Stop the system state updates
 */
-(void) stopCameraSystemStateUpdates;

/**
 *  Set camera's work mode. camera action will execute successfully on the corresponding work mode
 *
 *  @param mode  Work mode to be set to camera
 *  @param block Remote execute result.
 */
-(void) setCameraWorkMode:(CameraWorkMode)mode withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's current work mode.
 *
 *  @param block Remote execute result.
 */
-(void) getCameraWorkModeWithResult:(void (^)(CameraWorkMode, DJIError *))block;

@end

@interface DJIInspireCamera (CameraSettings)

/**
 *  Set camera's current setting to the specific user
 *
 *  @param settings Specific user to store the settings
 *  @param result   Remote execute result.
 */
-(void) saveCameraSettingsTo:(CameraUserSettings)settings withResult:(DJIExecuteResultBlock)result;

/**
 *  Load specific settings form user
 *
 *  @param settings Settings to be load
 *  @param result   Remote execute result.
 */
-(void) loadCameraSettingsFrom:(CameraUserSettings)settings withResult:(DJIExecuteResultBlock)result;

/**
 *  Set camera's exposure mode
 *
 *  @param mode  Exposure mode to be set
 *  @param block Remote execute result
 */
-(void) setCameraExposureMode:(CameraExposureMode)mode withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's exposure mode setting
 *
 *  @param block Remote execute result
 */
-(void) getCameraExposureModeWithResult:(void (^)(CameraExposureMode, DJIError *))block;

/**
 *  Set camera's photo size
 *
 *  @param photoSize Photo size set to camera
 *  @param ratio     Photo ration set to camera
 *  @param block     Remote execute result
 */
-(void) setCameraPhotoSize:(CameraPhotoSizeType)photoSize andRatio:(CameraPhotoRatioType)ratio withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's photo size setting
 *
 *  @param block Remote execute result
 */
-(void) getCameraPhotoSizeAndRatioWithResult:(void(^)(CameraPhotoSizeType photoSize, CameraPhotoRatioType ratio, DJIError* error))block;

/**
 *  Set camera's photo quality
 *
 *  @param quality Photo quality set to camera
 *  @param block   Remote execute result
 */
-(void) setCameraPhotoQuality:(CameraPhotoQualityType)quality withResult:(DJIExecuteResultBlock)block;

/**
 *  Get cameras' photo quality setting
 *
 *  @param block Remote execute result
 */
-(void) getCameraPhotoQualityWithResult:(void(^)(CameraPhotoQualityType quality, DJIError* error))block;

/**
 *  Set spot metering area. the area size is row(12) by column(8). so the areaIndex value is in range [0, 95]
 *
 *  @param areaIndex Area index set to camera
 *  @param block     Remote execute result
 */
-(void) setCameraSpotMeteringArea:(uint8_t)areaIndex withResult:(DJIExecuteResultBlock)block;

/**
 *  Get spot metering area index
 *
 *  @param block Remote execute result
 */
-(void) getCameraSpotMeteringAreaWithResult:(void(^)(uint8_t areaIndex, DJIError* error))block;

/**
 *  Set camera shutter speed. the avaliable value of shutterSpeed is defined as DJICameraShutterSpeedx.
 *
 *  attention:
 *    the shutterSpeed should not faster then the video frame rate when the camera is under CameraWorkModeRecord. for example: video frame rate = 30fps, then the shutterSpeed must <= 1/30. CameraWorkModeCapture has no any limitation.
 *
 *  @param shutterSpeed Shutter speed set to camear
 *  @param block        Remote execute result
 */
-(void) setCameraShutterSpeed:(double)shutterSpeed withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's shutter speed settings
 *
 *  @param block Remote execute result
 */
-(void) getCameraShutterSpeedWithResult:(void(^)(double shutterSpeed, DJIError* error))block;


/**
 *  Set camera's Colour temperature.
 *
 *  @param temperature Colour temperature in range [20, 100]
 *  @param block       Remote execute result
 */
-(void) setCameraColourTemperature:(uint8_t)temperature withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's colour temperature settings
 *
 *  @param block Remote execute result
 */
-(void) getCameraColourTemperatureWithResult:(void(^)(uint8_t temperature, DJIError* error))block;

/**
 *  Set camera's saturation
 *
 *  @param saturation Saturation in range [-3, 3]
 *  @param block      Remote execute result
 */
-(void) setCameraSaturation:(int8_t)saturation withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's saturation
 *
 *  @param block Remote execute result
 */
-(void) getCameraSaturationWithResult:(void(^)(int8_t saturation, DJIError* error))block;

/**
 *  Set camera's Hue
 *
 *  @param hue   Hue in range [-3, 3]
 *  @param block Remote execute result
 */
-(void) setCameraHue:(int8_t)hue withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's hue settings
 *
 *  @param block Remote execute result
 */
-(void) getCameraHueWithResult:(void(^)(int8_t hue, DJIError* error))block;

/**
 *  Set camera's digital filter.
 *
 *  @param filter Digital filter set to camera
 *  @param block  Remote execute result
 */
-(void) setCameraDigitalFilter:(CameraDigitalFilter)filter withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's digital filter settings
 *
 *  @param block Remote execute result
 */
-(void) getCameraDigitalFilterWithResult:(void(^)(CameraDigitalFilter filter, DJIError* error))block;

/**
 *  Set camra's file index mode. if set as CameraFileIndexReset, the new file will be start as index 1 when you change a new SD card.
 *
 *  @param fileIndex File index mode set to camera
 *  @param result    Remote execute result
 */
-(void) setCameraFileIndexMode:(CameraFileIndexMode)fileIndex withResult:(DJIExecuteResultBlock)result;

/**
 *  Get camera's file index mode.
 *
 *  @param result Remote execute result
 */
-(void) getCameraFileIndexModeWithResult:(void(^)(CameraFileIndexMode fileIndex, DJIError* error))result;

/**
 *  Set camera's AEB continue capture parameters
 *
 *  @param aebParam AEB capture parameters set to camera
 *  @param result   Remote execute result
 */
-(void) setCameraAEBParam:(CameraAEBParam)aebParam withResult:(DJIExecuteResultBlock)result;

/**
 *  Get camera's AEB parameters
 *
 *  @param result Remote execute result
 */
-(void) getCameraAEBParamWithResult:(void(^)(CameraAEBParam aeb, DJIError* error))result;

/**
 *  Set camera AE lock
 *
 *  @param isLock Lock or unlock AE
 *  @param result Remote execute result
 */
-(void) setCameraAELock:(BOOL)isLock withResult:(DJIExecuteResultBlock)result;

/**
 *  Get camera's AE lock status
 *
 *  @param result Remote execute result
 */
-(void) getCameraAELockWithResult:(void(^)(BOOL isLocked, DJIError* error))result;

@end

@interface DJIInspireCamera (CameraPlayback)

/**
 *  Enter multiple edit mode. The camera work mode should be CameraWorkModePlayback
 */
-(void) enterMultipleEditMode;

/**
 *  Exit multiple edit mode.
 */
-(void) exitMultipleEditMode;

/**
 *  Select a file at index
 *
 *  @param index File at index to be select
 */
-(void) selectFileAtIndex:(int)index;

/**
 *  Unselect file at index
 *
 *  @param index File at index unselect
 */
-(void) unselectFileAtIndex:(int)index;

/**
 *  Select all files on the SD card
 */
-(void) selectAllFiles;

/**
 *  Unselect all files
 */
-(void) unselectAllFiles;

/**
 *  Select all file in current page
 */
-(void) selectAllFilesInPage;

/**
 *  Unselect all file in current page
 */
-(void) unselectAllFilesInPage;

/**
 *  Delete all selected files
 */
-(void) deleteAllSelectedFiles;

/**
 *  Download the selected files.  The camera work mode will be auto changed to CameraWorkModeDownload
 *
 *  @param prepareBlock File prepare for download callback
 *  @param dataBlock    File data downloaded callback
 *  @param completion   File download completed callback
 */
-(void) downloadAllSelectedFilesWithPreparingBlock:(DJIFileDownloadPreparingBlock)prepareBlock dataBlock:(DJIFileDownloadingBlock)dataBlock completionBlock:(DJIFileDownloadCompletionBlock)completion;

/**
 *  Enter multiple file preview mode. The camera work mode should be CameraWorkModePlayback
 */
-(void) enterMultiplePreviewMode;

/**
 *  Go to next page
 */
-(void) multiplePreviewNextPage;

/**
 *  Back to previous page
 */
-(void) multiplePreviewPreviousPage;

/**
 *  Enter single file preview mode. The camera work mode should be CameraWorkModePlayback
 *
 *  @param index File to be preview
 */
-(void) enterSinglePreviewModeWithIndex:(uint8_t)index;

/**
 *  Go to next file
 */
-(void) singlePreviewNextPage;

/**
 *  Back to previous file
 */
-(void) singlePreviewPreviousPage;

/**
 *  Delete current previewing file
 */
-(void) deleteCurrentPreviewFile;

/**
 *  Set photo's zoom scale
 *
 *  @param scale scale is in range [0, 1]. if scale is negative value, then enter mutiple preview mode automatically.
 */
-(void) setPhotoZoomScale:(float)scale;

/**
 *  Move photo center coordinate to specific position.
 *
 *  @param position Position to be move to
 */
-(void) movePhotoCenterCoordinateTo:(CGPoint)position;

/**
 *  Start video playback. The slected file should be a video file.
 */
-(void) startVideoPlayback;

/**
 *  Pause video playback.
 */
-(void) pauseVideoPlayback;

/**
 *  Stop video playback
 */
-(void) stopVideoPlayback;

/**
 *  Play from specific location.
 *
 *  @param location location in range [0, 100]
 */
-(void) setVideoPlaybackFromLocation:(uint8_t)location;

/**
 *  Set camera's quick view parameters
 *
 *  @param param Quick view parameters set to camera
 *  @param block Remote execute result
 */
-(void) setCameraQuickViewParam:(CameraQuickViewParam)param withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's quick view parameters
 *
 *  @param block Remote execute result
 */
-(void) getCameraQuickViewParamWithResult:(void(^)(CameraQuickViewParam param, DJIError* error))block;

@end


@interface DJIInspireCamera (VideoSettings)

/**
 *  Set camera's video quality
 *
 *  @param quality Video quality set to camera
 *  @param block   Remote execute result
 */
-(void) setCameraVideoQuality:(VideoQuality)quality withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's video quality
 *
 *  @param block Remote execute result
 */
-(void) getCameraVideoQualityWithResult:(void(^)(VideoQuality quality, DJIError* error))block;

/**
 *  Set camera's video resolution and frame rate. The supported resolution and frame rate is below:
 *  PAL:4096x2160P_24fps
        4096x2160P_25fps
        3840x2160P_24fps
        3840x2160P_25fps
        1920x1080P_24fps
        1920x1080P_25fps
        1920x1080P_48fps
        1920x1080P_50fps
        1280x720P_24fps
        1280x720P_25fps
        1280x720P_48fps
        1280x720P_50fps
 
   NTSC:4096x2160P_24fps
        3840x2160P_24fps
        3840x2160P_30fps
        1920x1080P_24fps
        1920x1080P_30fps
        1920x1080P_48fps
        1920x1080P_60fps
        1280x720P_24fps
        1280x720P_30fps
        1280x720P_48fps
        1280x720P_60fps
 *
 *  @param resolution Resolute of video
 *  @param rate       Frame rate of video
 *  @param block      Remote execute result
 */
-(void) setCameraVideoResolution:(CameraVideoResolution)resolution andFrameRate:(CameraVideoFrameRate)rate withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's video resolution and frame rate
 *
 *  @param block Remote execute result
 */
-(void) getCameraVideoResolutionAndFrameRate:(void(^)(CameraVideoResolution resolution, CameraVideoFrameRate rate, DJIError* error))block;

/**
 *  Set camera's video storage format
 *
 *  @param format Storage format for video
 *  @param block  Remote execute result
 */
-(void) setCameraVideoStorageFormat:(CameraVideoStorageFormat)format withResult:(DJIExecuteResultBlock)block;

/**
 *  Get camera's video storage format settings
 *
 *  @param block Remote execute result
 */
-(void) getCameraVideoStorageFormatWithResult:(void(^)(CameraVideoStorageFormat format, DJIError* error))block;

/**
 *  Set camera's video standard.
 *
 *  @param videoStandard Video standard set to camera
 *  @param result        Remote execute result
 */
-(void) setCameraVideoStandard:(CameraVideoStandard)videoStandard withResult:(DJIExecuteResultBlock)result;

/**
 *  Get camera's video staandard.
 *
 *  @param result Remote execute result
 */
-(void) getCameraVideoStandardWithResult:(void(^)(CameraVideoStandard videoStandard, DJIError* error))result;


@end
