//
//  YXIconAdManager.h
//  LunchAd
//
//  Created by shuai on 2018/6/11.
//  Copyright © 2018年 YX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol YXIconAdManagerDelegate<NSObject>
@optional
/**
 加载成功的回调
 
 @param view  回调的view
 */
- (void)didLoadIconAd:(UIView *)view;
/**
 icon显示的回调
 
 @param view  回调的view
 */
- (void)didShowIconAd:(UIView *)view;
/**
 取广告失败调用
 
 @param error 为错误信息
 */
- (void)didFailedLoadIconAd:(NSError *)error;
/**
 广告点击后回调
 */
- (void)didClickedIconAd;

@end


@interface YXIconAdManager : UIView

@property (nonatomic,weak) id<YXIconAdManagerDelegate> delegate;

/*
 *  controller
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;
/**
 图片frame
 */
- (instancetype)initWithFrame:(CGRect)frame;

/**  媒体位Id  */
@property (nonatomic,copy) NSString *mediaId;


/**  开始加载广告  */
- (void)loadIconAd;

@end

NS_ASSUME_NONNULL_END
