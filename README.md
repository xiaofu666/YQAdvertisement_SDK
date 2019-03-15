

云蜻SDK
iOS 开发文档
用户使用说明







北京云蜻信息技术有限公司
2017年1月




 =============================1.1版本更新说明============================================
1.增加超时处理，超过30秒钟后会返回失败。
 =============================2.0版本更新说明============================================
1.增加广告位icon
 =============================2.1版本更新说明============================================
1.增加广告渠道，SDK中配置开屏显示逻辑
 =============================2.2版本更新说明============================================
1.优化超时请求处理
2.优化开屏展示逻辑
 =============================2.3版本更新说明============================================
1.增加广告内容。
2.优化展示。
 =============================2.4版本更新说明============================================
1.请求超时时间默认5秒，
2.去掉showEnterForeground 属性，此属性不再使用。
3.demo中附带 icon 请求示例，启动页再次请求示例。
4.所有的广告windows不再使用keywindow。
5.第三方framework更新。
 =============================2.5版本更新说明============================================
1.增加banner广告。
2.优化开屏广告。
=============================3.0版本更新说明============================================
1.增加广告点击跳转微信小程序功能。
（若需要此功能请配置
【1】 在你的工程文件中选择Build Setting，在"Other Linker Flags"中加入"-Objc -all_load"，在Search Paths中添加 libWeChatSDK.a ，WXApi.h，WXApiObject.h，
【2】微信开放平台新增了微信模块用户统计功能，便于开发者统计微信功能模块的用户使用和活跃情况。开发者需要在工程中链接上:SystemConfiguration.framework, libz.dylib, libsqlite3.0.dylib, libc++.dylib, Security.framework, CoreTelephony.framework, CFNetwork.framework。
【3】在Xcode中，选择你的工程设置项，选中“TARGETS”一栏，在“info”标签栏的“URL type“添加“URL scheme”为你所注册的应用程序id
【4】在Xcode中，选择你的工程设置项，选中“TARGETS”一栏，在“info”标签栏的“LSApplicationQueriesSchemes“添加weixin
【5】在你需要使 用微信终端API的文件中import WXApi.h 头文件，并增加 WXApiDelegate 协议。
    1.要使你的程序启动后微信终端能响应你的程序，必须在代码中向微信终端注册你的id。（在 AppDelegate 的 didFinishLaunchingWithOptions 函数中向微信注册id）
    2.重写AppDelegate的handleOpenURL和openURL方法：）
https://open.weixin.qq.com/cgi-bin/showdocument?action=dir_list&t=resource/res_list&verify=1&id=open1419319164&token=&lang=zh_CN


2.增加原生广告。
 =============================3.2版本更新说明============================================
1.优化轮播banner展示
2.添加pageController，默认显示
 =============================3.3版本更新说明============================================
1.增加更多尺寸的banner显示
2.增加自定义大小的原生尺寸广告数据









1、概述	3
2、集成准备	3
3、配置工程	3
4、开屏广告初始化及使用	4
5、ICON广告使用说明	5
6、原生广告使用说明	5
7、集成建议	6
8、关于点开广告跳转微信小程序的功能	6
9、常见问题	6
10、关于审核	7

 


1、概述
本文档描述了iOS 开发者如何集成云蜻SDK产品。 云蜻SDK提供了多种广告形式，包括：原生广告、广告墙、开屏、横幅、ICON、插屏等。
2、集成准备
1)	申请账号：开发者从云蜻SDK后台运营人员处获取账号、密码后，登录云蜻SDK系统后台。
2)	媒体位id：开发者每创建一个应用后，系统会自动生成媒体位id，可在云蜻SDK后台界面查看到已创建的应用以及对应的媒体位id。
3、配置工程
1）YXLaunchAD文件夹下的   YXLaunchAds.framework  、ThirdAdLibs文件夹以及其中的文件 ，这两个为广告SDK整体，如果项目中有的话可以不用导入。 
将 上述添加到XCode项目中
添加依赖项 	
libxml2.tbd 
WebKit.framework
AVFoundation.framework
Libz.tbd 
Security.framework 
AdSupport.framework 
CoreLocation.framework 
QuartzCore.framework 
SystemConfiguation.framework 
CoretTelephony.framework
CoreGraphics.framework
UIKit.framework
Foundation.framework 
CoreMotion.framework 
Libresolv.9.tbd
Libc++.tbd 
libsqlite3.0.tbd 
CFNetwork.framework，

2）配置ATS  Info.Plist: 
<key>NSAppTransportSecurity</key>
		<dict>
        		<key>NSAllowsArbitraryLoads</key>
        		<true/>
			 
	</dict>
