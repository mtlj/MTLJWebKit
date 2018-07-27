//
//  MTLJJSCommandHandlerBase.h
//  MTVoiceLiveSDK
//
//  Created by jie liang on 2018/7/18.
//  Copyright © 2018年 Meitu.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class MTLJWebViewController;

/**
 处理JS指令基类，每个指定的Command都应该继承于此类
 */
@interface MTLJJSCommandHandlerBase : NSObject
@property (nonatomic, strong) NSString *scheme;
@property (nonatomic, strong) NSDictionary *argument;


/**
 执行JSCommand，每个子类根据具体情况进行重写

 @param webViewController webViewController
 @param responseHandler 响应块
 @return YES/NO
 */
- (BOOL)executeCommand:(MTLJWebViewController *)webViewController responseHandler:(void(^)(id responseData))responseHandler;

@end
