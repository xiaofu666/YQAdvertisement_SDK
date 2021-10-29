//
//  YXInterstitialViewController.m
//  LunchAd
//
//  Created by shuai on 2018/10/25.
//  Copyright © 2018年 YX. All rights reserved.
//

#import "YXInterstitialViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>

static  NSString * interstitialAdID = @"dev_ios_interstitial";

@interface YXInterstitialViewController ()<YXInterstitialAdManagerDelegate>

@property (nonatomic, strong) YXInterstitialAdManager *interstitialAd;

@end

@implementation YXInterstitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"InterstitialAd";//插屏
    // Do any additional setup after loading the view from its nib.
    UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake(50, 200, [UIScreen mainScreen].bounds.size.width - 100 , 40)];
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"InterstitialAdTest" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(InterstitialAdBtnClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}
- (void)InterstitialAdBtnClicked{
    self.interstitialAd = [YXInterstitialAdManager new];
    self.interstitialAd.mediaId = interstitialAdID;
    self.interstitialAd.delegate = self;
    self.interstitialAd.controller = self;
    [self.interstitialAd loadInterstitialAd];
    NSLog(@"插屏请求");
}

#pragma mark Delegate
- (void)didLoadInterstitialAd{
    NSLog(@"插屏广告请求成功");
}

- (void)didClickedInterstitialAd{
    NSLog(@"插屏广告点击");
}

- (void)didFailedLoadInterstitialAd:(NSError *)error{
    NSLog(@"插屏广告请求失败");
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
