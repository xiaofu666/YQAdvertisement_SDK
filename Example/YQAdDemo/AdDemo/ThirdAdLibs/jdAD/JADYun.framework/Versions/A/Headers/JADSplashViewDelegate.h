//
//  JADSplashViewDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/18.
//

#ifndef JADSplashViewDelegate_h
#define JADSplashViewDelegate_h

#import "JADNativeAdData.h"

@class JADSplashView;

NS_ASSUME_NONNULL_BEGIN

@protocol JADSplashViewDelegate<NSObject>

@optional

/**
 * This method is called when splash ad material loaded successfully.
 * 广告数据：加载完成
 */
- (void)jadSplashViewDidLoad:(JADSplashView *)splashView;

/**
 * This method is called when splash ad material failed to load.
 * @param error : the reason of error
 * 广告数据：加载失败
 */
- (void)jadSplashView:(JADSplashView *)splashView didFailWithError:(NSError * __nullable)error;

/**
 * This method is called when rendering a splash ad succeed.
 * 广告视图：渲染完成
 */
- (void)jadSplashViewRenderSuccess:(JADSplashView *)splashView;

/**
 * This method is called when a splash ad failed to render.
 * @param error : the reason of error
 * 广告视图：渲染失败
 */
- (void)jadSplashViewRenderFail:(JADSplashView *)splashView error:(NSError * __nullable)error;

/**
 * This method is called when splash ad slot will be showing.
 * 广告视图：曝光
 */
- (void)jadSplashViewWillVisible:(JADSplashView *)splashView;

/**
 * This method is called when splash ad is clicked.
 * 广告视图：点击
 */
- (void)jadSplashViewDidClick:(JADSplashView *)splashView;

/**
 * This method is called when splash ad is closed.
 * 广告视图：关闭
 */
- (void)jadSplashViewDidClose:(JADSplashView *)splashView;

/**
 * This method is called when another controller has been closed.
 * @param interactionType ： open AppStore in app or open the webpage
 */
- (void)jadSplashViewDidCloseOtherController:(JADSplashView *)splashView
                             interactionType:(JADInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END
#endif /* JADSplashViewDelegate_h */
