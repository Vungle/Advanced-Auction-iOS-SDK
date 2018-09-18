//
//  VGAInterstitial.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <VungleAdvancedAuctionSDK/VGAInterstitialDelegate.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetwork.h>
#import <VungleAdvancedAuctionSDK/VGAAdRequestOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface VGAInterstitial : NSObject

/**
 * The Placement Id.
 */
@property(nonatomic, readonly) NSString *placementId;

/**
 * Because we’ll ask multiple Ad Networks to load ad, here isReady indicates there is at least one ad network ready to play ad.
 */
@property(nonatomic, readonly, getter=isReady) BOOL ready;

/**
 * Indicates if the interstitial has been presented. Can NOT present and load it again.
 */
@property(nonatomic, readonly) BOOL hasBeenPresented;

/**
 * delegate is used to notify some events happened.
 */
@property(nonatomic, weak, nullable) id<VGAInterstitialDelegate> delegate;

/**
 * Which Ad Networks are prepared to present Ads.
 */
@property(nonatomic, readonly) NSArray<VGAAdNetwork *> *preparedAdNetworks;

/**
 * Which Ad Network is presenting the ad.
 */
@property(nonatomic, readonly) VGAAdNetwork *presentingAdNetwork;

/**
 * Initialize with a placement id.
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 * Load interstitial with options
 */
- (void)load:(VGAAdRequestOptions *)options;

/**
 * Present interstitial
 */
- (void)presentFromViewController:(UIViewController *)rootViewController;


@end

NS_ASSUME_NONNULL_END
