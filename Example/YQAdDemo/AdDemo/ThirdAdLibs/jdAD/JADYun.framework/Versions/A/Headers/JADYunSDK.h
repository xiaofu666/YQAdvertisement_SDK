//
//  JADYun.h
//  JADYun
//
//  Created by wangshuai331 on 2020/7/31.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef void (^initCompletionHandler)(NSError *_Nullable error);

extern NSString *kJADYunInitSuccessNotification;

@class JADLocation, JADPollux;

@interface JADYunSDK : NSObject

/**
 * 初始化 JADYun  SDK 方法
 * @param appID 京东广告应用标识
*/
+ (void)initWithAppID:(NSString *_Nullable)appID;

/**
 * 检查 JADYun SDK 是否已经初始化成功
 */
+ (BOOL)isInitialized;

/**
 * SDK Version 版本号
 */
+ (NSString *)sdkVersion;

/**
 * 是否开启log 日志
 * @param enableLog Debug模式 默认为 NO
 */
+ (void)enableLog:(BOOL)enableLog;

/**
 * 是否允许JADYun SDK 使用地理位置权限
 * @param isCanUseLocation 默认为YES
 */
+ (void)canUseLocation:(BOOL)isCanUseLocation;

/**
 * 当isCanUseLocation = NO时，可传入地理位置信息，京东 SDK 使用您传入的地理位置信息
 * @param location 传入的地理位置
 */
+ (void)setUserLocation:(JADLocation *)location;

/**
 * @param polluxs 传入Pollux数组，可选配置，原CAID
 */
+ (void)setPolluxArray:(NSArray<JADPollux *> *)polluxs;

/**
 * @param idfa 传入idfa值，可选配置
 */
+ (void)setCustomIDFA:(NSString *)idfa;

/**
 * 是否允许使用IDFA， 不设置则默认为YES；设置为NO时，IDFA权限不可用，可通过setCustomIDFA传入有效的IDFA值
 * @param isCanUseIDFA 是否允许
 */
+ (void)canUseIDFA:(BOOL)isCanUseIDFA;

/**
 * 是否允许使用IP地址，不设置则默认为YES
 * @param isCanUseIP 是否允许
*/
+ (void)canUseIPAddress:(BOOL)isCanUseIP;

@end

NS_ASSUME_NONNULL_END
