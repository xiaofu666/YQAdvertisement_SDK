//
//  JADNativeAd.h
//  JADYun
//
//  Created by wangshuai331 on 2020/11/2.
//

#import <Foundation/Foundation.h>
#import "JADNativeAdSlot.h"
#import "JADNativeAdData.h"

@protocol JADNativeAdDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface JADNativeAd : NSObject

/**
 * 广告位描述信息
 */
@property (strong, nonatomic, readwrite, nullable) JADNativeAdSlot *adSlot;

/**
 * 广告返回数据
 */
@property (strong, atomic, readonly, nullable) NSArray<JADNativeAdData *> *data;

/**
 * 代理，里面包含了给开发者的回调事件
 */
@property (weak, nonatomic, readwrite, nullable) id<JADNativeAdDelegate> delegate;

/**
 * required.
 * 处理事件的控制器
 * 弹出落地页广告的控制器
 */
@property (weak, nonatomic, readwrite) UIViewController *rootViewController;

/**
 * 通过 ad slot 初始化 native ad
 * @param slot ：广告位描述信息，包括 slotID，adType...
 * @return ANNativeAd
 */
- (instancetype)initWithSlot:(JADNativeAdSlot *)slot;

/**
 * Register clickable views in native ads view.
 * @param containerView : required.
                        container view of the native ad.
 * @param clickableViews : optional.
                        Array of views that are clickable.
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews DEPRECATED_MSG_ATTRIBUTE("use registerContainer: withClickableViews: withClosableViews: ");

/**
 * Register clickable views in native ads view.
 * @param containerView : required.
                        container view of the native ad.
 * @param clickableViews : optional.
                        Array of views that are clickable.
 * @param closableViews : optional.
                        Array of views that are closable.
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews
        withClosableViews:(NSArray<__kindof UIView *> *_Nullable)closableViews;
/**
 * Unregister ad view from the native ad.
 */
- (void)unregisterView;

/**
 * Actively request nativeAd data.
 * 加载广告数据
 */
- (void)loadAdData;

@end

@protocol JADNativeAdDelegate <NSObject>

@optional

/**
 * This method is called when native ad material loaded successfully.
 * 广告数据：加载成功
 */
- (void)jadNativeAdDidLoad:(JADNativeAd *)nativeAd;

/**
 * This method is called when native ad materia failed to load.
 * @param error : the reason of error
 * 广告数据：加载失败
 */
- (void)jadNativeAd:(JADNativeAd *)nativeAd didFailWithError:(NSError *__nullable)error;

/**
 * This method is called when native ad slot has been shown.
 * 广告视图：曝光
 */
- (void)jadNativeAdDidBecomeVisable:(JADNativeAd *)nativeAd DEPRECATED_MSG_ATTRIBUTE("use jadNativeAdDidBecomeVisible: ");
- (void)jadNativeAdDidBecomeVisible:(JADNativeAd *)nativeAd;

/**
 * This method is called when native ad is clicked.
 * 广告视图：点击
 */
- (void)jadNativeAdDidClick:(JADNativeAd *)nativeAd withView:(UIView *_Nullable)view;

/**
 * This method is called when native ad is closed.
 * 广告视图：关闭
 */
- (void)jadNativeAdDidClose:(JADNativeAd *)nativeAd withView:(UIView *_Nullable)view;

/**
 * This method is called when another controller has been closed.
 * @param interactionType ： open AppStore in app or open the webpage
 */
- (void)jadNativeAdDidCloseOtherController:(JADNativeAd *)nativeAd
                           interactionType:(JADInteractionType)interactionType;

/**
 * This method is called when splash native ad is delay action.
 * 广告视图：开屏倒计时时间回调
 */
- (void)jadNativeAdForSplash:(JADNativeAd *)nativeAd countDown:(int)countDown;

@end

NS_ASSUME_NONNULL_END

