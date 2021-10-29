//
//  ViewController.m
//  LunchAd
//
//  Created by shuai on 2018/5/21.
//  Copyright © 2018年 YX. All rights reserved.
//

#import "ViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>
#import "YXScrollerBannerViewController.h"
#import "YXFeedAdViewController.h"
#import "YXNativeExpressAdController.h"
#import "YXBannerViewController.h"
#import "YXLaunchScreenViewController.h"
#import "YXHalfLaunchScreenViewController.h"
#import "YXIconViewController.h"
#import "YXInterstitialViewController.h"
#import "YXMotivationVideoViewController.h"
#import "YXDrawVideoViewController.h"
#import "YXPasterVideoViewController.h"

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) UITableView *tableView;
@property (nonatomic,strong) NSArray *dataArr;

@end

@implementation ViewController

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.hidden = NO;
}
- (void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
}
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"ADDemo";
    self.dataArr = @[@"全屏开屏启动页样式",@"半屏开屏启动页样式",@"轮播广告",@"原生信息流广告",@"原生模板广告",@"横幅广告",@"icon样式",@"插屏样式",@"激励视频",@"draw视频",@"视频贴片",@"H5 任务"];
    
    [self.view addSubview:self.tableView];
    
}
static NSString * cellID = @"CELL";
- (UITableView *)tableView{
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height) style:UITableViewStylePlain];
        _tableView.rowHeight = 60;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:cellID];
    }
    return _tableView;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArr.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell=[tableView dequeueReusableCellWithIdentifier:cellID forIndexPath:indexPath];
    cell.textLabel.text = self.dataArr[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    NSString *titleStr = self.dataArr[indexPath.row];
    if ([titleStr isEqualToString:@"全屏开屏启动页样式"]) {
       [self.navigationController pushViewController:[YXLaunchScreenViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"半屏开屏启动页样式"]) {
       [self.navigationController pushViewController:[YXHalfLaunchScreenViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"轮播广告"]) {
        [self.navigationController pushViewController:[YXScrollerBannerViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"原生信息流广告"]) {
        [self.navigationController pushViewController:[YXFeedAdViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"原生模板广告"]) {
        [self.navigationController pushViewController:[YXNativeExpressAdController new] animated:YES];
    } else if ([titleStr isEqualToString:@"横幅广告"]) {
        [self.navigationController pushViewController:[YXBannerViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"icon样式"]) {
        [self.navigationController pushViewController:[YXIconViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"插屏样式"]) {
        [self.navigationController pushViewController:[YXInterstitialViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"激励视频"]) {
        [self.navigationController pushViewController:[YXMotivationVideoViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"draw视频"]) {
        [self.navigationController pushViewController:[YXDrawVideoViewController new] animated:YES];
    } else if ([titleStr isEqualToString:@"视频贴片"]) {
        [self.navigationController pushViewController:[YXPasterVideoViewController new] animated:YES];
    }
    else if ([titleStr isEqualToString:@"H5 任务"]) {
        [YXAdSDKManager defaultManager].channelID = @"t-h5";
        [YXAdSDKManager defaultManager].vuid = @"t_111111111";//渠道号前缀+_+用户ID
        [YXAdSDKManager defaultManager].nick_name = @"测试大佬";
        [self getH5TaskWebViewWithPostID:@"banner-v1"];
    }
}
- (void)getH5TaskWebViewWithPostID:(NSString *)postID {
    [YXAdSDKManager getMaterialWithPostID:postID Success:^(id  _Nonnull json) {
        if (json) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"接口请求成功 data=%@",json);
                NSDictionary *dataDict = (NSDictionary *)json;
                NSDictionary *dict = dataDict[@"data"];
                if (dict[@"material_path"]) {
                    //活动入口 标题与logo
                    //展示到页面时 上报report_url ，具体参考文档
                }
                SFWebTaskViewController *taskVC = [SFWebTaskViewController new];
                taskVC.urlStr = dict[@"page_url"];
                taskVC.posId = postID;
                [self.navigationController pushViewController:taskVC animated:YES];
            });
        }
    } fail:^(NSError * _Nonnull error) {
        NSLog(@"接口请求失败 error=%@",error);
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    NSLog(@"didReceiveMemoryWarning");
}


@end
