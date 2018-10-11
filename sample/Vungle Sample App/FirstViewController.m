//
//  FirstViewController.m
//  Vungle Sample App
//
//  Created by Vungle on 3/24/14.
//  Copyright (c) 2017 Vungle. All rights reserved.
//

#import "FirstViewController.h"
@import VungleAdvancedAuctionSDK;

static NSString *const kVungleAppIDPrefix = @"AppID: ";
static NSString *const kVungleInterstitialPrefix = @"Interstitial: ";
static NSString *const kVungleRewardedVideoAdPrefix = @"Rewarded Video Ad: ";

static NSString *const kVungleTestAppID = @"5aa9e7dc7db3b73d270148e7";
static NSString *const kVungleTestPlacementID01 = @"DEFAULT-1337376";
static NSString *const kVungleTestPlacementID02 = @"REWARDEDTEST1-5264189";

@interface FirstViewController () <VungleAdvancedAuctionSDKDelegate, VGAInterstitialDelegate, VGARewardedVideoAdDelegate>

@property (weak, nonatomic) IBOutlet UILabel *appIdLabel;
@property (weak, nonatomic) IBOutlet UILabel *placementIdLabel1;
@property (weak, nonatomic) IBOutlet UILabel *placementIdLabel2;

@property (weak, nonatomic) IBOutlet UIButton *sdkInitButton;
@property (weak, nonatomic) IBOutlet UIButton *loadButton1;
@property (weak, nonatomic) IBOutlet UIButton *loadButton2;
@property (weak, nonatomic) IBOutlet UIButton *playButton1;
@property (weak, nonatomic) IBOutlet UIButton *playButton2;
@property (weak, nonatomic) IBOutlet UIButton *checkCurrentStatusButton;

@property (nonatomic, strong) VungleAdvancedAuctionSDK *sdk;
@property (nonatomic, strong) VGAInterstitial *interstitial;
@property (nonatomic, strong) VGARewardedVideoAd *rewardedVideoAd;


@end

@implementation FirstViewController

#pragma mark - UIViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setViewDefault];
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

- (IBAction)onInitButtonTapped:(id)sender {
    [self startVungle];
}

- (IBAction)onLoadButtonTapped:(id)sender {
    if (sender == self.loadButton1) {
        [self loadInterstitial];
    } else if(sender == self.loadButton2) {
        [self loadRewardedVideoAd];
    }
    [self updateButtonState:sender enabled:NO];
}

- (IBAction)onPlayButtonTapped:(id)sender {
    if (sender == self.playButton1) {
        [self playInterstitial];
    } else if(sender == self.playButton2) {
        [self playRewardedVideoAd];
    }
}


- (IBAction)onCheckCurrentStatusButtonTapped:(id)sender {
    NSLog(@"SDK Initialized: %@", self.sdk.initialized ? @"YES":@"NO");
    NSLog(@"Interstitial loaded: %@", self.interstitial.isReady ? @"YES":@"NO");
    NSLog(@"Rewarded Video Ad loaded: %@", self.rewardedVideoAd.isReady ? @"YES":@"NO");
}

#pragma mark - FirstView Methods

- (void)setViewDefault {
    self.appIdLabel.text = [kVungleAppIDPrefix stringByAppendingString:kVungleTestAppID];
    self.placementIdLabel1.text = [kVungleInterstitialPrefix stringByAppendingString:kVungleTestPlacementID01];
    self.placementIdLabel2.text = [kVungleRewardedVideoAdPrefix stringByAppendingString:kVungleTestPlacementID02];

    [self updateButtonState:self.loadButton1 enabled:NO];
    [self updateButtonState:self.loadButton2 enabled:NO];
    [self updateButtonState:self.playButton1 enabled:NO];
    [self updateButtonState:self.playButton2 enabled:NO];
}

- (void)updateButtons {
    [self updateButtonState:self.loadButton1 enabled:YES];
    [self updateButtonState:self.loadButton2 enabled:YES];
}

    

- (void)startVungle {
    [self updateButtonState:self.sdkInitButton enabled:NO];
    
    self.sdk = [VungleAdvancedAuctionSDK sharedSDK];
    self.sdk.delegate = self;
    [self.sdk startWithAppId:kVungleTestAppID];
    
}

- (void)loadInterstitial {
    _interstitial = [[VGAInterstitial alloc] initWithPlacementId:kVungleTestPlacementID01];
    _interstitial.delegate = self;
    VGAAdRequestOptions *options = [[VGAAdRequestOptions alloc] init];
    [_interstitial load:options];
}

- (void)loadRewardedVideoAd {
    _rewardedVideoAd = [[VGARewardedVideoAd alloc] initWithPlacementId:kVungleTestPlacementID02];
    _rewardedVideoAd.delegate = self;
    VGAAdRequestOptions *options = [[VGAAdRequestOptions alloc] init];
    [_rewardedVideoAd load:options];
}

- (void)playInterstitial {
    if (_interstitial.isReady) {
        [_interstitial presentFromViewController:self];
    }
}

