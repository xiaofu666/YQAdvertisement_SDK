//
//  YXFeedAdViewController.m
//  LunchAd
//
//  Created by shuai on 2018/10/14.
//  Copyright © 2018年 YX. All rights reserved.
//

#import "YXFeedAdViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>
#import "ADTableViewCell.h"

static  NSString * feedMediaID = @"beta_ios_native";

@interface YXFeedAdViewController () <YXFeedAdManagerDelegate ,UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) YXFeedAdManager *feedManager;
@property (nonatomic,strong) UITableView *tableView;
@property (nonatomic,strong) NSMutableArray *dataSource;

@end

@implementation YXFeedAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"FeedAd";
    // Do any additional setup after loading the view.
    self.dataSource = [[NSMutableArray alloc]initWithCapacity:0];
    for (int i = 0; i < 20; i ++ ) {
        NSString * title = [NSString stringWithFormat:@"Number:%d  临时数据",i];
        [self.dataSource addObject:title];
    }
    
    [self.view addSubview:self.tableView];
    [self loadFeedAds];
}

- (void)initadViewWithData:(YXFeedAdData *)data adView:(ADTableViewCell *)adView{
    adView.adTitleLabel.text = data.adTitle;
    [self setImage:adView.adIconImageView WithURL:[NSURL URLWithString:data.IconUrl] placeholderImage:nil];
    adView.adContentLabel.text = data.adContent;
    if(!data.buttonText){
        [adView.infoBtn setTitle:@"点击下载" forState:UIControlStateNormal];
    }else{
        [adView.infoBtn setTitle:data.buttonText forState:UIControlStateNormal];
    }
}
- (void)setImage:(UIImageView*)imageView WithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder {
    NSURLSession *shareSessin = [NSURLSession sharedSession];
    NSMutableURLRequest *urlRequest = [NSMutableURLRequest requestWithURL:url];
    NSURLSessionDataTask *dataTask = [shareSessin dataTaskWithRequest:urlRequest completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        UIImage *image = [[UIImage alloc] initWithData:data];
        dispatch_async(dispatch_get_main_queue(), ^{
            [imageView setImage:image];
        });
    }];
    [dataTask resume];
}

- (UITableView *)tableView{
    if (!_tableView ) {
        _tableView = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [_tableView registerNib:[UINib nibWithNibName:@"ADTableViewCell" bundle:nil] forCellReuseIdentifier:@"ADTableViewCellID"];
    }
    return _tableView;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    id model = self.dataSource[indexPath.row];
    if ([model isKindOfClass:[YXFeedAdData class]]) {
        ADTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ADTableViewCellID" forIndexPath:indexPath];
        [self initadViewWithData:model adView:cell];
        [_feedManager registerAdViewForInteraction:cell.adImageView adData:model clickableViews:cell.subviews];
        return cell;
    }else{
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cellID"];
        if (!cell) {
            cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@"cellID"];
        }
        cell.textLabel.text = model;
        return cell;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    id model = self.dataSource[indexPath.row];
    if ([model isKindOfClass:[YXFeedAdData class]]) {
        return 270;
    }else{
        return 80;
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)loadFeedAds{
    _feedManager = [YXFeedAdManager new];
    _feedManager.adSize = YXADSize690X388;
    _feedManager.mediaId = feedMediaID;
    _feedManager.controller = self;
    _feedManager.delegate = self;
    _feedManager.adCount = 5;
    [_feedManager loadFeedAd];
}

#pragma mark ad delegate
- (void)didLoadFeedAd:(NSArray<YXFeedAdData *> *)data{
    NSMutableArray *dataSources = [self.dataSource mutableCopy];
    if (data.count > 0) {
        for (YXFeedAdData * model in data) {
            uint32_t index = arc4random_uniform((uint32_t)self.dataSource.count);
            [dataSources insertObject:model atIndex:index];
            self.dataSource = [dataSources copy];
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.tableView reloadData];
        });
    }
    NSLog(@"原生信息流广告获取成功");
}
-(void)didFailedLoadFeedAd:(NSError *)error{
    NSLog(@"原生信息流广告获取失败 error = %@",error);
}
-(void)didClickedFeedAd{
    NSLog(@"原生信息流广告点击");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
