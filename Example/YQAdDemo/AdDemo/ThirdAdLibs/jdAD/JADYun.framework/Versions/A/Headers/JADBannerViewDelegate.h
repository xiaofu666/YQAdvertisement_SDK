//
//  JADBannerViewDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/18.
//

#ifndef JADBannerViewDelegate_h
#define JADBannerViewDelegate_h

#import <Foundation/Foundation.h>
#import "JADNativeAdData.h"

@class JADBannerView;

NS_ASSUME_NONNULL_BEGIN

/// The methods declared by the JADBannerViewDelegate protocol allow the adopting delegate to respond to messages from the JADBannerView class and thus respond to operations such as whether the ad has been loaded, the person has clicked the ad.
@protocol JADBannerViewDelegate<NSObject>

@optional

/**
 * Sent when an ad has been successfully loaded.
 * 广告数据：加载成功
 */
- (void)jadBannerViewDidLoad:(JADBannerView *)bannerView;

/**
 * Sent after an JADBannerView fails to load the ad.
 * 广告数据：加载失败
 */
- (void)jadBannerView:(JADBannerView *)bannerView didFailWithError:(NSError * __nullable)error;

/**
 * This method is called when rendering a bannerView succeed.
 * 广告视图：渲染完成
 */
- (void)jadBannerViewRenderSuccess:(JADBannerView *)bannerView;

/**
 * This method is called when a bannerView failed to render.
 * @param error : the reason of error
 * 广告视图：渲染失败
 */
- (void)jadBannerViewRenderFail:(JADBannerView *)bannerView error:(NSError * __nullable)error;

/**
 * Sent immediately before the impression of an JADBannerView object will be logged.
 * 广告视图：曝光
 */
- (void)jadBannerViewWillVisible:(JADBannerView *)bannerView;

/**
 * Sent after an ad has been clicked by the person.
 * 广告视图：点击
 */
- (void)jadBannerViewDidClick:(JADBannerView *)bannerView;

/**
 * Sent after a full screen content has been dismissed.
 * 广告视图：关闭
 */
- (void)jadBannerViewDidClose:(JADBannerView *)bannerView;

/**
 * This method is called when another controller has been closed.
 * @param interactionType ： open AppStore in app or open the webpage
 */
- (void)jadBannerViewDidCloseOtherController:(JADBannerView *)bannerView
                             interactionType:(JADInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END

#endif /* JADBannerViewDelegate_h */
