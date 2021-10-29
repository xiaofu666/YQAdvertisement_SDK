//
//  YXHalfLaunchScreenViewController.m
//  LunchAd
//
//  Created by shuai on 2018/10/23.
//  Copyright © 2018年 YX. All rights reserved.
//

#import "YXHalfLaunchScreenViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>

@interface YXHalfLaunchScreenViewController ()<YXLaunchAdManagerDelegate>

@end

@implementation YXHalfLaunchScreenViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    // Do any additional setup after loading the view from its nib.
    self.title = @"LaunchAd";
    UIButton *launchScreenBtn = [[UIButton alloc]initWithFrame:CGRectMake(50, 300, [UIScreen mainScreen].bounds.size.width - 100, 40)];
    launchScreenBtn.backgroundColor = [UIColor blueColor];
    [launchScreenBtn setTitle:@"LaunchADTest" forState:UIControlStateNormal];
    [launchScreenBtn addTarget:self action:@selector(launchScreenBtnClicked:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:launchScreenBtn];
}
- (void)launchScreenBtnClicked:(UIButton*)sender{
    YXLaunchAdManager *adManager = [YXLaunchAdManager new];
    adManager.waitDataDuration = 5;
    adManager.duration = 5;
    adManager.mediaId = @"dev_ios_splash";
    adManager.delegate = self;
    adManager.showBackImage = YES;
    UILabel *bottom = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height * 0.2)];
    bottom.text = @"AD Demo";
    bottom.textAlignment = NSTextAlignmentCenter;
    bottom.font = [UIFont systemFontOfSize:35];
    //bottom 为含logo的view
    adManager.bottomView = bottom;
    [adManager loadLaunchAdWithShowAdWindow:[[UIApplication sharedApplication] keyWindow]];
    NSLog(@"开始请求半开屏广告");
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
