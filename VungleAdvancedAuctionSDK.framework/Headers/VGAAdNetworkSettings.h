//
//  VGAAdNetworkSettings.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An object implementing this protocol contains parameters set by the publisher on the client
 * device for a particular ad network.
 * Ad networks should create an 'settings' class implementing this protocol for their publishers to
 * use.
 */
@protocol VGAAdNetworkSettings<NSObject>

@end


NS_ASSUME_NONNULL_END
