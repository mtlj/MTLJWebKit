//
//  MTLJWebViewController.h
//  MTVoiceLiveSDK
//
//  Created by jie liang on 2018/7/17.
//  Copyright © 2018年 Meitu.com. All rights reserved.
//

#import <UIKit/UIKit.h>
@class MTLJJSCommandHandlerBase;
@class MTLJJSCommandResponseBase;

@interface MTLJWebViewController : UIViewController
@property (nonatomic, readonly) NSURL *currentURL;
@property (nonatomic, copy) NSURL *originURL;
@property (nonatomic, strong) NSDictionary *requestHeader;

/**
 注册JSCommandHandler，用于处理JS发来的请求

 @param commandHandler JS请求的处理类（继承自JSCommandHandleBase）
 */
- (void)registerJSCommandHandler:(MTLJJSCommandHandlerBase *)commandHandler;

/**
 删除JSCommandHandler

 @param commandHandler 继承自JSCommandHandleBase的具体JS请求
 */
- (void)removeJSCommandHandler:(MTLJJSCommandHandlerBase *)commandHandler;

/**
 调用JS

 @param commandHandler JS的响应处理类（继承自MTLJJSCommandResponseBase）
 */
- (void)callJSCommandHandler:(MTLJJSCommandResponseBase *)commandHandler;
@end
