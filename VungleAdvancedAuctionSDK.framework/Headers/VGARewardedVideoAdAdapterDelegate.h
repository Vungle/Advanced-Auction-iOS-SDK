//
//  VGARewardedVideoAdAdapterDelegate.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VungleAdvancedAuctionSDK/VGABidInfo.h>
#import <VungleAdvancedAuctionSDK/VGAReward.h>
#import <VungleAdvancedAuctionSDK/VGAUserConsentInfo.h>


@protocol VGAAdNetworkSettings;
@protocol VGARewardedVideoAdAdapter;

/**
 * This protocol is for adapter to request some information or notify SDK when
 * some events did happen, like ad loaded or playing started.
 */
@protocol VGARewardedVideoAdAdapterDelegate<NSObject>

/**
 * The info include the parameters set by the publisher in the Vungle's dashboard.
 * Like appId of the ad network, or placement ids.
 */
-(NSDictionary*)info;

/**
 * The networkSettings include the specified parameters which are set by the publisher.
 */
-(id<VGAAdNetworkSettings>)adNetworkSettings;

/**
 * The user consent information
 */
-(VGAUserConsentInfo *)userConsentInfo;

/**
 * The view ordinal by session
 * Here the session means from app start to exit (killed)
 */
-(NSUInteger)viewOrdinalBySession;

/**
 * The view ordinal by day.(from local time 6:00 AM to 6:00 AM next day)
 */
-(NSUInteger)viewOrdinalByDay;


/**
 * Notifies the delegate that the ad network SDK did set up.
 */
-(void)adapterDidSetUpForRewardedVideoAd:(id<VGARewardedVideoAdAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK failed to set up.
 */
-(void)adapter:(id<VGARewardedVideoAdAdapter>)adapter
didFailToSetUpForRewardedVideoAdWithError:(NSError*)error;

/**
 * Notifies the delegate that the ad network SDK did load rewarded video ad.
 * bidInfo include the bid price or bid token or both of them.
 */
-(void)adapterDidLoadRewardedVideoAd:(id<VGARewardedVideoAdAdapter>)adapter
                         withBidInfo:(VGABidInfo *)bidInfo;

/**
 * Notifies the delegate that the ad network SDK failed to load rewarded video ad.
 */
-(void)adapter:(id<VGARewardedVideoAdAdapter>)adapter
didFailToLoadRewardedVideoAdWithError:(NSError *)error;

/**
 * Notifies the delegate that the ad network SDK will present the rewarded video ad.
 */
-(void)adapterWillPresentRewardedVideoAd:(id<VGARewardedVideoAdAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK has presented the rewarded video ad.
 */
-(void)adapterDidPresentRewardedVideoAd:(id<VGARewardedVideoAdAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK failed to present the rewarded video ad.
 */
-(void)adapter:(id<VGARewardedVideoAdAdapter>)adapter
didFailToPresentRewardedVideoAdWithError:(NSError *)error;

/**
 * Notifies the delegate that the ad network SDK will dismiss the rewarded video ad.
 */
-(void)adapterWillDismissRewardedVideoAd:(id<VGARewardedVideoAdAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK has dismissed the rewarded video ad.
 */
-(void)adapterDidDismissRewardedVideoAd:(id<VGARewardedVideoAdAdapter>)adapter;

/**
 * Notifies the delegate that the user will leave application context.
 */
-(void)adapterWillLeaveApplicationFromRewardedVideoAd:(id<VGARewardedVideoAdAdapter>)adapter;

/**
 * Notifies the delegate that the rewarded video ad has been clicked.
 */
-(void)adapterDidGetRewardedVideoAdClick:(id<VGARewardedVideoAdAdapter>)adapter;

/**
 * Notifies the delegate that the adapter has rewarded the user.
 */
- (void)adapter:(id<VGARewardedVideoAdAdapter>)adapter
didRewardUserWithReward:(VGAReward *)reward;

/**
 * Use to logging debugging messages during adapter's lifecycle.
 */
-(void)logDebug:(NSString *)message, ...NS_FORMAT_FUNCTION(1, 2);

/**
 * Use to logging errors during adapter's lifecycle.
 */
-(void)logError:(NSString *)message, ...NS_FORMAT_FUNCTION(1, 2);




@end
