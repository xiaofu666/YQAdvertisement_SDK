//
//  YXLaunchScreenViewController.m
//  LunchAd
//
//  Created by shuai on 2018/10/8.
//  Copyright © 2018年 YX. All rights reserved.
//

#import "YXLaunchScreenViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>

@interface YXLaunchScreenViewController ()<YXLaunchAdManagerDelegate>

@end

@implementation YXLaunchScreenViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    // Do any additional setup after loading the view from its nib.
    self.title = @"LaunchAd";
    UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake(50, 300, [UIScreen mainScreen].bounds.size.width - 100, 40)];
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"LaunchADTest" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(launchScreenBtnClicked:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}
- (void)launchScreenBtnClicked:(UIButton*)sender{
    YXLaunchAdManager *adManager = [YXLaunchAdManager new];
    adManager.waitDataDuration = 3;
    adManager.duration = 5;
    adManager.mediaId = @"dev_ios_splash";
    adManager.delegate = self;
    adManager.showBackImage = YES;
    [adManager loadLaunchAdWithShowAdWindow:[UIApplication sharedApplication].delegate.window];
    NSLog(@"开始请求开屏广告");
}

#pragma mark Delegate Func
-(void)didLoadAd:(UIView *)view{
    NSLog(@"广告请求ok");
}
-(void)didFailedLoadAd:(NSError *)error{
    NSLog(@"广告请求失败%@",error);
}
-(void)LaunchShowFinish{
    NSLog(@"广告显示完成");
}
- (void)didClickedAdWithUrlStr:(NSString *)urlStr{
    NSLog(@"广告点击事件");
}
- (void)didAdShowReturn{
    NSLog(@"落地页或者appstoe返回事件，方便用户做返回后的处理工作");
}
- (void)lunchADSkipButtonClick{
    NSLog(@"跳过");
}
-(void)customSkipDuration:(NSInteger)duration{
    NSLog(@"广告倒计时:%ld",(long)duration);
}
- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
