//
//  JADNativeAdWidget.h
//  JADYun
//
//  Created by wangshuai331 on 2020/10/28.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JADNativeAdWidget : NSObject

/// close button widget
@property (strong, nonatomic, readonly, nullable) UIButton *closeWidget;
/// skip button widget
@property (strong, nonatomic, readonly, nullable) UIButton *skipWidget;

/// title label widget
@property (strong, nonatomic, readonly, nullable) UILabel *adTitleWidget;
/// description label widget
@property (strong, nonatomic, readonly, nullable) UILabel *adDescriptionWidget;

/// logo imageView widget
@property (strong, nonatomic, readonly, nullable) UIImageView *logoWidget;
/// logo text imageView widget
@property (strong, nonatomic, readonly, nullable) UIImageView *logoTextWidget;

/// logo ad imageView widget
@property (strong, nonatomic, readonly, nullable) UIImageView *logoAdWidget;

@end

NS_ASSUME_NONNULL_END
