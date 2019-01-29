//
//  VGAError.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Vungle Advanced Auction SDK error domain.
 */
extern NSString *const kVGAErrorDomain;

/**
 * NSError codes for VGA error domain.
 */
typedef NS_ENUM(NSInteger, VGAErrorCode) {
    /// SDK did NOT initialized
    kVGAErrorSDKNotInitialized,
    
    /// Invalid parameters to initialize SDK.
    kVGAErrorSDKInvalidInitParameters,
    
    /// Unknown / Invalid placement Id
    kVGAErrorInvalidPlacementId,
    
    /// The Ad has been presented
    kVGAErrorAdHasBeenPresented,
    
    /// The Ad NOT ready to present.
    kVGAErrorCanNotPresentAdNotReady,
    
    /// Invalid configuration
    kVGAErrorInvalidConfiguration,
    
    /// Received invalid response.
    kVGAErrorReceivedInvalidResponse,
    
    /// The parameters pass to adapter are invalid
    kVGAErrorMediationInvalidParameter,
    
    /// SDK did not be used correctly, such as run on a background thread
    kVGAErrorSDKWrongUsage,
    
    /// Current device's iOS version too low
    kVGAErrorInvalidiOSVersion,
    
    /// Failed to create adapter for ad networks.
    /// This error happens often because of not integrate the adapter's library.
    kVGAErrorAdapterCreateFailed,
    
    ///The placement type mismatched.
    ///For example, create an interstitial with a placement id, but this placement's type is a rewarded video ad.
    kVGAErrorPlacementTypeMismatched,
    
    /// The backend service is disabled for now.
    /// This error maybe caused by limited resources of the backend or some problem of the publisher's account.
    kVGAErrorServiceDisabled,
    
    /// All Ad networks failed to load
    kVGAErrorAllAdsLoadFailed,
};

NS_ASSUME_NONNULL_END
