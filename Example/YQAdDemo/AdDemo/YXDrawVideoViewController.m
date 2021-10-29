//
//  YXDrawVideoViewController.m
//  TestAdA
//
//  Created by lurich on 2020/5/9.
//  Copyright © 2020 YX. All rights reserved.
//

#import "YXDrawVideoViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>
#import "ADTableViewCell.h"

static  NSString * feedMediaID = @"dev_ios_smallvideo_fullvideo_t";

@interface YXDrawVideoViewController () <SFDrawVideoAdDelegate ,UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) SFDrawVideoAdManager *feedManager;
@property (nonatomic,strong) UITableView *tableView;
@property (nonatomic,strong) NSMutableArray *dataSource;

@end

@implementation YXDrawVideoViewController

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.hidden = YES;
}
- (void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    self.navigationController.navigationBar.hidden = NO;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"DrawVideoFeedAd";
    // Do any additional setup after loading the view.
    self.dataSource = [[NSMutableArray alloc]initWithCapacity:0];
    for (int i = 0; i < 10; i ++ ) {
        NSString * title = [NSString stringWithFormat:@"Number:%d  临时数据",i];
        [self.dataSource addObject:title];
    }
    [self.view addSubview:self.tableView];
    [self loadFeedAds];
}

- (UITableView *)tableView{
    if (!_tableView ) {
        _tableView = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.pagingEnabled = YES;
        [_tableView registerNib:[UINib nibWithNibName:@"ADTableViewCell" bundle:nil] forCellReuseIdentifier:@"ADTableViewCellID"];
    }
    return _tableView;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return  self.dataSource.count;
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    id model = self.dataSource[indexPath.row];
    if ([model isKindOfClass:[YXFeedAdData class]]) {
        ADTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ADTableViewCellID" forIndexPath:indexPath];
        UIView *view = [cell.contentView viewWithTag:1000];
        [view removeFromSuperview];
        YXFeedAdData *adModel = (YXFeedAdData *)model;
        if (adModel.adType == 2) {//自渲染
            cell.adTitleLabel.text = adModel.adTitle;
            cell.adContentLabel.text = adModel.adContent;
            if(!adModel.buttonText){
                [cell.infoBtn setTitle:@"点击下载" forState:UIControlStateNormal];
            }else{
                [cell.infoBtn setTitle:adModel.buttonText forState:UIControlStateNormal];
            }
            [_feedManager registerAdViewForInteraction:cell.contentView adData:model clickableViews:cell.subviews];
        } else {//SDK渲染
            UIView *view = adModel.data;
            view.tag = 1000;
            [cell.contentView addSubview:view];
        }
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
    return tableView.bounds.size.height;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)loadFeedAds{
    SFDrawVideoAdManager *feedManager = [SFDrawVideoAdManager new];
    feedManager.mediaId = feedMediaID;
    feedManager.controller = self;
    feedManager.delegate = self;
    feedManager.adCount = 5;
    feedManager.s2sHeight = self.view.frame.size.height;
    [feedManager loadFeedAd];
    self.feedManager = feedManager;
}

#pragma mark ad delegate
- (void)didLoadDrawVideoFeedAd:(NSArray<YXFeedAdData *> *)data{
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
}

-(void)didFailedLoadFeedAd:(NSError *)error{
    NSLog(@"Draw视频流广告加载失败 error = %@",error);
}

-(void)didClickedFeedAd{
    NSLog(@"Draw视频流广告-点击了广告");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
