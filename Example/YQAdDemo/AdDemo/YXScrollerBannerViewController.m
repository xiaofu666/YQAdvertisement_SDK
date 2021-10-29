//
//  YXScrollerBannerViewController.m
//  LunchAd
//
//  Created by shuai on 2018/11/21.
//  Copyright © 2018 YX. All rights reserved.
//

#import "YXScrollerBannerViewController.h" 
#import <YXLaunchAds/YXLaunchAds.h>

static  NSString * feedMediaID = @"beta_ios_native";

@interface YXScrollerBannerViewController ()<YXMutBannerAdManagerDelegate>

@property (nonatomic, strong) UIView *BannerView;
@property (nonatomic, strong) YXMutBannerAdManager * mutBanner;

@end

@implementation YXScrollerBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat width = self.view.frame.size.width-60;
    //根据宽高比自定义适配
    CGFloat height = 388 * width / 690;
    self.BannerView = [[UIView alloc]initWithFrame:CGRectMake(30,100 , width, height)];
    [self.view addSubview:self.BannerView];
    
    //请求广告
    [self loadAd];
    
    UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake(50, 150+height, [UIScreen mainScreen].bounds.size.width - 100, 40)];
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"刷新广告" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(reloadADView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}

- (void)loadAd{
    YXMutBannerAdManager *mutBanner = [YXMutBannerAdManager new];
    mutBanner.delegate = self;
    mutBanner.adSize = YXADSizeCustom;
    mutBanner.s2sWidth = self.BannerView.bounds.size.width;
    mutBanner.s2sHeight = self.BannerView.bounds.size.height;
    mutBanner.controller = self;
    mutBanner.isOnlyImage = YES;
    mutBanner.mediaId = feedMediaID;
    mutBanner.pageControlAliment = YXBannerScrollViewPageContolAlimentCenter;
    mutBanner.pageControlStyle = YXBannerScrollViewPageControlHorizontal;
    mutBanner.pageDotColor = UIColor.greenColor;
    mutBanner.currentPageDotColor = UIColor.redColor;
    mutBanner.cornerRadius = 8;
    [mutBanner loadMutBannerAdViewsInView:self.BannerView];
    self.mutBanner = mutBanner;
    NSLog(@"请求多图广告");
}

- (void)reloadADView{
    [self.mutBanner reloadMutBannerAd];
}

#pragma mark Delegate
- (void)didLoadMutBannerAdView{
    NSLog(@"加载成功");
}
-(void)didFailedLoadMutBannerAd:(NSError *)error{
    NSLog(@"加载失败%@",error);
}
- (void)didClickedMutBannerAdWithIndex:(NSInteger)index UrlStr:(NSString *)urlStr{
    NSLog(@"点击");
}

- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
