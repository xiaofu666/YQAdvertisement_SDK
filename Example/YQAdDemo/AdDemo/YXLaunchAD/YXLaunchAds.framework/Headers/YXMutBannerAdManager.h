//
//  YXMutBannerAdManager.h
//  LunchAd
//
//  Created by shuai on 2018/11/21.
//  Copyright © 2018 YX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wquoted-include-in-framework-header"
#import "YXLaunchConfiguration.h"
#pragma clang diagnostic pop

@class YXFeedAdData;

NS_ASSUME_NONNULL_BEGIN
@protocol YXMutBannerAdManagerDelegate<NSObject>
@optional
/**
 加载成功的回调
 */
- (void)didLoadMutBannerAdView;
/**
 取广告失败调用
 
 @param error 为错误信息
 */
- (void)didFailedLoadMutBannerAd:(NSError* _Nonnull)error;
/**
 广告点击后的回调   只有自投广告，该回调URLStr 才有值
 */
- (void)didClickedMutBannerAdWithIndex:(NSInteger)index UrlStr:(NSString *)urlStr;

@end
@interface YXMutBannerAdManager : NSObject

@property(nonatomic,weak) id<YXMutBannerAdManagerDelegate> delegate;

@property (nonatomic,assign) YXADSize  adSize __attribute__((deprecated("即将废弃")));

//轮播图弧度
@property (nonatomic, assign) CGFloat cornerRadius;

/**  媒体位Id  */
@property (nonatomic,copy) NSString *mediaId;

/** 是否只显示图片 */
@property (nonatomic, assign) BOOL isOnlyImage;

/**
 广告数量 默认为1
 */
@property (nonatomic,assign) NSInteger adCount;

/** 轮播图片的ContentMode，默认为 UIViewContentModeScaleToFill */
@property (nonatomic, assign) UIViewContentMode bannerImageViewContentMode;

/** 自动滚动间隔时间,默认3s */
@property (nonatomic, assign) CGFloat autoScrollTimeInterval;

/** 是否显示分页控件 */
@property (nonatomic, assign) BOOL showPageControl;

/** 是否在只有一张图时隐藏pagecontrol，默认为YES */
@property(nonatomic) BOOL hidesForSinglePage;

/**
 pagecontrol 样式，默认为系统自带经典样式
 当为 YXBannerScrollViewPageImage 前缀样式时，必须传入分页控件小图标的图片，否则展示无效果
 */
@property (nonatomic, assign) YXBannerScrollViewPageContolStyle pageControlStyle;

/** 分页控件位置 */
@property (nonatomic, assign) YXBannerScrollViewPageContolAliment pageControlAliment;

///属性无法满足。自行设置分页的Positio
@property(nonatomic, assign)CGPoint pageOffset;

/** 分页控件小圆标大小 */
@property (nonatomic, assign) CGSize pageControlDotSize;

/** 当前分页控件小圆标颜色 */
@property (nonatomic, strong) UIColor *currentPageDotColor;

/** 其他分页控件小圆标颜色 */
@property (nonatomic, strong) UIColor *pageDotColor;

/** 当前分页控件小圆标图片 */
@property (nonatomic, strong) UIImage *currentPageDotImage;

/** 其他分页控件小圆标图片 */
@property (nonatomic, strong) UIImage *pageDotImage;

/**
  [必选]开发者需传入用来弹出广告的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;


/**  开始加载广告  */

/**
 开始加载广告

 @param view 加载广告的View
 */
- (void)loadMutBannerAdViewsInView:(UIView*)view;


/**
 刷新广告数据
 */
- (void)reloadMutBannerAd;

/**
 清空轮播广告缓存数据
 */
- (void)clearMutBannerAdImageChace;

@end

NS_ASSUME_NONNULL_END
