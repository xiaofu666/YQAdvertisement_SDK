osx_image: xcode9
language: objective-c

env:
global:
- LANG=en_US.UTF-8
- LC_ALL=en_US.UTF-8
- XCODE_PROJECT=YQAdDemo/TestAdA.xcodeproj
matrix:
- SCHEME="YQAdvertisement_SDK"

before_install:
- gem install xcpretty --no-rdoc --no-ri --no-document --quiet

script:
- set -o pipefail
- xcodebuild -project "$XCODE_PROJECT" -scheme "$SCHEME" -configuration Debug clean build CODE_SIGN_IDENTITY="" CODE_SIGNING_REQUIRED=NO | xcpretty -c

after_success:
- sleep 3

