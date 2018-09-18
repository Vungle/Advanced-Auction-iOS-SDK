//
//  VGAAdRequestOptions.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VungleAdvancedAuctionSDK/VGAAdNetworkSettings.h>

NS_ASSUME_NONNULL_BEGIN

@interface VGAAdRequestOptions : NSObject

/**
 * The user identifier that will be passed if the ad is incentivized.
 * The value passed as 'user' in the an incentivized server-to-server call.
 * Note: This may not be valid for some ad networks.
 */
@property(nonatomic, copy, nullable) NSString *userId;

/**
 * Controls whether presented ads will start in a muted state or not.
 * Note: This may not be valid for some ad networks.
 */
@property(nonatomic, assign) BOOL muted;

/**
 * This is an integer indicating the order in which this ad was shown in the game session.
 * (for example, if two ads were already shown in this session, and this ad from Vungle was then shown third, pass in '3').
 * Note: This may not be valid for some ad networks.
 */
@property(nonatomic, assign) NSUInteger ordinal;

/**
 * Ad networks may have additional parameters they accept. To pass these parameters to them, create
 * the ad network settings object for that network, fill in the parameters, and add it here. The
 * ad network should have a header defining the interface for the 'settings' object to create. All
 * networks will have access to the basic settings you've set in this VGAAdRequestOptions (userId, muted,
 * ordinal etc.). If you added a settings object that is the same class as one you have
 * registered before, the previous settings will be overwritten.
 */
- (void)addAdNetworkSettings:(id<VGAAdNetworkSettings>)adNetworkSettings;

/**
 * Returns the network settings defined for an ad network.
 */
- (id<VGAAdNetworkSettings>)adNetworkSettingsFor:(Class<VGAAdNetworkSettings>)aClass;

/**
 * Removes the settings for an ad network. |aClass| is the class which represents that network's
 * extras type.
 */
- (void)removeAdNetworkSettings:(Class<VGAAdNetworkSettings>)aClass;


@end

NS_ASSUME_NONNULL_END