- (void)playRewardedVideoAd {
    if (_rewardedVideoAd.isReady) {
        [_rewardedVideoAd presentFromViewController:self];
    }
}

- (void)updateButtonState:(UIButton *) button enabled:(BOOL)enabled {
    button.enabled = enabled;
    button.alpha = (enabled? 1.0:0.45);
}

#pragma mark - VungleAdvancedAuctionSDKDelegate methods

-(void)sdkDidInitialize {
    NSLog(@"sdkDidInitialize");
    [self updateButtons];
}

-(void)sdkFailedToInitializeWithError:(NSError *)error {
    NSLog(@"sdkFailedToInitializeWithError: %@", error);
}

#pragma mark - VGAInterstitialDelegate methods
- (void)interstitialDidLoad:(VGAInterstitial*)interstitial withAdNetwork:(VGAAdNetwork *)adNetwork {
    NSLog(@"interstitialDidLoad, ad network:%@", adNetwork.name);
    [self updateButtonState:self.playButton1 enabled:YES];
}

- (void)interstitial:(VGAInterstitial*)interstitial didFailToLoadWithError:(NSError*)error withAdNetwork:(VGAAdNetwork * _Nullable)adNetwork {
    NSLog(@"interstitialDidLoadWithError:%@, ad network:%@", error, adNetwork.name);
}

-(void)interstitialWillPresent:(VGAInterstitial*)interstitial {
    NSLog(@"interstitialWillPresent");
}

- (void)interstitialDidPresent:(VGAInterstitial*)interstitial {
    NSLog(@"interstitialDidPresent");
}

- (void)interstitial:(VGAInterstitial*)interstitial didFailToPresentWithError:(NSError*)error {
    NSLog(@"interstitial:didFailToPresentWithError, %@", error);
}

- (void)interstitialWillDismiss:(VGAInterstitial*)interstitial {
    NSLog(@"interstitialWillDismiss");
}

- (void)interstitialDidDismiss:(VGAInterstitial*)interstitial {
    NSLog(@"interstitialDidDismiss");
    [self updateButtonState:self.loadButton1 enabled:YES];
    [self updateButtonState:self.playButton1 enabled:NO];
}

- (void)interstitialDidGetClick:(VGAInterstitial*)interstitial {
    NSLog(@"interstitialDidGetClick");
}

- (void)userWillLeaveApplicationFromInterstitial:(VGAInterstitial*)interstitial {
    NSLog(@"userWillLeaveApplicationFromInterstitial");
}



#pragma mark - VGARewardedVideoAdDelegate methods

- (void)rewardedVideoAd:(VGARewardedVideoAd *)rewardedVideoAd didRewardUserWithReward:(VGAReward *)reward {
    NSLog(@"didRewardUserWithReward:{type:%@, amount:%@}", reward.type, reward.amount);
}

- (void)rewardedVideoAdDidLoad:(VGARewardedVideoAd*)rewardedVideoAd
                 withAdNetwork:(VGAAdNetwork *)adNetwork {
    NSLog(@"rewardedVideoAdDidLoad, ad network:%@", adNetwork.name);
    [self updateButtonState:self.playButton2 enabled:YES];
}

- (void)rewardedVideoAd:(VGARewardedVideoAd*)rewardedVideoAd
 didFailToLoadWithError:(NSError*)error withAdNetwork:(VGAAdNetwork *)adNetwork {
    NSLog(@"rewardedVideoAd:didFailToLoadWithError:%@, ad network:%@", error, adNetwork.name);
}

- (void)rewardedVideoAdWillPresent:(VGARewardedVideoAd*)rewardedVideoAd {
    NSLog(@"rewardedVideoAdWillPresent");
}

- (void)rewardedVideoAdDidPresent:(VGARewardedVideoAd*)rewardedVideoAd {
    NSLog(@"rewardedVideoAdDidPresent");
}

- (void)rewardedVideoAd:(VGARewardedVideoAd*)rewardedVideoAd didFailToPresentWithError:(NSError*)error {
    NSLog(@"rewardedVideoAd:didFailToPresentWithError:%@", error);
}

- (void)rewardedVideoAdWillDismiss:(VGARewardedVideoAd*)rewardedVideoAd {
    NSLog(@"rewardedVideoAdWillDismiss");
}

- (void)rewardedVideoAdDidDismiss:(VGARewardedVideoAd*)rewardedVideoAd {
    NSLog(@"rewardedVideoAdDidDismiss");
    [self updateButtonState:self.loadButton2 enabled:YES];
    [self updateButtonState:self.playButton2 enabled:NO];
}

- (void)rewardedVideoAdDidGetClick:(VGARewardedVideoAd*)rewardedVideoAd {
    NSLog(@"rewardedVideoAdDidGetClick");
}

- (void)userWillLeaveApplicationFromRewardedVideoAd:(VGARewardedVideoAd*)rewardedVideoAd {
    NSLog(@"userWillLeaveApplicationFromRewardedVideoAd");
}




@end
