//
//  YXFeedAdManager.h
//  LunchAd
//
//  Created by shuai on 2018/10/12.
//  Copyright © 2018年 YX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wquoted-include-in-framework-header"
#import "YXLaunchConfiguration.h"
#pragma clang diagnostic pop

@class YXFeedAdData;

NS_ASSUME_NONNULL_BEGIN

typedef void(^getADSucess) (YXFeedAdData *model);
typedef void(^getADFail) (NSError *error);

@interface SFSDKAdManager : NSObject

@property (nonatomic,assign) YXADSize adSize;

/**
 当adSize类型为YXADSizeCustom时，宽高必传，其余模式不用传
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

@property (nonatomic, assign) YXFeedAdType AdType;

@property (nonatomic, copy) getADSucess success;
@property (nonatomic, copy) getADFail   fail;

- (void)loadsingleFeedAdSuccess:(getADSucess)success fail:(getADFail)fail;

/**
 定义原生广告视图中可以点击的 视图区域，行为由SDK控制
 @param view 原生广告的视图所在的view，完整可点击区域
 */
- (void)registerAdViewForInteraction:(UIImageView *)view adData:(YXFeedAdData*)adData clickableViews:(NSArray *)views;

@end

NS_ASSUME_NONNULL_END
