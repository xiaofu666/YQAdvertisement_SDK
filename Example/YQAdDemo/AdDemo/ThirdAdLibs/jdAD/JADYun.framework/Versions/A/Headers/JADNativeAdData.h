//
//  JADNativeAdData.h
//  JADYun
//
//  Created by wangshuai331 on 2020/11/2.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, JADInteractionType) {
    JADInteractionTypeCustom = 0,
    JADInteractionTypeURL = 1,      // open the webpage using a browser
    JADInteractionTypePage = 2,     // open the webpage within the app
};

NS_ASSUME_NONNULL_BEGIN

@interface JADNativeAdData : NSObject

// ad image address URL
@property (strong, nonatomic) NSArray <NSString *> *adImages;

// ad source
@property (copy, nonatomic) NSString *adResource;

// ad video url
@property (copy, nonatomic) NSString *adVideo;

// ad title
@property (copy, nonatomic) NSString *adTitle;

// ad description
@property (copy, nonatomic) NSString *adDescription;

// ad price 广告价格（单位：分）
@property (assign, nonatomic) NSInteger adPrice;

@end

NS_ASSUME_NONNULL_END
