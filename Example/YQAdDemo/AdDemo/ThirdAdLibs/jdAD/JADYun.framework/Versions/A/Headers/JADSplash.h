//
//  JADSplash.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JADSplashDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/// A customized UIView to represent a JADYun ad (splash ad).
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.0; please adopt JADSplashView") @interface JADSplash : UIView

/// the delegate
@property (nonatomic, weak) id<JADSplashDelegate> delegate;

/**
 Maximum allowable load timeout, default 5s, unit s.
 */
@property (nonatomic, assign) NSTimeInterval tolerateTime;

/**
 Splash allowable skip timeout, default 5s, unit s.
 */
@property (nonatomic, assign) NSTimeInterval skipTime;

/**
 * 初始化开屏广告
 * @param placementID 代码位ID
 * @param size 开屏广告尺寸
 * @param rootViewController Handling ad actions
 * @param isSupportDeepLink 注意：该参数已失效
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)size
                 rootViewController:(UIViewController *)rootViewController
                  isSupportDeepLink:(BOOL)isSupportDeepLink
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.2; use initWithPlacementID: adSize: rootViewController: ");

/**
 * 初始化开屏广告
 * @param placementID 代码位ID
 * @param size 开屏广告尺寸
 * @param rootViewController Handling ad actions
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)size
                 rootViewController:(UIViewController *)rootViewController;

/**
 * Load splash ad datas.
*/
- (void)loadAd;

/**
 * Display splash ad.
 * @param window : window for displaying ad.
*/
- (void)showWithWindow:(UIWindow *)window;

@end

NS_ASSUME_NONNULL_END
