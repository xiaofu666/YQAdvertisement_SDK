//
//  AppDelegate.m
//  AdDemo
//
//  Created by lurich on 2021/6/11.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>

@interface AppDelegate ()<YXLaunchAdManagerDelegate>

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions{
    // Override point for customization after application launch.
    [YXAdSDKManager defaultManager].cityCode = @"C0F87AB3948E8C6D";
    [YXAdSDKManager defaultManager].channelID = @"t-i";//对接时使用运营提供的渠道号
    [YXAdSDKManager defaultManager].vuid = @"t_111111111";//渠道号前缀+_+用户ID
    [YXAdSDKManager defaultManager].nick_name = @"测试专员";
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    UINavigationController *rootVC = [[UINavigationController alloc]initWithRootViewController:[ViewController new]];
    self.window.rootViewController = rootVC;
    [self.window makeKeyAndVisible];
    
    /** 开屏广告初始化 */
    [self initLaunchAd];
    return YES;
}

/** 开屏广告初始化 建议放在 didFinishLaunchingWithOptions中调用 */
- (void)initLaunchAd{
    YXLaunchAdManager *adManager = [YXLaunchAdManager new];
    adManager.waitDataDuration = 3;
    adManager.duration = 5;
    adManager.mediaId = @"cwdk_ios_splash";
    adManager.delegate = self;
    adManager.showBackImage = YES;
    [adManager loadLaunchAdWithShowAdWindow:self.window];
}
#pragma mark ADDelegate
-(void)didLoadAd:(UIView *)view{
    NSLog(@"广告请求ok");
}
- (void)didClickedAdWithUrlStr:(NSString *)urlStr{
    NSLog(@"广告点击事件");
}
-(void)LaunchShowFinish{
    NSLog(@"广告显示完成");
}
-(void)didFailedLoadAd:(NSError *)error{
    NSLog(@"广告请求失败%@",error);
}
- (void)didAdShowReturn{
    NSLog(@"落地页或者appstoe返回事件，方便用户做返回后的处理工作");
}
-(void)customSkipDuration:(NSInteger)duration{
    NSLog(@"广告倒计时:%ld",(long)duration);
}
- (void)lunchADSkipButtonClick{
    NSLog(@"跳过");
}

@end
