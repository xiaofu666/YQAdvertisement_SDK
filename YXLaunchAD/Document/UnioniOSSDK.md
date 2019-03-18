# 云蜻广告 iOS SDK 接入说明

| 文档版本| 修订日期| 修订说明|
| --- | --- | --- |
| v1.0 | 2018-3-23 | 创建文档，支持Banner，信息流广告|
| v1.1 | 2018-5-21 | 增加超时处理，超过30秒钟后会返回失败。|
| v2.0 | 2018-6-30 | 增加广告位icon|
| v2.1 | 2018-7-17 | 增加广告渠道，SDK中配置开屏显示逻辑|
| v2.2 | 2018-8-28 | 优化超时请求处理.优化开屏展示逻辑   |
| v2.3 | 2018-9-2 | 增加广告内容，优化展示|
| v2.4 | 2018-9-25 | 【1】请求超时时间默认5秒 【2】去掉showEnterForeground 属性，此属性不再使用【3】demo中附带 icon 请求示例，启动页再次请求示例 【4】所有的广告windows不再使用keywindow 【5】第三方framework更新 |
| v2.5 | 2018-10-04 |【1】增加banner广告 【2】优化开屏广告 |
| v2.8 | 2018-11-10 |【1】增加广告点击跳转微信小程序功能。【2】微信开放平台新增了微信模块用户统计功能 【3】增加原生广告。 |
| v2.9  | 2018-12-16 |【1】优化轮播banner展示【2】添加pageController，默认显示 |
| v3.0 | 2018-06-12 |【1】增加更多尺寸的banner显示 【2】增加自定义大小的原生尺寸广告数据 |
<!-- TOC -->

