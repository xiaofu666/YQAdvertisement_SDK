//
//  JADNativeAdSlot.h
//  JADYun
//
//  Created by wangshuai331 on 2020/11/2.
//

#import <Foundation/Foundation.h>

#import "JADNativeSize.h"
#import "JADYunConstant.h"

typedef NS_ENUM(NSUInteger, JADAdSlotAdType) {
    JADAdSlotAdTypeUnknown       = 0,
    JADAdSlotAdTypeSplash        = 1,    // splash ads
    JADAdSlotAdTypeFeed          = 2,    // feed ads
    JADAdSlotAdTypeFeedVideo     = 3,    // feed video ads
    JADAdSlotAdTypeInterstitial  = 4,    // interstitial ads
    JADAdSlotAdTypeBanner        = 5,    // banner ads
    JADAdSlotAdTypeRewardedVideo = 6,    // rewarded video ads
};

NS_ASSUME_NONNULL_BEGIN

@interface JADNativeAdSlot : NSObject

///  required. The unique identifier of a native ad.
@property (copy, nonatomic) NSString *adID;

/// required. Ad type.
@property (assign, nonatomic) JADAdSlotAdType adType;

/// required. Image size.
@property (strong, nonatomic) JADNativeSize *imgSize;

/// Whether to support deeplink. 注意：该参数已失效
@property (assign, nonatomic) BOOL isSupportDeepLink DEPRECATED_MSG_ATTRIBUTE("This property is deprecated, Settings are no longer required after version 1.2.2");

/// Splash allowable skipTime , default 5s
@property (assign, nonatomic) CGFloat fetchDelay DEPRECATED_MSG_ATTRIBUTE("use skipTime");
@property (assign, nonatomic) CGFloat skipTime;


/// 触发点击事件的手势类型
@property (nonatomic, assign) JADClickEventTriggerType triggerType;

@end

NS_ASSUME_NONNULL_END
