//
//  JADInterstitialDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#ifndef ANInterstitialDelegate_h
#define ANInterstitialDelegate_h

@class JADInterstitial;

NS_ASSUME_NONNULL_BEGIN

/// The methods declared by the JADInterstitialDelegate protocol allow the adopting delegate to respond to messages from the JADInterstitial class and thus respond to operations such as whether the interstitial ad has been loaded.
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.0; please adopt JADInterstitialViewDelegate") @protocol JADInterstitialDelegate <NSObject>

@optional

/**
 * This method is called when interstitial ad material loaded successfully.
 */
- (void)jadInterstitialDidLoad:(JADInterstitial *)interstitial;

/**
 * This method is called when interstitial ad material failed to load.
 * @param error : the reason of error
 */
- (void)jadInterstitial:(JADInterstitial *)interstitial didFailWithError:(NSError * __nullable)error;

/**
 * This method is called when rendering a interstitial ad successed.
 */
- (void)jadInterstitialRenderSuccess:(JADInterstitial *)interstitial;

/**
 * This method is called when a interstitial ad failed to render.
 * @param error : the reason of error
 */
- (void)jadInterstitialRenderFail:(JADInterstitial *)interstitial error:(NSError * __nullable)error;

/**
 * This method is called when interstitial ad  will be showing.
 */
- (void)jadInterstitialWillVisible:(JADInterstitial *)interstitial;

/**
 * This method is called when interstitial ad is clicked.
 */
- (void)jadInterstitialDidClick:(JADInterstitial *)interstitial;

/**
 * This method is called when interstitial ad is closed.
 */
- (void)jadInterstitialDidClose:(JADInterstitial *)interstitial;
@end

NS_ASSUME_NONNULL_END


#endif /* ANInterstitialDelegate_h */
