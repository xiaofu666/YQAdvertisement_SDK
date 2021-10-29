//
//  KSAdSplashViewController.h
//  KSAdSDK
//
//  Created by zhangchuntao on 2020/6/1.
//

#import <UIKit/UIKit.h>

#if __has_include(<KSUDefine/KSAdShowDirection.h>)
    #import <KSUDefine/KSAdShowDirection.h>
#else
    #import "KSAdShowDirection.h"
#endif

NS_ASSUME_NONNULL_BEGIN
DEPRECATED_MSG_ATTRIBUTE("use KSSplashAdView instead.")
@interface KSAdSplashViewController : UIViewController

// 显示方向，需要在viewDidLoad前设置
@property (nonatomic, assign) KSAdShowDirection showDirection;

@end

NS_ASSUME_NONNULL_END
