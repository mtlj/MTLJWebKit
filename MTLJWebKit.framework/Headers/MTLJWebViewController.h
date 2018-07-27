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
 注册JSCommandHandler，用于js调用原生做事情

 @param commandHandler 继承自JSCommandHandleBase的具体js命令
 */
- (void)registerJSCommandHandler:(MTLJJSCommandHandlerBase *)commandHandler;

/**
 删除JSCommandHandler

 @param commandHandler 继承自JSCommandHandleBase的具体js命令
 */
- (void)removeJSCommandHandler:(MTLJJSCommandHandlerBase *)commandHandler;

- (void)callJSCommandHandler:(MTLJJSCommandResponseBase *)commandHandler;
@end
