//
//  MTLJJSCommandResponseBase.h
//  MT
//
//  Created by jie liang on 2018/7/26.
//  Copyright © 2018年 Meitu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class MTLJWebViewController;

/**
 调用JS的基类，每个指定的调用都需继承于此类
 */
@interface MTLJJSCommandResponseBase : NSObject
@property (nonatomic, strong) NSString *scheme; // 协议Scheme，按约定赋值
@property (nonatomic, strong) NSDictionary *argument;   // 调用JS携带的参数

/**
 处理JS的响应

 @param webViewController webViewController 
 @param responseData responseData一般为NSDictionary类型
 */
- (void)executeResponse:(MTLJWebViewController *)webViewController responseData:(id)responseData;

@end
