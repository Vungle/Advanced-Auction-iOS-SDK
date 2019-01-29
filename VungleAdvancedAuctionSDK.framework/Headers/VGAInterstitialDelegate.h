//
//  VGAInterstitialDelegate.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetwork.h>


NS_ASSUME_NONNULL_BEGIN

@class VGAInterstitial;

/**
 * Delegate for receiving events from a VGAInterstitial such as ad 
 * requests succeeding/failing.
 */
@protocol VGAInterstitialDelegate <NSObject>

@optional

/**
 * Indicates that there is an ad network did load the the intersititial.
 */
- (void)interstitialDidLoad:(VGAInterstitial*)interstitial
             withAdNetwork:(VGAAdNetwork *)adNetwork;

/**
 * Indicates that there is at least one ad network did load the the intersititial.
 */
- (void)interstitialDidLoad:(VGAInterstitial*)interstitial;

/**
 * Indicates that there is an ad network failed to load the interstitial.
 */
- (void)interstitial:(VGAInterstitial*)interstitial
didFailToLoadWithError:(NSError*)error withAdNetwork:(VGAAdNetwork * _Nullable)adNetwork;

/**
 * Indicates that all ad networks failed to load the interstitial.
 */
- (void)interstitial:(VGAInterstitial*)interstitial didFailToLoadWithError:(NSError*)error;

/**
 * Notifies the delegate that the interstitial would be presented.
 */
-(void)interstitialWillPresent:(VGAInterstitial*)interstitial;

/**
 * Notifies the delegate that the interstitial has been presented.
 */
- (void)interstitialDidPresent:(VGAInterstitial*)interstitial;

/**
 * Notifies the delegate that the interstitial has failed to present with some error.
 */
- (void)interstitial:(VGAInterstitial*)interstitial didFailToPresentWithError:(NSError*)error;

/**
 * Notifies the delegate that the interstitial will be dismissed.
 */
- (void)interstitialWillDismiss:(VGAInterstitial*)interstitial;

/**
 * Notifies the delegate that the interstitial has been dismissed.
 */
- (void)interstitialDidDismiss:(VGAInterstitial*)interstitial;

/**
 * Notifies the delegate that the interstitial has been clicked.
 */
- (void)interstitialDidGetClick:(VGAInterstitial*)interstitial;

/**
 * Notifies the delegate that the user will leave application context.
 */
- (void)userWillLeaveApplicationFromInterstitial:(VGAInterstitial*)interstitial;


@end

NS_ASSUME_NONNULL_END
