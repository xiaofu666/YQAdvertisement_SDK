//
//  JADBanner.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JADBannerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/// A customized UIView to represent a JADYun ad (banner ad).
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.0; please adopt JADBannerView") @interface JADBanner : UIView

@property (nonatomic, readonly, nullable) NSString *placementID;

/// the delegate
@property (nonatomic, weak) id<JADBannerDelegate> delegate;

/// hide close button
@property (nonatomic, assign) BOOL hideCloseButton;

/// The banner's ad placement ID.
- (NSString *)placementID;

/**
 * 初始化横幅广告view
 * @param placementID 代码位ID
 * @param adSize 代码位大小，注意：与管理平台的配置保持一致
 * @param rootViewController 代码位所在的UIViewController
 * @param isSupportDeepLink 注意：该参数已失效
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)adSize
                 rootViewController:(UIViewController *)rootViewController
                  isSupportDeepLink:(BOOL)isSupportDeepLink
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.2; use initWithPlacementID: adSize: rootViewController: ");

/**
 * 初始化横幅广告view
 * @param placementID 代码位ID
 * @param adSize 代码位大小，注意：与管理平台的配置保持一致
 * @param rootViewController 代码位所在的UIViewController
*/
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)adSize
                 rootViewController:(UIViewController *)rootViewController;

/**
 * Begins loading the JADBanner content.
 */
- (void)loadAndShow;

@end

NS_ASSUME_NONNULL_END
