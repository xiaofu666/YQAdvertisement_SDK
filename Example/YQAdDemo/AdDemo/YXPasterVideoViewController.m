//
//  YXPasterVideoViewController.m
//  AdDemo
//
//  Created by lurich on 2021/6/15.
//

#import "YXPasterVideoViewController.h"
#import <YXLaunchAds/YXLaunchAds.h>

static  NSString * feedMediaID = @"dev_ios_native_video";

@interface YXPasterVideoViewController ()<SFNativeVideoAdManagerDelegate>

@property (nonatomic, strong) SFNativeVideoADManager *videoManager;
@property (nonatomic,strong) UIView *videoView;
@property (nonatomic, strong) UILabel *timeView;

@end

@implementation YXPasterVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    if (@available(iOS 11.0, *)) {
        self.navigationItem.largeTitleDisplayMode = UINavigationItemLargeTitleDisplayModeNever;
    } else {
        // Fallback on earlier versions
        self.automaticallyAdjustsScrollViewInsets = NO;
    }
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"VideoAd";
    UIButton *iconBtn = ({
        UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake(50, 200, [UIScreen mainScreen].bounds.size.width - 100 , 40)];
        button.backgroundColor = [UIColor blueColor];
        [button setTitle:@"VideoADTest" forState:UIControlStateNormal];
        [button addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
        button;
    });
    [self.view addSubview:iconBtn];
    
    CGFloat width = self.view.frame.size.width-60;
    //根据宽高比自定义适配
    CGFloat height = 9 * width / 16;
    self.videoView = [[UIView alloc]initWithFrame:CGRectMake(30, 300, width, height)];
    self.videoView.backgroundColor = [UIColor lightGrayColor];
    [self.view addSubview:self.videoView];
}
- (void)loadAd{
    [self.videoView.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
    SFNativeVideoADManager *videoManager = [SFNativeVideoADManager new];
    videoManager.mediaId = feedMediaID;
    videoManager.controller = self;
    videoManager.delegate = self;
    videoManager.runPlay = YES;
    [videoManager loadNativeVideoAdWithBackView:self.videoView];
    self.videoManager = videoManager;
}
- (UILabel *)timeView{
    if (!_timeView) {
        _timeView = [[UILabel alloc] initWithFrame:CGRectMake(self.videoView.bounds.size.width-80, 10, 70, 30)];
        _timeView.textAlignment = NSTextAlignmentCenter;
        _timeView.textColor = UIColor.whiteColor;
        _timeView.font = [UIFont systemFontOfSize:14 weight:UIFontWeightBold];
        _timeView.backgroundColor = UIColor.grayColor;
        _timeView.layer.masksToBounds = YES;
        _timeView.layer.cornerRadius = 15;
        _timeView.text = @"";
    }
    return _timeView;
}
#pragma mark ADdelegate
/**
 加载成功的回调
 */
- (void)didLoadNativeVideoAdWithDuation:(double)time{
    NSLog(@"加载成功的回调");
    NSLog(@"总时长:%@",@(time));
    [self.videoManager showNativeVideoAd];
    [self.videoView addSubview:self.timeView];
}

/**
 取广告失败调用
 
 @param error 为错误信息
 */
- (void)didFailedLoadNativeVideoAd:(NSError* _Nonnull)error{
    NSLog(@"取广告失败调用");
}

/**
 广告点击后回调
 */
- (void)didClickedNativeVideoAd{
    NSLog(@"广告点击后回调");
}
/**
 落地页或者appstoe返回事件，方便用户做返回后的处理工作
 */
-(void)didNativeVideoAdShowReturn{
    NSLog(@"落地页或者appstoe返回事件，方便用户做返回后的处理工作");
}
/**
 广告播放完成
 */
- (void)didPlayFinishNativeVideoAd{
    NSLog(@"广告播放完成");
}

/**
 *  倒计时回调
 *  @param duration 倒计时时间
 */
-(void)didNativeVideoAdDuration:(NSInteger)duration{
    self.timeView.text = [NSString stringWithFormat:@"%@ 秒",@(duration)];
    if (duration<=0) {
        [self.timeView removeFromSuperview];
    }
}

- (void)dealloc
{
    NSLog(@"%@ %@",[self class],NSStringFromSelector(_cmd));
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

