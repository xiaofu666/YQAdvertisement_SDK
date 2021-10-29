//
//  JADInterstitialAdDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/20.
//

#ifndef JADInterstitialAdDelegate_h
#define JADInterstitialAdDelegate_h

#import "JADNativeAdData.h"

@class JADInterstitialAd;

NS_ASSUME_NONNULL_BEGIN

/// The methods declared by the JADInterstitialAdDelegate protocol allow the adopting delegate to respond to messages from the JADInterstitialAd class and thus respond to operations such as whether the interstitial ad has been loaded.
@protocol JADInterstitialAdDelegate <NSObject>

@optional

/**
 * This method is called when interstitial ad material loaded successfully.
 * 广告数据：加载完成
 */
- (void)jadInterstitialAdDidLoad:(JADInterstitialAd *)interstitialAd;

/**
 * This method is called when interstitial ad material failed to load.
 * @param error : the reason of error
 * 广告数据：加载失败
 */
- (void)jadInterstitialAd:(JADInterstitialAd *)interstitialAd didFailWithError:(NSError * __nullable)error;

/**
 * This method is called when rendering a interstitial ad succeed.
 * 广告视图：渲染完成
 */
- (void)jadInterstitialAdRenderSuccess:(JADInterstitialAd *)interstitialAd;

/**
 * This method is called when a interstitial ad failed to render.
 * @param error : the reason of error
 * 广告视图：渲染失败
 */
- (void)jadInterstitialAdRenderFail:(JADInterstitialAd *)interstitialAd error:(NSError * __nullable)error;

/**
 * This method is called when interstitial ad  will be showing.
 * 广告视图：曝光
 */
- (void)jadInterstitialAdWillVisible:(JADInterstitialAd *)interstitialAd;

/**
 * This method is called when interstitial ad is clicked.
 * 广告视图：点击
 */
- (void)jadInterstitialAdDidClick:(JADInterstitialAd *)interstitialAd;

/**
 * This method is called when interstitial ad is closed.
 * 广告视图：关闭
 */
- (void)jadInterstitialAdDidClose:(JADInterstitialAd *)interstitialAd;

/**
 * This method is called when another controller has been closed.
 * @param interactionType ： open AppStore in app or open the webpage
 */
- (void)jadInterstitialAdDidCloseOtherController:(JADInterstitialAd *)interstitialAd
                                 interactionType:(JADInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END

#endif /* JADInterstitialAdDelegate_h */
