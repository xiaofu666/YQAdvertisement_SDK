//
//  JADSplashDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#ifndef JADSplashDelegate_h
#define JADSplashDelegate_h

#import <Foundation/Foundation.h>

@class JADSplash;

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("No longer supported after 1.2.0; please adopt JADSplashViewDelegate")  @protocol JADSplashDelegate<NSObject>

@optional

/**
 * This method is called when splash ad material loaded successfully.
 */
- (void)jadSplashDidLoad:(JADSplash *)splash;

/**
 * This method is called when splash ad material failed to load.
 * @param error : the reason of error
 */
- (void)jadSplash:(JADSplash *)splash didFailWithError:(NSError * __nullable)error;

/**
 * This method is called when rendering a splash ad successed.
 */
- (void)jadSplashRenderSuccess:(JADSplash *)splash;

/**
 * This method is called when a splash ad failed to render.
 * @param error : the reason of error
 */
- (void)jadSplashRenderFail:(JADSplash *)splash error:(NSError * __nullable)error;

/**
 * This method is called when splash ad slot will be showing.
 */
- (void)jadSplashWillVisible:(JADSplash *)splash;

/**
 * This method is called when splash ad is clicked.
 */
- (void)jadSplashDidClick:(JADSplash *)splash;

/**
 * This method is called when splash ad is closed.
 */
- (void)jadSplashDidClose:(JADSplash *)splash;

@end

NS_ASSUME_NONNULL_END

#endif /* JADSplashDelegate_h */
