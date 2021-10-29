//
//  JADSplashView.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "JADYunConstant.h"
#import "JADSplashViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, JADSplashStyle) {
    JADSplashStyleServerConfig,     // 采用服务端配置
    JADSplashStyleOnlyText,         // 只显示文案，全屏可点击
    JADSplashStyleOnlyTextClick,    // 只有文案部分可点击
    JADSplashStyleNormal,           // 不处理，无文案，全屏可点击
};

/// A customized UIView to represent a JADYun ad (splash ad).
@interface JADSplashView : UIView

/**
 * The splashView's ad placement ID.
 * 属性：代码位ID
 */
@property (nonatomic, strong, readonly, nullable) NSString *placementID;

/**
 * The splashView's ad delegate.
 * 开屏视图 delegate
 */
@property (nonatomic, weak) id<JADSplashViewDelegate> delegate;

/**
 Maximum allowable load timeout, default 5s, unit s.
 加载广告最大容忍时长，默认5s
 */
@property (nonatomic, assign) NSTimeInterval tolerateTime;

/**
 Splash allowable skip timeout, default 5s, unit s.
 开屏广告跳过时长，默认5s
 */
@property (nonatomic, assign) NSTimeInterval skipTime;

/**
 * Ad price
 * 广告价格（单位：分）
 */
@property (nonatomic, assign, readonly) NSInteger price;

/**
 * 开屏样式
 */
@property (nonatomic, assign) JADSplashStyle splashStyle;

/**
 * 触发点击事件的手势类型
 */
@property (nonatomic, assign) JADClickEventTriggerType triggerType;

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
 * @param rootViewController 落地页跳转所需控制器
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)size
                 rootViewController:(UIViewController *)rootViewController;

/**
 * Load splash ad data.
 * 加载开屏广告
*/
- (void)loadAdData;

@end

NS_ASSUME_NONNULL_END
