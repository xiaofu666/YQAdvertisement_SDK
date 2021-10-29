//
//  SFNativeVideoADManager.h
//  AdDemo
//
//  Created by lurich on 2021/6/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class YXFeedAdData;

NS_ASSUME_NONNULL_BEGIN

@protocol SFNativeVideoAdManagerDelegate<NSObject>
@optional

/**
 加载成功的回调
 @param time 广告总时长
 */
- (void)didLoadNativeVideoAdWithDuation:(double)time;

/**
 取广告失败调用
 @param error 为错误信息
 */
- (void)didFailedLoadNativeVideoAd:(NSError* _Nonnull)error;

/**
 广告点击后回调
 */
- (void)didClickedNativeVideoAd;

/**
 落地页或者appstoe返回事件，方便用户做返回后的处理工作
 */
-(void)didNativeVideoAdShowReturn;

/**
 *  倒计时回调
 *  @param duration 倒计时时间
 */
-(void)didNativeVideoAdDuration:(NSInteger)duration;

/**
  贴片广告播放完成
 */
- (void)didPlayFinishNativeVideoAd;

@end

@interface SFNativeVideoADManager : NSObject

@property(nonatomic,weak) id<SFNativeVideoAdManagerDelegate> delegate;

/**
 请求视频的时长下限。
 以下两种情况会使用 0，1:不设置  2:minVideoDuration大于maxVideoDuration
*/
@property (nonatomic) NSInteger minVideoDuration;

/**
 请求视频的时长上限，视频时长有效值范围为[5,180]。
 */
@property (nonatomic) NSInteger maxVideoDuration;

/**
 是否循环播放广告视频，自定义广告时长时，可选择循环播放，default: NO
 */
@property (nonatomic, assign, getter=isRunPlay) BOOL runPlay;

/**  媒体位Id  */
@property (nonatomic,copy) NSString *mediaId;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;


/**  开始加载广告  */
- (void)loadNativeVideoAdWithBackView:(UIView *)backView;

/**
 在播放音频时, 默认使用AVAudioSession设置的category及options，
 SDK设置的category为AVAudioSessionCategoryAmbient，options为AVAudioSessionCategoryOptionDuckOthers
 若调用方想自定义，可在展示广告时自行设置；
 示例代码：
 [[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryPlayback withOptions:AVAudioSessionCategoryOptionDuckOthers error:nil];
 */
/**  开始播放广告  */
- (void)showNativeVideoAd;

/**  停止视频广告播放  */
- (void)stopVideoPlay;


@end

NS_ASSUME_NONNULL_END
