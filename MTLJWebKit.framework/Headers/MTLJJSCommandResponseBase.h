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
 调用JS方法基类，每个指定的调用都需继承于此类
 */
@interface MTLJJSCommandResponseBase : NSObject
@property (nonatomic, strong) NSString *scheme;
@property (nonatomic, strong) NSDictionary *argument;
- (void)executeResponse:(MTLJWebViewController *)webViewController responseData:(id)responseData;

@end
