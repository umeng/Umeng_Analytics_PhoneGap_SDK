//
//  UMPlugin.h
//
//  Created by wangkai on 16-04-14.
//
//

#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>


@interface UMPlugin : CDVPlugin

- (void)getDeviceId:(CDVInvokedUrlCommand*)command;

- (void)onCCEvent:(CDVInvokedUrlCommand*)command;
- (void)onEvent:(CDVInvokedUrlCommand*)command;
- (void)onEventWithLabel:(CDVInvokedUrlCommand*)command;
- (void)onEventWithParameters:(CDVInvokedUrlCommand*)command;
- (void)onEventWithCounter:(CDVInvokedUrlCommand*)command;
- (void)onPageBegin:(CDVInvokedUrlCommand*)command;
- (void)onPageEnd:(CDVInvokedUrlCommand*)command;
- (void)setLogEnabled:(CDVInvokedUrlCommand*)command;
- (void)profileSignInWithPUID:(CDVInvokedUrlCommand*)command;
- (void)profileSignInWithPUIDWithProvider:(CDVInvokedUrlCommand*)command;
- (void)profileSignOff:(NSArray *)arguments;

//游戏统计

- (void)setUserLevelId:(CDVInvokedUrlCommand*)command;
- (void)startLevel:(CDVInvokedUrlCommand*)command;
- (void)finishLevel:(CDVInvokedUrlCommand*)command;
- (void)failLevel:(CDVInvokedUrlCommand*)command;
- (void)exchange:(CDVInvokedUrlCommand*)command;
- (void)pay:(CDVInvokedUrlCommand*)command ;
- (void)payWithItem:(CDVInvokedUrlCommand*)command;- (void)buy:(CDVInvokedUrlCommand*)command;
- (void)use:(CDVInvokedUrlCommand*)command;
- (void)bonus:(CDVInvokedUrlCommand*)command;
- (void)bonusWithItem:(CDVInvokedUrlCommand*)command;


@end
