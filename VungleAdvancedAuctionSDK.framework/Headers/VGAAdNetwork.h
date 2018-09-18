//
//  VGAAdNetwork.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VGAAdNetwork : NSObject
/**
 * The name of ad network
 */
@property(nonatomic, copy) NSString* name;

- (instancetype)initWithName:(NSString *)name;

@end


NS_ASSUME_NONNULL_END
