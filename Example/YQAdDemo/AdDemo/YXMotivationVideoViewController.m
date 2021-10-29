//
//  YXMotivationVideoViewController.m
//  LunchAd
//
//  Created by shuai on 2018/11/29.
//  Copyright © 2018 YX. All rights reserved.
//

#import "YXMotivationVideoViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>

@interface YXMotivationVideoViewController ()<YXMotivationDelegate>

@property (nonatomic, strong) YXMotivationVideoManager * motivationVideo;

@end

@implementation YXMotivationVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"激励视频demo";
    // Do any additional setup after loading the view.
    UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake(50, 300, [UIScreen mainScreen].bounds.size.width - 100, 40)];
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"打开激励视频" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(launchScreenBtnClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}

- (void)launchScreenBtnClicked{
    self.motivationVideo = [YXMotivationVideoManager new];
    self.motivationVideo.delegate = self;
    self.motivationVideo.showAdController = self;
    self.motivationVideo.mediaId = @"dev_ios_lotto_stimulatevideo_t";
    [self.motivationVideo loadVideoPlacement];
}

#pragma mark Delegate

/**
 adValid 激励视频广告-视频-加载成功
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoDidLoad:(BOOL)adValid{
    NSLog(@"激励视频广告-视频-加载成功");
}

/**
 adValid 激励视频广告点击
 
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoDidClick:(BOOL)adValid{
    NSLog(@"激励视频广告点击");
}

/**
 adValid 激励视频广告素材加载失败
  @param error 错误对象
 */
- (void)rewardedVideoDidFailWithError:(NSError *)error{
    NSLog(@"激励视频广告素材加载失败");
}

/**
 adValid 激励视频广告播放达到激励条件
 
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoAdDidRewardEffective:(BOOL)adValid{
    NSLog(@"激励视频广告播放达到激励条件");
}

/**
 adValid 激励视频广告播放完成
 
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoDidPlayFinish:(BOOL)adValid{
    NSLog(@"激励视频广告播放完成");
}

/**
 adValid 激励视频广告已经关闭
 */
- (void)rewardedVideoDidClose{
    NSLog(@"激励视频广告已经关闭");
}

/**
adValid 激励视频播放页即将打开
*/
- (void)rewardVideoAdWillVisible{
    NSLog(@"激励视频播放页即将打开");
}

/**
 adValid 激励视频广告点击了跳过按钮
 */
- (void)rewardedVideoSkipBtnClick{
    NSLog(@"激励视频广告点击了跳过按钮");
}

- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
