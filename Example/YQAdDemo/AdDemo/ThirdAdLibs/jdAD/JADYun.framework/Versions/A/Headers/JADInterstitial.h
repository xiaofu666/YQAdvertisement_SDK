//
//  ANInterstitial.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JADInterstitialDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/// A customized UIView to represent a JADYun ad (interstitial ad).
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.0; please adopt JADInterstitialView") @interface JADInterstitial : UIView

/// the delegate
@property (nonatomic, weak) id<JADInterstitialDelegate> delegate;

/// The interstitial's ad placement ID.
- (NSString *)placementID;

/**
 * 初始化插屏广告view
 * @param placementID 代码位ID
 * @param adSize 代码位的大小，请确保：size 的 width : height = 1:1 or 2:3 or 3:2
 * @param isSupportDeepLink 注意：该参数已失效
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)adSize
                  isSupportDeepLink:(BOOL)isSupportDeepLink
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.2; use initWithPlacementID: adSize: ");

/**
 * 初始化插屏广告view
 * @param placementID 代码位ID
 * @param adSize 代码位的大小，请确保：size 的 width : height = 1:1 or 2:3 or 3:2
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)adSize;
/**
 * Load interstitial ad datas.
*/
- (void)loadAd;

/**
 * Display interstitial ad.
 * @param rootViewController : root view controller for displaying ad.
*/
- (void)showWithViewController:(UIViewController *)rootViewController;


@end

NS_ASSUME_NONNULL_END
