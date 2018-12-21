//
//  VGAInterstitialAdapterDelegate.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VungleAdvancedAuctionSDK/VGABidInfo.h>
#import <VungleAdvancedAuctionSDK/VGAUserConsentInfo.h>


@protocol VGAAdNetworkSettings;
@protocol VGAInterstitialAdapter;


@protocol VGAInterstitialAdapterDelegate<NSObject>
/**
 * The info include the parameters set by the publisher in the vungle's dashboard. Like appId of the ad network, or placement ids.
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
 * Adapter need use this numer + 1 to pass to ad network for current view.
 */
-(NSUInteger)viewOrdinalBySession;

/**
 * The view ordinal by day.(from local time 6:00 AM to 6:00 AM next day)
 * Adapter need use this numer + 1 to pass to ad network for current view.
 */
-(NSUInteger)viewOrdinalByDay;


/**
 * Notifies the delegate that the ad network SDK did set up.
 */
-(void)adapterDidSetUpForInterstitial:(id<VGAInterstitialAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK failed to set up.
 */
-(void)adapter:(id<VGAInterstitialAdapter>)adapter
didFailToSetUpForInterstitialWithError:(NSError*)error;

/**
 * Notifies the delegate that the ad network SDK did load interstitial.
 * bidInfo include the bid price or bid token or both of them.
 * Will define some constants for the keys.
 */
-(void)adapterDidLoadInterstitial:(id<VGAInterstitialAdapter>)adapter
                      withBidInfo:(VGABidInfo *)bidInfo;

/**
 * Notifies the delegate that the ad network SDK failed to load interstitial.
 */
-(void)adapter:(id<VGAInterstitialAdapter>)adapter
didFailToLoadInterstitialWithError:(NSError *)error;

/**
 * Notifies the delegate that the ad network SDK will present the interstitial.
 */
-(void)adapterWillPresentInterstitial:(id<VGAInterstitialAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK has presented the interstitial.
 */
-(void)adapterDidPresentInterstitial:(id<VGAInterstitialAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK failed to present the interstitial.
 */
-(void)adapter:(id<VGAInterstitialAdapter>)adapter
didFailToPresentInterstitialWithError:(NSError*)error;

/**
 * Notifies the delegate that the ad network SDK will dismiss the interstitial.
 */
-(void)adapterWillDismissInterstitial:(id<VGAInterstitialAdapter>)adapter;

/**
 * Notifies the delegate that the ad network SDK has dismissed the interstitial.
 */
-(void)adapterDidDismissInterstitial:(id<VGAInterstitialAdapter>)adapter;

/**
 * Notifies the delegate that the user will leave application context.
 */
-(void)adapterWillLeaveApplicationFromInterstitial:(id<VGAInterstitialAdapter>)adapter;

/**
 * Notifies the delegate that the interstitial has been clicked.
 */
-(void)adapterDidGetInterstitialClick:(id<VGAInterstitialAdapter>)adapter;


/**
 * Use to logging debugging messages during adapter's lifecycle.
 */
-(void)logDebug:(NSString *)message, ...NS_FORMAT_FUNCTION(1, 2);

/**
 * Use to logging errors during adapter's lifecycle.
 */
-(void)logError:(NSString *)message, ...NS_FORMAT_FUNCTION(1, 2);



@end