3）在Other Linker Flags添加配置   -ObjC   -all_load
4、开屏广告初始化及使用
1）导入#import <YXLaunchAds/YXLaunchAdManager.h>
2）遵循代理 <YXLaunchAdManagerDelegate>
3）广告页面呈现在一个不是keywindow的windows上 ，建议开屏广告的初始化放在第一位。
非全屏示例：
    YXLaunchAdManager *adManager = [YXLaunchAdManager shareManager];
    adManager.waitDataDuration = 3;
    adManager.duration = 5;
    adManager.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width,   [UIScreen mainScreen].bounds.size.height * 0.8);//屏幕高度的百分之八十为广告部分
    adManager.mediaId = @"*******";//媒体位id，由我们运营提供
    adManager.adType = YXScreenType;
      adManager.imageOption = YXLaunchAdImageDefault;
    adManager.contentMode = UIViewContentModeScaleAspectFill;
    adManager.showFinishAnimate = ShowFinishAnimateFadein;
    adManager.showFinishAnimateTime = 0.8;
    adManager.skipButtonType = SkipTypeRoundProgressTime; 
    adManager.delegate = self; 
    [adManager loadLaunchAdWithShowAdWindow:self.window];
5、icon广告使用说明
1）导入 #import <YXLaunchAds/YXIconAdManager.h>
2）遵循代理  <YXIconAdManagerDelegate>
3）使用示例

 iconAd = [[YXIconAdManager alloc]initWithFrame:CGRectMake(100, 100, 128, 128) adType:YXIconType delegate:self mediaId:@"********"];
6、原生广告使用说明
1）导入 #import <YXLaunchAds/YXFeedAdManager.h> 
  #import "YXFeedAdRegisterView.h"

2）遵循代理 YXFeedAdManagerDelegate3）使用示例

3）使用示例
feedManager = [YXFeedAdManager new];
    feedManager.adSize = YXADSize690X388;
    feedManager.mediaId = feedMediaID;
    
    feedManager.controller = self;
    feedManager.delegate = self;
    [feedManager loadFeedAd];
    
请求成功后再去注册：
[feedManager registerAdViewForInteraction:self.registAdView];
7、集成建议
建议等待时间设置为5秒，展示时间设置为5秒。
App在从后台5分钟后到前台时 建议也加上开屏广告。使用示例详情见demo。 
  
8、关于点开广告跳转微信小程序的功能
！若需要此功能请配置
【1】 在你的工程文件中选择Build Setting，在"Other Linker Flags"中加入"-Objc -all_load"，在Search Paths中添加 libWeChatSDK.a ，WXApi.h，WXApiObject.h，
【2】微信开放平台新增了微信模块用户统计功能，便于开发者统计微信功能模块的用户使用和活跃情况。开发者需要在工程中链接上:SystemConfiguration.framework, libz.dylib, libsqlite3.0.dylib, libc++.dylib, Security.framework, CoreTelephony.framework, CFNetwork.framework。
【3】在Xcode中，选择你的工程设置项，选中“TARGETS”一栏，在“info”标签栏的“URL type“添加“URL scheme”为你所注册的应用程序id
【4】在Xcode中，选择你的工程设置项，选中“TARGETS”一栏，在“info”标签栏的“LSApplicationQueriesSchemes“添加weixin
【5】 在你需要使用微信终端API的文件中import WXApi.h 头文件，并增加 WXApiDelegate 协议。
    1.要使你的程序启动后微信终端能响应你的程序，必须在代码中向微信终端注册你的id。（在 AppDelegate 的 didFinishLaunchingWithOptions 函数中向微信注册id）
    2.重写AppDelegate的handleOpenURL和openURL方法：）
9、常见问题
测试的时候无广告或者不展示广告. 
   答：首先检查网络是否正常，国外广告需要使用vpn代理，其次检查传入的 Key 和运营分配的是否一致.

10、关于审核
问：在将我的iOS应用程序提交给Apple进行审核时，我需要选择哪些与IDFA相关的选项？
答：将我们的SDK集成到您的iOS应用程序后，您需要将您的应用程序提交给Apple进行审核。作为此审核流程的一部分，系统会询问您的应用是否使用广告标识符（IDFA）。请选中“是”。然后，系统会询问您的应用如何使用它。问题将采用以下形式：
此应用使用广告标识符（选择所有适用的选项）？
1.在应用内投放广告
2.将此应用安装归因于之前提供的广告
3.将此应用程序中采取的操作归因于先前投放的广告
如果您将使用AD框架，则必须选择第一个选项。 
系统还会要求您选中一个框以确认您的应用是否符合iOS中用户的限制广告跟踪设置。SDK尊重iOS有限广告跟踪设置。当某人启用有限广告跟踪时，SDK仅使用通过使用广告标识符获得的数据，用于iOS开发者计划许可协议中定义的“有限广告目的”。请在提示时确保选中此框。

以这种方式标记这些问题将有助于确保顺利的审核过程。

