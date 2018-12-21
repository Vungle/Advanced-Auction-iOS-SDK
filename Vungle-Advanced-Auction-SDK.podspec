#
# Be sure to run `pod lib lint Vungle-Advanced-Auction-SDK.podspec' to ensure this is a
# valid spec before submitting.
#

Pod::Spec.new do |s|
s.name             = "Vungle-Advanced-Auction-SDK"
s.version          = "1.1.0"
s.summary          = "Vungle's Advanced Auction iOS SDK'"
s.description      = <<-DESC
An SDK for video ad based monetization with the Vungle Advanced Auction solution
DESC

s.homepage         = "http://www.vungle.com/"
s.license          = { :type => "Commercial", :file => "LICENSE.md" }
s.author           = { "Vungle" => "tech-support@vungle.com" }

s.platform     = :ios, '8.0'
s.requires_arc = true

s.source           = { :git => "https://github.com/Vungle/Advanced-Auction-iOS-SDK.git", :tag => "v1.1.0" }
s.vendored_frameworks = 'VungleAdvancedAuctionSDK.framework'
s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }

s.frameworks = 'AdSupport', 'AudioToolbox', 'AVFoundation', 'CFNetwork', 'CoreGraphics', 'CoreMedia', 'MediaPlayer', 'QuartzCore', 'StoreKit', 'SystemConfiguration'
s.weak_framework = 'WebKit', 'UIKit', 'Foundation'
s.libraries = 'z'
end
