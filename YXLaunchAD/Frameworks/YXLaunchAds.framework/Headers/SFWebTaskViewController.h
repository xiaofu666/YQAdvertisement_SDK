//
//  SFWebViewController.h
//  fitness
//
//  Created by 小富 on 2017/7/19.
//  Copyright © 2017年 YunXiang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

NS_ASSUME_NONNULL_BEGIN

//关闭通知
extern NSString * const CLOST_POST_NAME;
//H5分享
extern NSString * const H5_WX_SHARE;

@interface SFWebTaskViewController : UIViewController

@property (nonatomic, copy) NSString *urlStr;
@property (nonatomic, copy) NSString *posId;

@end

NS_ASSUME_NONNULL_END

