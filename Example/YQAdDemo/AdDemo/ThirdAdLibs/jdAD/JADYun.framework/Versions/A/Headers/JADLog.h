//
//  JADLogModule.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/6.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

//Verbose
#define JADLogV(format, ...) [JADLog logV:format,##__VA_ARGS__];

//Debug
#define JADLogD(format, ...) [JADLog logD:format,##__VA_ARGS__];

//Info
#define JADLogI(format, ...) [JADLog logI:format,##__VA_ARGS__];

//Warning
#define JADLogW(format, ...) [JADLog logW:format,##__VA_ARGS__];

//Error
#define JADLogE(format, ...) [JADLog logE:format,##__VA_ARGS__];


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, JADLogLevel) {
    JADLogLevelV = 0,   //Verbose
    JADLogLevelD = 1,   //Debug
    JADLogLevelI = 2,   //Info
    JADLogLevelW = 3,   //Warning
    JADLogLevelE = 4,   //Error
    JADLogLevelN = 5,   //Close
};

@interface JADLog : NSObject

+ (void)openLog:(BOOL)open;
+ (void)setDebugMode;
+ (void)setVerboseMode;
+ (void)logV:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logD:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logI:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logW:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logE:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);

@end

NS_ASSUME_NONNULL_END
