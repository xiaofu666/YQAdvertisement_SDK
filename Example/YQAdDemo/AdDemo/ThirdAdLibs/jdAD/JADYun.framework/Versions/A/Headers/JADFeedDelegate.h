//
//  JADFeedDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#ifndef JADFeedDelegate_h
#define JADFeedDelegate_h

@class JADFeed;

NS_ASSUME_NONNULL_BEGIN

/// The methods declared by the JADFeedDelegate protocol allow the adopting delegate to respond to messages from the JADFeed class and thus respond to operations such as whether the native ad has been loaded.
DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.0; please adopt JADFeedViewDelegate") @protocol JADFeedDelegate<NSObject>

@optional

/**
 * This method is called when FeedAdView ad slot loaded successfully.
 * @param feedView : view for bannerAdView
 */
- (void)jadFeed:(JADFeed *)feed didLoadView:(UIView *)feedView;

/**
 * This method is called when feedAdView ad slot failed to load.
 * @param error : the reason of error
 */
- (void)jadFeed:(JADFeed *)feed didFailWithError:(NSError *)error;

/**
 * This method is called when rendering a feedAdView successed, and feedAdView.size.height has been updated
 */
- (void)jadFeedRenderSucess:(JADFeed *)feed;

/**
 * This method is called when a feedAdView failed to render
 */
- (void)jadFeedRenderFail:(JADFeed *)feed error:(NSError *)error;;

/**
 * This method is called when feedAdView  will be showing.
 */
- (void)jadFeedWillVisible:(JADFeed *)feed;

/**
 * Sent when an ad view is clicked
 */
- (void)jadFeedDidClick:(JADFeed *)feed;

/**
 * Sent when an ad view is closed
 */
- (void)jadFeedDidClose:(JADFeed *)feed;

@end

NS_ASSUME_NONNULL_END


#endif /* JADFeedDelegate_h */
