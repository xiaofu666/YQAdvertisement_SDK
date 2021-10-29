//
//  JADFeedViewDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/18.
//

#ifndef JADFeedViewDelegate_h
#define JADFeedViewDelegate_h

#import "JADNativeAdData.h"

@class JADFeedView;

NS_ASSUME_NONNULL_BEGIN

/// The methods declared by the JADFeedViewDelegate protocol allow the adopting delegate to respond to messages from the JADFeedView class and thus respond to operations such as whether the native ad has been loaded.
@protocol JADFeedViewDelegate<NSObject>

@optional

/**
 * This method is called when feedView ad slot loaded successfully.
 * @param feedView : view for feedView
 * 广告数据：加载成功
 */
- (void)jadFeedViewDidLoad:(JADFeedView *)feedView;

/**
 * This method is called when feedView ad slot failed to load.
 * @param error : the reason of error
 * 广告数据：加载失败
 */
- (void)jadFeedView:(JADFeedView *)feedView didFailWithError:(NSError * __nullable)error;

/**
 * This method is called when rendering a feedView succeed, and feedView.size.height has been updated
 * 广告视图：渲染完成
 */
- (void)jadFeedViewRenderSuccess:(JADFeedView *)feedView;

/**
 * This method is called when a feedView failed to render
 * 广告视图：渲染失败
 */
- (void)jadFeedViewRenderFail:(JADFeedView *)feedView error:(NSError * __nullable)error;;

/**
 * This method is called when feedView  will be showing.
 * 广告视图：曝光
 */
- (void)jadFeedViewWillVisible:(JADFeedView *)feedView;

/**
 * Sent when an ad view is clicked
 * 广告视图：点击
 */
- (void)jadFeedViewDidClick:(JADFeedView *)feedView;

/**
 * Sent when an ad view is closed
 * 广告视图：关闭
 */
- (void)jadFeedViewDidClose:(JADFeedView *)feed;

/**
 * This method is called when another controller has been closed.
 * @param interactionType ： open AppStore in app or open the webpage
 */
- (void)jadFeedViewDidCloseOtherController:(JADFeedView *)feedView
                           interactionType:(JADInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END

#endif /* JADFeedViewDelegate_h */
