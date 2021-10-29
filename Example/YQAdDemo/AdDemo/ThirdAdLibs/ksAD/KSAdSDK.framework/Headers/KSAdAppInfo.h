//
//  KSAdAppInfo.h
//  KSAdSDK
//
//  Created by 徐志军 on 2019/8/29.
//

#import <Foundation/Foundation.h>

@class KSAdAppInfoContent;

NS_ASSUME_NONNULL_BEGIN

@interface KSAdAppInfo : NSObject

@property (nonatomic, copy) NSString *appId;            // app标识 必填 后续修改为string
@property (nonatomic, copy) NSString *name;             // app名称 选填(sdk内部会自动取CFBundleDisplayName)
@property (nonatomic, copy) NSString *packageName;      // app安装包名 选填(sdk内部会自动取bundleIdentifier)
@property (nonatomic, copy) NSString *version;          // app版本号 选填(sdk内部会自动取"CFBundleShortVersionString.CFBundleVersion")

// 新增广告请求字段
@property (nonatomic, strong) KSAdAppInfoContent *content; // 内容相关

@end

@interface KSAdAppInfoContent : NSObject

// 新增广告请求字段
@property (nonatomic, copy) NSString *prevTitle;        // 内容标签（广告展示前文章标题）
@property (nonatomic, copy) NSString *postTitle;        // 内容标签（广告展示后文章标题）
@property (nonatomic, copy) NSString *historyTitle;     // 内容标签（用户最近浏览文章标题）
@property (nonatomic, copy) NSString *channel;          // 频道标签

@end

NS_ASSUME_NONNULL_END
