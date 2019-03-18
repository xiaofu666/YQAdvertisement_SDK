
Pod::Spec.new do |s|

  s.name         = "TestAdA"
  s.version      = "0.0.1"
  s.summary      = "A delightful iOS advertisement framework."
  s.description  = <<-DESC
                   ‘This is an advertisement SDK.’
                   DESC

  s.homepage     = "https://github.com/xiaofu666/YQAdvertisement_SDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author             = { "小富" => "3290235031@qq.com" }
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/xiaofu666/YQAdvertisement_SDK.git", :tag => "#{s.version}" }

s.subspec 'YXLaunchAD' do |sfLib|
  sfLib.source_files  = ["TestAdA/TestAdA/YXLaunchAD/**/*"]
  #  s.exclude_files = "TestAdA/TestAdA/YXLaunchAD/YXLaunchAds.framework"

  sfLib.public_header_files = ["TestAdA/TestAdA/YXLaunchAD/**/*.h"]

end

s.subspec 'YXLaunchAD' do |sfLib|
sfLib.source_files  = ["TestAdA/TestAdA/YXLaunchAD/**/*"]
#  s.exclude_files = "TestAdA/TestAdA/YXLaunchAD/YXLaunchAds.framework"

sfLib.public_header_files = ["TestAdA/TestAdA/YXLaunchAD/**/*.h"]

end

  s.resources = ["TestAdA/TestAdA/YXLaunchAD/**/*.{bundle}"]

  s.requires_arc = true

  s.dependency 'Bytedance-UnionAD', '~> 1.9.9.2'

end
