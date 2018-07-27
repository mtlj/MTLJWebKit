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
 处理JS请求的基类，每个指定的Command都应该继承于此类
 */
@interface MTLJJSCommandHandlerBase : NSObject
@property (nonatomic, strong) NSString *scheme; // 协议Scheme，按约定赋值
@property (nonatomic, strong, readonly) NSDictionary *argument;   // JS请求带来的参数，可直接使用


/**
 执行JSCommand，每个子类根据具体情况进行重写

 @param webViewController webViewController
 @param responseHandler 响应块，responseData一般为NSDictionary类型
 @return YES/NO
 */
- (BOOL)executeCommand:(MTLJWebViewController *)webViewController responseHandler:(void(^)(id responseData))responseHandler;

@end
