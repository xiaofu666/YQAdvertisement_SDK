//
//  YXLaunchAdManager.h
//  YXLaunchAdExample

//  Created by shuai on 2018/3/23.
//  Copyright © 2018年 M. All rights reserved.
//  Version 2.4

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wquoted-include-in-framework-header"
#import "YXLaunchConfiguration.h"
#pragma clang diagnostic pop

//广告代理
@protocol YXLaunchAdManagerDelegate <NSObject>
@optional
/**
 加载成功的回调
 @param view  回调的view（开屏的时候返回nil）
 */
- (void)didLoadAd:(UIView *_Nullable)view;
/**
 取广告失败调用
 @param error 为错误信息
 */
- (void)didFailedLoadAd:(NSError *_Nonnull)error;
/**
 广告结束 移除window中的视图
 */
- (void)LaunchShowFinish;
/**
 广告点击后回调
 */
- (void)didClickedAdWithUrlStr:(NSString *_Nonnull)urlStr;
/**
 落地页或者appstoe返回事件，方便用户做返回后的处理工作
 */
-(void)didAdShowReturn;
/**
 跳过按钮点击回调
 */
- (void)lunchADSkipButtonClick;
/**
 *  倒计时回调
 *  @param duration 倒计时时间
 */
-(void)customSkipDuration:(NSInteger)duration; 

@end

@interface YXLaunchAdManager : NSObject

@property(nonatomic, weak) id<YXLaunchAdManagerDelegate> _Nullable delegate;

/**  媒体位Id  */
@property (nonatomic, copy, nonnull) NSString *mediaId;

/**
 1. 全屏接入：bottomView 不传入
 2. 半屏接入：bottomView 传入logo的view
 */
/** 设置半屏广告的所含 logo 的 view  */
@property (nonatomic,strong) UIView * _Nullable bottomView;

// 以下为可选参数
///** 缓存机制(default YXLaunchImageDefault) */
@property(nonatomic,assign)YXLaunchAdImageOptions imageOption;

/** 设置开屏广告的停留时间default 5s （建议在 4s-5s 内） */
@property(nonatomic,assign)NSInteger duration;
/**
 设置开屏广告的等待时间 default 3s （建议在 3s-5s 内）
 1.因为数据请求是异步的,请在数据请求前,调用下面方法配置数据等待时间.
 2.设为5即表示:启动页将停留5s等待服务器返回广告数据,5s内等到广告数据,将正常显示广告,否则将不显示
 3.数据获取成功,配置广告数据后,自动结束等待,显示广告
 */
@property(nonatomic,assign)NSInteger waitDataDuration;

/** 显示完成动画时间(default 0.8 , 单位:秒) */
@property(nonatomic,assign)CGFloat showFinishAnimateTime;

/** 显示完成动画(default ShowFinishAnimateFadein) */
@property(nonatomic,assign)ShowFinishAnimate showFinishAnimate;

/** 跳过按钮类型(default SkipTypeTimeText) */
@property(nonatomic,assign)SkipType skipButtonType;

/** 图片广告缩放模式(default UIViewContentModeScaleToFill) */
@property(nonatomic,assign)UIViewContentMode contentMode;

/** 倒计时结束自动关闭开屏广告(default YES) */
@property (nonatomic, assign) BOOL autoClose;

/** 是否显示默认背景(default NO) */
@property (nonatomic, assign) BOOL showBackImage;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController * _Nullable showAdController;

/**  开始加载广告  */
- (void)loadLaunchAdWithShowAdWindow:(UIWindow *_Nonnull)showAdWindow;

@end
