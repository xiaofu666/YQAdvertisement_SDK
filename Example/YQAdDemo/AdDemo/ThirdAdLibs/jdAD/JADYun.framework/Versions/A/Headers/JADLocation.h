//
//  JADLocation.h
//  JADYun
//
//  Created by zhangdi208 on 2021/2/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JADLocation : NSObject

/// 经度
@property (nonatomic, strong) NSNumber *longitude;

/// 纬度
@property (nonatomic, strong) NSNumber *latitude;

@end

NS_ASSUME_NONNULL_END
