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

@protocol YXImageTextAdManagerDelegate<NSObject>
@optional
/**
 加载成功的回调
 
 @param data  回调的广告素材
 */
- (void)didLoadFeedAd:(NSArray<YXFeedAdData*>*_Nullable)data;
/**
 取广告失败调用
 
 @param error 为错误信息
 */
- (void)didFailedLoadFeedAd:(NSError* _Nonnull)error;
/**
 广告点击后回调
 */
- (void)didClickedFeedAd;
/**
 广告被关闭
 */
- (void)nativeExpressAdClose;
/**
 广告渲染成功
 */
- (void)didFeedAdRenderSuccess:(NSArray<YXFeedAdData *> *)data;
/**
 广告渲染失败
 */
- (void)didFeedAdRenderFail;

@end

@interface SFNativeExpressAdManager : NSObject

@property(nonatomic,weak) id<YXImageTextAdManagerDelegate> delegate;
/**
宽度默认屏幕宽度,高度自适应
 */
@property (nonatomic, assign) CGFloat s2sWidth;
@property (nonatomic, assign) CGFloat s2sHeight;

/**  媒体位Id  */
@property (nonatomic,copy) NSString *mediaId;

/**
 广告数量,不传则后台控制
 */
@property (nonatomic,assign) NSInteger adCount;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;


/**  开始加载广告  */
- (void)loadNativeExpressFeedAd;

@end

NS_ASSUME_NONNULL_END
