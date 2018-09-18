//
//  VGARewardedVideoAdAdapterProtocol.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <VungleAdvancedAuctionSDK/VGARewardedVideoAdAdapterDelegate.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetworkSettings.h>

/**
 * This protocol is used to interact with Ad Network SDK to load / present rewarded video ads.
 */
@protocol VGARewardedVideoAdAdapter<NSObject>

/**
 * The adapter's version
 */
+(NSString *)adapterVersion;

/**
 * The Class of the specified AdNetworkSettings
 */
+(Class<VGAAdNetworkSettings>)adNetworkSettingsClass;

/**
 *
 */
-(instancetype)initWithRewardedVideoAdAdapterDelegate:(id<VGARewardedVideoAdAdapterDelegate>)delegate;


/**
 * Do some set up before requesting rewarded video.
 */
-(void)setUpForRewardedVideoAd;

/**
 * Load an rewarded video.
 */
-(void)loadRewardedVideoAd;

/**
 * Indicates if the rewarded video ad loaded
 */
-(BOOL)hasRewardedVideoAdAvailable;

/**
 * Present the rewarded video ad.
 */
-(void)presentRewardedVideoAdFromViewController:(UIViewController*)controller;

/**
 *
 */
-(void)stopBeingDelegateForRewardedVideoAd;

@end
