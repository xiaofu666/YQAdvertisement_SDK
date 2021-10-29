//
//  SFWKWebView.h
//  AdDemo
//
//  Created by lurich on 2021/8/5.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^TitleBlock)(NSString *title);
@interface SFWKWebView : UIView

@property (nonatomic, copy) TitleBlock titleBlock;
@property (nonatomic, strong) UIViewController *currentVC;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *posId;
@property (nonatomic, strong) WKWebView *webView;

@end

NS_ASSUME_NONNULL_END
