//
//  JADBannerDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#ifndef JADBannerDelegate_h
#define JADBannerDelegate_h

#import <Foundation/Foundation.h>

@class JADBanner;

NS_ASSUME_NONNULL_BEGIN

/// The methods declared by the JADBannerDelegate protocol allow the adopting delegate to respond to messages from the JADBanner class and thus respond to operations such as whether the ad has been loaded, the person has clicked the ad.
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.0; please adopt JADBannerViewDelegate") @protocol JADBannerDelegate<NSObject>

@optional

/**
 * Sent when an ad has been successfully loaded.
 */
- (void)jadBannerDidLoad:(JADBanner *)banner;

/**
 * Sent after an ANBanner fails to load the ad.
 */
- (void)jadBanner:(JADBanner *)banner didFailWithError:(NSError * __nullable)error;

/**
 * This method is called when rendering a nativeExpressAdView successed.
 */
- (void)jadBannerRenderSuccess:(JADBanner *)banner;

/**
 * This method is called when a nativeExpressAdView failed to render.
 * @param error : the reason of error
 */
- (void)jadBannerRenderFail:(JADBanner *)banner error:(NSError * __nullable)error;

/**
 * Sent immediately before the impression of an ANBanner object will be logged.
 */
- (void)jadBannerWillVisible:(JADBanner *)banner;

/**
 * Sent after an ad has been clicked by the person.
 */
- (void)jadBannerDidClick:(JADBanner *)banner;

/**
 * Sent after a full screen content has been dismissed.
 */
- (void)jadBannerDidClose:(JADBanner *)banner;

@end

NS_ASSUME_NONNULL_END

#endif /* JADBannerDelegate_h */
