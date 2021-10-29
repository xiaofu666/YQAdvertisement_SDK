//
//  JADBannerView.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "JADYunConstant.h"
#import "JADBannerViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/// A customized UIView to represent a JADYun ad (banner ad).
@interface JADBannerView : UIView

/**
 * The bannerView's ad placement ID.
 * 属性：代码位ID
 */
@property (nonatomic, strong, readonly, nullable) NSString *placementID;

/**
 * hide close button
 * 隐藏关闭按钮属性
 */
@property (nonatomic, assign) BOOL hideCloseButton;

/**
 * The bannerView's ad delegate.
 * banner视图 delegate
 */
@property (nonatomic, weak) id<JADBannerViewDelegate> delegate;

/**
 * Ad price
 * 广告价格（单位：分）
 */
@property (nonatomic, assign, readonly) NSInteger price;

/**
 * 触发点击事件的手势类型
 */
@property (nonatomic, assign) JADClickEventTriggerType triggerType;


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
 * Load banner view ad data.
 * 加载banner广告
 */
- (void)loadAdData;

@end

NS_ASSUME_NONNULL_END
