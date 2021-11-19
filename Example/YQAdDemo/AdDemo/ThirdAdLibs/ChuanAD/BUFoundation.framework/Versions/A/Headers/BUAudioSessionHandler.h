//
//  BUMuteMonitor.h
//  BUFoundation
//
//  Created by bytedance on 2021/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 用于回调当前静音按钮是否为静音状态的block

 @param isMute 如果静音按钮当前为静音状态，则为YES，否则为NO
 */
typedef void(^MuteBlock)(BOOL isMute);

/**
 用于回调当前真实音量的block
 
 @param currentRealVolume 当前的真实音量
 */
typedef void(^RealVolumeBlock)(CGFloat currentRealVolume);

/**
 用于监听音量变化的block
 @param newVolume 新的音量值
 */
typedef void(^VolumeChangeBlock)(CGFloat newVolume);

@interface BUAudioSessionSetting : NSObject

@property (nonatomic, assign) BOOL allowModifyAudioSessionSetting;

@property (nonatomic, copy) NSString *sourcePath;

+ (instancetype)shareInstance;

- (void)monitorMute;

- (void)saveAudioSessionOriginCategory;

@end


@interface BUAudioSessionHandler : NSObject

- (void)resetAudioSessionCategoryToOriginStatus;

- (void)interruptOtherAudioPlayingWithMute:(BOOL)mute;

@end

NS_ASSUME_NONNULL_END