- [云蜻广告 iOS SDK 接入说明](#云蜻广告-ios-sdk-接入说明)
    - [1. iOS SDK接入](#1-ios-sdk接入)
        - [1.1 iOS SDK导入framework](#11-ios-sdk导入framework)
            - [1.1.1 申请应用的AppID和SlotID](#111-申请应用的appid和slotid)
            - [1.1.2 工程设置导入framework](#112-工程设置导入framework)
            - [方法一：](#方法一)
            - [方法二：](#方法二)
        - [1.2 Xcode编译选项设置](#12-xcode编译选项设置)
            - [1.2.1 添加权限](#121-添加权限)
            - [1.2.2 运行环境配置](#122-运行环境配置)
            - [1.2.3 添加依赖库](#123-添加依赖库)
    - [2. SDK接口类介绍与广告接入](#2-sdk接口类介绍与广告接入)
        - [2.1 全局设置](#21-全局设置)
        - [2.2 原生广告](#22-原生广告)
        - [2.3 Icon广告](#23-Icon广告)
        - [2.4 原生banner广告](#24-原生banner广告)
        - [2.5 原生插屏广告](#25-原生插屏广告)
        - [2.6 开屏广告](#26-开屏广告)
        - [2.7 激励视频](#27-激励视频)

    - [附录](#附录)
        - [SDK错误码](#sdk错误码)
        - [FAQ](#faq)

<!-- /TOC -->


## 1. iOS SDK接入

### 1.1 iOS SDK导入framework

#### 1.1.1 申请应用的AppID和SlotID

请向云蜻广告平台申请媒体位ID。

#### 1.1.2 工程设置导入framework
#### 方法一：

获取 framework 文件后直接将 {YXLaunchAD}文件拖入工程即可。

拖入时请按以下方式选择：

![image](images/bu_1.jpeg)

拖入完请确保Copy Bundle Resources中有BUAdSDK.bundle，否则可能出现incon图片加载不出来的情况。

![image](images/bu_5.jpeg)

#### 方法二：

SDK1982版本以后支持pod方式接入，只需配置pod环境，在podfile文件中加入以下代码即可接入成功。
```
pod 'YXLaunchAD', '~> 0.0.5'
```
更多关于pod方式的接入请参考 [gitthub地址](https://github.com/xiaofu666/YQAdvertisement_SDK)

### 1.2 Xcode编译选项设置

#### 1.2.1 添加权限

 **注意要添加的系统库**

+ 工程plist文件设置，点击右边的information Property List后边的 "+" 展开

添加 App Transport Security Settings，先点击左侧展开箭头，再点右侧加号，Allow Arbitrary Loads 选项自动加入，修改值为 YES。 SDK API 已经全部支持HTTPS，但是广告主素材存在非HTTPS情况。

```json
<key>NSAppTransportSecurity</key>
    <dict>
         <key>NSAllowsArbitraryLoads</key>
         <true/>
    </dict>
```
具体操作如图：

![image](images/bu_2.jpeg)

+ Build Settings中Other Linker Flags **增加参数-ObjC**，SDK同时支持-all_load

具体操作如图：

![image](images/bu_3.jpeg)

#### 1.2.2 运行环境配置

+ 支持系统 iOS 8.X 及以上;
+ SDK编译环境 Xcode 9.4, Base SDK 11.1;
+ 支持架构：i386, x86-64, armv7, armv7s, arm64

#### 1.2.3 添加依赖库
工程需要在TARGETS -> Build Phases中找到Link Binary With Libraries，点击“+”，依次添加下列依赖库	

+ StoreKit.framework
+ MobileCoreServices.framework
+ WebKit.framework
+ MediaPlayer.framework
+ CoreMedia.framework
+ AVFoundation.framework
+ CoreLocation.framework
+ CoreTelephony.framework
+ SystemConfiguration.framework
+ AdSupport.framework
+ CoreMotion.framework
+ libresolv.9.tbd
+ libc++.tbd
+ libz.tbd
+ libxml2.tbd 
+ Security.framework  
+ QuartzCore.framework 
+ CoreGraphics.framework
+ UIKit.framework
+ Foundation.framework 


具体操作如图所示：

![image](images/bu_4.png)

## 2. SDK接口类介绍与广告接入

### 2.1 全局设置

#### 2.1.1 使用

SDK 需要在 AppDelegate 的方法 ```- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions``` 里进行初始化

其中以下设置是 **必须** 的，应用相关 appID 设置：

``` Objective-C
[YXAdSDKManager defaultManager]; //工程初始化
```

更多使用方式可以参见 SDK Demo 工程

### 2.2 原生广告
+ **类型说明：** 广告原生广告即一般广告样式，形式分为图文和视频，按场景又可区分为原生banner、原生插屏广告等。

+ **使用说明：** 在SDK里只需要使用 YXFeedAdManager 就可以获取原生广告，YXFeedAdManager 类提供了原生广告的数据类型等各种信息，在数据获取后可以在属性 data（YXFeedAdData）里面获取广告数据信息。

### 2.3 Icon广告

+ **类型说明：**Icon广告主要是 APP 中展示一个小图标，用户点击可跳到对应的广告业或者小程序。具体可参考Demo中YXIconViewController部分示例代码

### 2.4 原生banner广告
+ **类型说明：**原生banner广告是为满足媒体多元化需求而开发的一种原生广告。
+ **使用说明：**SDK可提供数据绑定、点击事件的上报、响应回调，开发者进行自渲染，接入方式同原生广告相同。具体可参考Demo中YXBannerViewController部分示例代码

### 2.5 原生插屏广告
+ **类型说明：**原生插屏广告是为满足媒体多元化需求而开发的一种原生广告。
+  **使用说明：**SDK可提供数据绑定、点击事件的上报、响应回调，开发者进行自渲染，接入方式同原生广告相同。具体可参考Demo中YXInterstitialViewController部分示例代码

### 2.6 开屏广告

+ **类型说明：**开屏广告主要是 APP 启动时展示的全屏广告视图，开发只要按照接入标准就能够展示设计好的视图。具体可参考Demo中YXInterstitialViewController部分示例代码

### 2.6 轮播广告

+ **类型说明：**轮播广告主要是在APP 中展示的广告轮播视图，开发只要按照接入标准就能够展示设计好的视图。具体可参考Demo中YXScrollerBannerViewController部分示例代码

### 2.7 激励视频

+ **类型说明：**激励视频广告是一种全新的广告形式，用户可选择观看视频广告以换取有价物，例如虚拟货币、应用内物品和独家内容等等；这类广告的长度为 15-30 秒，不可跳过，且广告的结束画面会显示结束页面，引导用户进行后续动作。具体可参考Demo中YXMotivationVideoViewController部分示例代码



## 附录

下面是各种error code的值

```Objective-C
    ErrorCode        = -3,     // 解析的数据没有广告
    ErrorCode         = -2,     // 网络请求失败
    ErrorCode       = -1,     // 解析失败
    ErrorCode       = 10001,  // 参数错误
    ErrorCode          = 10002,
    ErrorCode          = 20000,
    ErrorCode             = 20001,  // 没有广告
    ErrorCode       = 40000,  // http conent_type错误
    ErrorCode       = 40001,  // http request pb错误
    ErrorCode         = 40002,  // 请求app不能为空
    ErrorCode         = 40003,  // 请求wap不能为空
    ErrorCode       = 40004,  // 缺少广告位描述
    ErrorCode       = 40005,  // 广告位尺寸 不合法
    ErrorCode       = 40006,  // 广告位 ID 不合法
    ErrorCode       = 40007,  // 请求广告数量 错误
    ErrorCode       = 50001   // 广告服务器错误
    服务器错误码
    ErrorCode       = 40008 //没有填写素材尺寸，或者素材尺寸大于 10000
    ErrorCode	     = 40009 //媒体是空，或者没有运行
    ErrorCode       = 40015 //媒体已经被通知整改三次以上,进行校验,如果字段非法,则不返回广告
    ErrorCode      = 40016 //请求的 appid 与媒体平台的 appid 不一致 
    									  = 40018 //SDK包名与广告配置包名不一致

```


### FAQ
1. 媒体平台配置了只出小图和组图，为什么会返回大图？（类似返回素材类型和媒体平台不符问题）

	答：先check下接入版本，1.2.0及之前版本的SDK对素材类型解析有问题，如果版本问题建议升级；

2. iOS的广告页面在我们app内打开，没有办法关闭或返回。

	答：无法返回是由于 您的主页ViewController 隐藏了NavigationBar；

3.	发现头条 SDK里 BUWebViewController 类 TTRUIWebView 类有内存泄漏。

	答：是系统的问题， UIWebView 一致有泄漏， 我们后续会考虑用 WKWebView 替换

4. iOS集成的包大小是多少?

	答	: 根据我们demo打包后的计算为3M左右. 但是具体大小会根据导入的功能有所差别. 实际情况以集成后的包大小为主.
			