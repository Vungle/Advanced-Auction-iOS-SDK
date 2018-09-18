//
//  VGAInterstitialAdapterProtocol.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetworkSettings.h>
#import <VungleAdvancedAuctionSDK/VGAInterstitialAdapterDelegate.h>

@protocol VGAInterstitialAdapter<NSObject>

/**
 * The adapter's version
 */
+(NSString*)adapterVersion;

/**
 * The Class of the specified AdNetworkSettings
 */
+(Class<VGAAdNetworkSettings>)adNetworkSettingsClass;

/**
 *
 */
-(instancetype)initWithInterstitialAdapterDelegate:(id<VGAInterstitialAdapterDelegate>)delegate;

/**
 *Do some set up before requesting interstitial.
 */
-(void)setUpForInterstitial;

/**
 * Load an interstitial
 */
-(void)loadInterstitial;

/**
 *Indicates if the interstitial is loaded
 */
-(BOOL)hasInterstitialAvailable;

/**
 *Present the interstitial
 */
-(void)presentInterstitialFromViewController:(UIViewController*)controller;


-(void)stopBeingDelegateForInterstitial;

@end

