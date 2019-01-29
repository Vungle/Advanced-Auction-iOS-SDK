//
//  VGARewardedVideoAdDelegate.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetwork.h>
#import <VungleAdvancedAuctionSDK/VGAReward.h>

@class VGARewardedVideoAd;

/**
 * Delegate for receiving events from a VGARewardedVideoAd such as ad requests
 * succeeding/failing.
 */
@protocol VGARewardedVideoAdDelegate<NSObject>

@required
/**
 * Tells the delegate that the reward video ad has rewarded the user.
 */
- (void)rewardedVideoAd:(VGARewardedVideoAd *)rewardedVideoAd
didRewardUserWithReward:(VGAReward *)reward;

@optional
/**
 * Indicates that there is an ad network did load the the rewarded video ad.
 */
- (void)rewardedVideoAdDidLoad:(VGARewardedVideoAd*)rewardedVideoAd
                withAdNetwork:(VGAAdNetwork *)adNetwork;


/**
 * Indicates that there is at least one ad network did load the the rewarded video ad.
 */
- (void)rewardedVideoAdDidLoad:(VGARewardedVideoAd*)rewardedVideoAd;

/**
 * Indicates that there is an ad network failed to load the rewarded video ad.
 */
- (void)rewardedVideoAd:(VGARewardedVideoAd*)rewardedVideoAd
 didFailToLoadWithError:(NSError*)error withAdNetwork:(VGAAdNetwork *)adNetwork;

/**
 * Indicates that all ad networks failed to load the the rewarded video ad.
 */
- (void)rewardedVideoAd:(VGARewardedVideoAd*)rewardedVideoAd didFailToLoadWithError:(NSError*)error;

/**
 * Notifies the delegate that the rewarded video ad would be presented.
 */
- (void)rewardedVideoAdWillPresent:(VGARewardedVideoAd*)rewardedVideoAd;

/**
 * Notifies the delegate that the rewarded video ad has been presented.
 */
- (void)rewardedVideoAdDidPresent:(VGARewardedVideoAd*)rewardedVideoAd;

/**
 * Notifies the delegate that the rewarded video ad has failed to present with some error.
 */
- (void)rewardedVideoAd:(VGARewardedVideoAd*)rewardedVideoAd
didFailToPresentWithError:(NSError*)error;

/**
 * Notifies the delegate that the rewarded video ad will be dismissed.
 */
- (void)rewardedVideoAdWillDismiss:(VGARewardedVideoAd*)rewardedVideoAd;

/*
 * Notifies the delegate that the rewarded video ad has been dismissed.
 */
- (void)rewardedVideoAdDidDismiss:(VGARewardedVideoAd*)rewardedVideoAd;

/*
 * Notifies the delegate that the rewarded video ad has been clicked.
 */
- (void)rewardedVideoAdDidGetClick:(VGARewardedVideoAd*)rewardedVideoAd;

/**
 * Notifies the delegate that the user will leave application context.
 */
- (void)userWillLeaveApplicationFromRewardedVideoAd:(VGARewardedVideoAd*)rewardedVideoAd;

@end
