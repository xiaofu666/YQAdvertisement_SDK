//
//  SFDrawVideoAdManager.h
//  YXLaunchAds
//
//  Created by lurich on 2020/5/9.
//  Copyright © 2020 YX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wquoted-include-in-framework-header"
#import "YXLaunchConfiguration.h"
#pragma clang diagnostic pop

@class YXFeedAdData;

NS_ASSUME_NONNULL_BEGIN

@protocol SFDrawVideoAdDelegate<NSObject>
@optional

/**
 加载成功的回调
 
 @param data  回调的广告素材
 */
- (void)didLoadDrawVideoFeedAd:(NSArray<YXFeedAdData *> *)data;

/**
 取广告失败调用
 
 @param error 为错误信息
 */
- (void)didFailedLoadFeedAd:(NSError *)error;

/**
 广告点击后回调
 */
- (void)didClickedFeedAd;

@end

@interface SFDrawVideoAdManager : NSObject

@property(nonatomic,weak) id<SFDrawVideoAdDelegate> delegate;
/**
宽度默认屏幕宽度,高度自适应
 */
@property (nonatomic, assign) CGFloat s2sWidth;
@property (nonatomic, assign) CGFloat s2sHeight;

/**  媒体位Id  */
@property (nonatomic,copy) NSString *mediaId;

/**
 广告数量 默认为1
 */
@property (nonatomic,assign) NSInteger adCount;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;


/**  开始加载广告  */
- (void)loadFeedAd;

/**
 定义原生广告视图中可以点击的 视图区域，行为由SDK控制
 @param view 原生广告的视图，完整可点击区域
 */
- (void)registerAdViewForInteraction:(UIView *)view adData:(YXFeedAdData*)adData clickableViews:(NSArray *)views;

@end

NS_ASSUME_NONNULL_END
