//
//  VungleAdvancedAuctionSDK.h
//  Vungle Advanced Auction SDK
//  SDK Version: 1.1.0
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetwork.h>
#import <VungleAdvancedAuctionSDK/VGAAdRequestOptions.h>
#import <VungleAdvancedAuctionSDK/VGAError.h>
#import <VungleAdvancedAuctionSDK/VGAReward.h>
#import <VungleAdvancedAuctionSDK/VGAInterstitial.h>
#import <VungleAdvancedAuctionSDK/VGAInterstitialDelegate.h>
#import <VungleAdvancedAuctionSDK/VGARewardedVideoAd.h>
#import <VungleAdvancedAuctionSDK/VGARewardedVideoAdDelegate.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetworkSettings.h>
#import <VungleAdvancedAuctionSDK/VGABidInfo.h>
#import <VungleAdvancedAuctionSDK/VGAUserConsentInfo.h>
#import <VungleAdvancedAuctionSDK/VGAInterstitialAdapterProtocol.h>
#import <VungleAdvancedAuctionSDK/VGAInterstitialAdapterDelegate.h>
#import <VungleAdvancedAuctionSDK/VGARewardedVideoAdAdapterProtocol.h>
#import <VungleAdvancedAuctionSDK/VGARewardedVideoAdAdapterDelegate.h>


NS_ASSUME_NONNULL_BEGIN

@protocol VungleAdvancedAuctionSDKDelegate <NSObject>
@optional
/**
 * If implemented, this will get called when the SDK has finished initialization.
 * It's only at this point that one can call other APIs to load & play ads.
 */
-(void)sdkDidInitialize;

/**
 * If implemented, this will get called if the SDK fails to initialize.
 * The included NSError object should give some information as to the failure reason.
 * @note If initialization fails, you will need to restart the SDK.
 */
-(void)sdkFailedToInitializeWithError:(NSError *)error;

@end

@interface VungleAdvancedAuctionSDK : NSObject
@property(nonatomic, weak, nullable) id<VungleAdvancedAuctionSDKDelegate> delegate;
@property(atomic, readonly, getter=isInitialized) BOOL initialized;

/**
 * Returns the singleton instance.
 */
+ (instancetype)sharedSDK;

/**
 * Initializes the SDK. You can get your app id on Vungle's dashboard: https://v.vungle.com
 * @param appId the unique identifier for your app
 */
- (void)startWithAppId:(NSString *)appId;

/**
 * Returns the version of the SDK.
 */
+ (NSString *)getVersion;

/**
 * Update User's consent status, suggest call this API before `startWithAppId:`
 */
- (void)updateConsentStatus:(VGAConsentStatus)contentStatus;

/**
 * Get current consent status
 */
- (VGAConsentStatus)getCurrentContentStatus;

@end

/**
 * This is for internal use
 */
@protocol VGASDKLogger <NSObject>

- (void)log:(NSInteger)level
    context:(NSString *)context
    message:(NSString *)message;
@end


NS_ASSUME_NONNULL_END
