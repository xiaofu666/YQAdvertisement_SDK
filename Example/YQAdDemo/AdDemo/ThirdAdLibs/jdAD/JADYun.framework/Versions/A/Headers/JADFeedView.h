//
//  JADFeedView.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "JADYunConstant.h"
#import "JADFeedViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/// A customized UIView to represent a JADYun ad (feed ad).
@interface JADFeedView : UIView

/**
 * The feedView's ad placement ID.
 * 属性：代码位ID
 */
@property (nonatomic, strong, readonly, nullable) NSString *placementID;

/**
 * The feedView's ad delegate.
 * 信息流视图 delegate
 */
@property (nonatomic, weak, nullable) id<JADFeedViewDelegate> delegate;

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
 * 初始化信息流广告
 * @param placementID 代码位ID
 * @param adSize 代码位大小
 * @param isSupportDeepLink 注意：该参数已失效
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)adSize
                  isSupportDeepLink:(BOOL)isSupportDeepLink
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.2; use initWithPlacementID: adSize: ");

/**
 * 初始化信息流广告
 * @param placementID 代码位ID
 * @param adSize 代码位大小
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                             adSize:(CGSize)adSize;

/**
 * Load feed view ad data.
 * 加载信息流广告
*/
- (void)loadAdData;

@end

NS_ASSUME_NONNULL_END
