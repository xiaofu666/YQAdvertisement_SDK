//
//  KSAdPlayableDemoViewController.h
//  KSAdSDK
//
//  Created by zhangchuntao on 2020/11/20.
//

#import <UIKit/UIKit.h>
#if __has_include(<KSUDefine/KSAdShowDirection.h>)
#import <KSUDefine/KSAdShowDirection.h>
#else
#import "KSAdShowDirection.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface KSAdPlayableDemoViewController : UIViewController

@property (nonatomic, copy) NSString *playableURL;

@property (nonatomic, copy) NSString *downloadURL;

@property (nonatomic, assign) KSAdShowDirection showDirection;

@end

NS_ASSUME_NONNULL_END
