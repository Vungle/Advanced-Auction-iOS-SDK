//
//  VGAUserConsentInfo.h
//  VungleAdvancedAuctionSDK
//
//  Created by frank.zheng on 2018/7/23.
//  Copyright © 2018 Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VGAConsentStatus) {
    VGAConsentUnknown = 0,
    VGAConsentAccepted,
    VGAConsentDenied,
};

@interface VGAUserConsentInfo : NSObject
@property(nonatomic, assign) VGAConsentStatus consentStatus;
@property(nonatomic, assign) BOOL consentRequired; //if user in gdpr region

@end
