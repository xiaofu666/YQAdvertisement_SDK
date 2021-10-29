//
//  SFSDKExpressManager.h
//  TestAdA
//
//  Created by lurich on 2019/12/12.
//  Copyright © 2019 YX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class YXFeedAdData;

NS_ASSUME_NONNULL_BEGIN

typedef void(^getADSucess) (YXFeedAdData *model);
typedef void(^getADFail) (NSError *error);

@interface SFSDKExpressManager : NSObject
/**
 宽高必传
 */
@property (nonatomic, assign) CGFloat s2sWidth;
@property (nonatomic, assign) CGFloat s2sHeight;

/**  媒体位Id  */
@property (nonatomic,copy) NSString *mediaId;

/**
 广告数量 默认为1
 */
@property (nonatomic,assign) NSInteger adCount;

@property (nonatomic, copy) getADSucess success;
@property (nonatomic, copy) getADFail   fail;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**  开始加载广告  */
- (void)loadNativeExpressFeedAdSuccess:(getADSucess)success fail:(getADFail)fail;

@end

NS_ASSUME_NONNULL_END
