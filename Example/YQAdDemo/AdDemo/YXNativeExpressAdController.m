//
//  YXNativeExpressAdController.m
//  TestAdA
//
//  Created by lurich on 2019/8/26.
//  Copyright © 2019 YX. All rights reserved.
//

#import "YXNativeExpressAdController.h"
#import <YXLaunchAds/YXLaunchAds.h>

@interface YXNativeExpressAdController ()<UITableViewDelegate,UITableViewDataSource,YXImageTextAdManagerDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *dataArray;
@property (nonatomic, strong) SFNativeExpressAdManager *manager;

@end

@implementation YXNativeExpressAdController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dataArray = [NSMutableArray array];
    for (int i=0; i<10; i++) {
        [self.dataArray addObject:@"测试数据"];
    }
    [self.view addSubview:self.tableView];
    // Do any additional setup after loading the view.
    [self loadNativeExpressAds];
}
- (void)loadNativeExpressAds{
    SFNativeExpressAdManager *manager = [SFNativeExpressAdManager new];
    manager.mediaId = @"dev_ios_lotto_award_feed_t";
    manager.adCount = 3;
    manager.controller = self;
    manager.delegate = self;
    [manager loadNativeExpressFeedAd];
    self.manager = manager;
}

- (UITableView *)tableView{
    if(!_tableView){
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height) style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"UITableViewCellID"];
    }
    return _tableView;
}
#pragma mark - tableViewDelegate
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArray.count;
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    id model = self.dataArray[indexPath.row];
    if ([model isKindOfClass:[YXFeedAdData class]]) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cellID"];
        if (!cell) {
            cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@"cellID"];
        }
        [cell.contentView.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
        UIView *view = ((YXFeedAdData *)model).data;
        [cell.contentView addSubview:view];
        return cell;
    }else{
        UITableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:@"UITableViewCellID"];
        cell.textLabel.text = model;
        return cell;
    }
}
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    id model = self.dataArray[indexPath.row];
    if ([model isKindOfClass:[YXFeedAdData class]]) {
        YXFeedAdData *modelData = model;
        UIView *view = modelData.data;
        return view.bounds.size.height;
    }else{
        return 80;
    }
}
- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    return [UIView new];
}
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return CGFLOAT_MIN;
}
- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section{
    return [UIView new];
}
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    return CGFLOAT_MIN;
}

#pragma mark Delegate
/**
 加载成功的回调
 @param data  回调的广告素材
 */
- (void)didLoadFeedAd:(NSArray<YXFeedAdData*>*_Nullable)data{
    NSMutableArray *dataSources = [self.dataArray mutableCopy];
    if (data.count > 0) {
        for (YXFeedAdData * model in data) {
            uint32_t index = arc4random_uniform((uint32_t)self.dataArray.count);
            [dataSources insertObject:model atIndex:index];
        }
        self.dataArray = [dataSources copy];
    }
}
/**
 取广告失败调用
 @param error 为错误信息
 */
- (void)didFailedLoadFeedAd:(NSError* _Nonnull)error{
    NSLog(@"取广告失败调用 error = %@",error);
}
/**
 广告点击后回调
 */
- (void)didClickedFeedAd{
    NSLog(@"广告点击后回调");
}
/**
 广告被关闭
 */
- (void)nativeExpressAdClose{
    NSLog(@"广告被关闭");
}

/**
 广告渲染成功
 */
- (void)didFeedAdRenderSuccess:(NSArray<YXFeedAdData *> *)data{
    NSLog(@"广告渲染成功,此时view的高度已自适应");
    [self.tableView reloadData];
}

- (void)dealloc{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

@end
