
Pod::Spec.new do |s|

  s.name         = "YXLaunchAD"
  s.version      = "3.0.2" # 版本号
  s.summary      = "YXLaunchAds is a SDK from CloudDragonfly providing union AD service."
  s.description  = <<-DESC
                   ‘CloudDragonfly provides Union ADs which include native、banner、feed、splash、RewardVideo etc..’
                   DESC
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "小富" => "3290235031@qq.com" }

  s.homepage     = "https://github.com/xiaofu666/YQAdvertisement_SDK"
  s.source       = { :git => "https://github.com/xiaofu666/YQAdvertisement_SDK.git", :tag => s.version.to_s }

  s.platform     = :ios, "8.0"

  s.frameworks = 'UIKit', 'MapKit', 'QuartzCore', 'WebKit', 'Security', 'MediaPlayer', 'CoreLocation', 'AdSupport', 'CoreMedia', 'Foundation', 'AVFoundation', 'CoreTelephony', 'CoreGraphics', 'StoreKit', 'SystemConfiguration', 'MobileCoreServices', 'CoreMotion'
  s.libraries = 'c++', 'resolv', 'xml2', 'z'

  #s.public_header_files = 'YXLaunchAD/Classes/*.h'
  #s.source_files = 'YXLaunchAD/Classes/*'

  s.vendored_frameworks =  'YXLaunchAD/Frameworks/YXLaunchAds.framework'

  s.dependency 'Bytedance-UnionAD', '~> 1.9.9.2'
  s.dependency 'WechatOpenSDK', '~> 1.8.4'

end
