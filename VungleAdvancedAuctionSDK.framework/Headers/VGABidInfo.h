//
//  VGABidInfo.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VGABidInfo : NSObject

@property(nonatomic, copy) NSString *bidToken;

@property(nonatomic, copy) NSNumber *bidPrice;

-(instancetype)initWithBidPrice:(NSNumber * _Nullable)bidPrice bidToken:(NSString * _Nullable)bidToken;

-(BOOL)isValid;


@end

NS_ASSUME_NONNULL_END
