
Pod::Spec.new do |s|

  s.name         = "YXLaunchAD"
  s.version      = "4.5.4" # 版本号
  s.summary      = "YXLaunchAds is a SDK from CloudDragonfly providing union AD service."
  s.description  = <<-DESC
                   ‘CloudDragonfly provides Union ADs which include native、banner、feed、splash、RewardVideo etc..’
                   DESC
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "小富" => "3290235031@qq.com" }

  s.homepage     = "https://github.com/xiaofu666/YQAdvertisement_SDK"
  s.source       = { :git => "https://github.com/xiaofu666/YQAdvertisement_SDK.git", :tag => s.version.to_s }

  s.platform     = :ios, "9.0"

  s.frameworks = 'AssetsLibrary', 'MapKit', 'JavaScriptCore', 'StoreKit', 'MobileCoreServices', 'WebKit', 'MediaPlayer', 'CoreMedia', 'AVFoundation', 'CoreLocation', 'CoreTelephony', 'SystemConfiguration', 'AdSupport', 'CoreMotion', 'Security', 'QuartzCore', 'CoreGraphics', 'SafariServices', 'UIKit', 'Foundation', 'AppTrackingTransparency'
  s.libraries = 'c++', 'resolv', 'xml2', 'bz2', 'z', 'iconv', 'sqlite3'

  s.vendored_frameworks =  'YXLaunchAD/Frameworks/*.framework'
  s.resource = 'YXLaunchAD/Frameworks/XibAndPng.bundle'
  
  s.xcconfig = { "OTHER_LDFLAGS" => "-ObjC" }
  s.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => '' }

  s.dependency 'Ads-CN'
  s.dependency 'GDTMobSDK'
  s.dependency 'KSAdSDK'
  s.dependency 'JztSDK'
  
end
