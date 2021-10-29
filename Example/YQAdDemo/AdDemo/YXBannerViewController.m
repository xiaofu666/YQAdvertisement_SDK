//
//  YXBannerViewController.m
//  LunchAd
//
//  Created by shuai on 2018/10/8.
//  Copyright © 2018年 YX. All rights reserved.
//

#import "YXBannerViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>

static  NSString * bannerMediaID = @"dev_ios_banner";

@interface YXBannerViewController ()<YXBannerAdManagerDelegate>

@property (nonatomic, strong) YXBannerAdManager *bannerView;

@end

@implementation YXBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"BannerAd";
    // Do any additional setup after loading the view from its nib.
    UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake(50, 200, [UIScreen mainScreen].bounds.size.width - 100 , 40)];
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"BannerADTest" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(bannerBtnClicked:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}
- (void)bannerBtnClicked:(UIButton*)button{
    if (self.bannerView) {
        [_bannerView removeFromSuperview];
        _bannerView = nil;
    }
    YXBannerAdManager *bannerView =  [[YXBannerAdManager alloc]initWithFrame:CGRectMake(0,self.view.bounds.size.height-60, self.view.bounds.size.width, 60)];
    bannerView.interval = 30;
    bannerView.isLoop = YES;
    bannerView.delegate = self;
    bannerView.controller = self;
    bannerView.mediaId = bannerMediaID;
    [bannerView loadBannerAD];
    self.bannerView = bannerView;
    NSLog(@"Banner请求");
}

#pragma mark Delegate
- (void)didLoadBannerAd{
    NSLog(@"Banner广告请求成功");
    [self.view addSubview:self.bannerView];
}

- (void)didClickedBannerAd{
    NSLog(@"Banner广告点击");
}

- (void)didFailedLoadIconAd:(NSError *)error{
    NSLog(@"Banner广告请求失败");
}

- (void)didCloseBannerAd{
    NSLog(@"Banner广告关闭后回调");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
