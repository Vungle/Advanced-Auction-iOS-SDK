//
//  VGAReward.h
//  Vungle Advanced Auction SDK
//
//  Copyright (c) 2013-Present Vungle Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VGAReward : NSObject

/**
 * Type of the reward.
 */
@property(nonatomic, readonly, copy) NSString *type;

/**
 * Amount rewarded to the user.
 */
@property(nonatomic, readonly, copy) NSNumber *amount;

/**
 * Returns an initialized VGAReward with the provided reward type and reward amount. rewardType
 * and rewardAmount must not be nil.
 */
- (instancetype)initWithRewardType:(NSString *)rewardType
                      rewardAmount:(NSNumber *)rewardAmount;

@end

NS_ASSUME_NONNULL_END
