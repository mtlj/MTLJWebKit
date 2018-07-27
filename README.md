# MTLJWebKit
A set of Objective-C and Javascript interaction solutions based on WKWebView, supporting iOS 9.0

Installation (iOS)
------------------------

### Installation with CocoaPods
Add this to your [podfile](https://guides.cocoapods.org/using/getting-started.html) and run `pod install` to install:

```ruby
pod 'MTLJWebKit', '~> 1.0.2'
```

Usage
-----
1) Import the header file
```objc
#import <MTLJWebKit/MTLJWebKit.h>
```

2) Instantiate MTLJWebViewController and set originURL property

```objc
MTLJWebViewController *webViewVC = [[MTLJWebViewController alloc] init];
webViewVC.originURL = xxxURL;
```

3) Extends MTLJJSCommandHandlerBase class，override executeCommand:responseHandler: method and set scheme property，Register a JSCommandHandler in ObjC

```objc
[webViewVC registerJSCommandHandler:[MTLJJSCommandHandlerBaseSubClass new]];
```

4) Extends MTLJJSCommandResponseBase class，override executeResponse:responseData: method and set scheme、argument property，Call a JSCommandHandler in ObjC

```objc
[webViewVC callJSCommandHandler:[MTLJJSCommandResponseBaseSubClass new]];
```

4) Copy and paste `setupMTLJWebViewJavascriptBridge` into your JS:

```javascript
function setupMTLJWebViewJavascriptBridge(callback) {
    if (window.MTLJWebViewJavascriptBridge) { return callback(MTLJWebViewJavascriptBridge); }
    if (window.WVJBCallbacks) { return window.WVJBCallbacks.push(callback); }
    window.WVJBCallbacks = [callback];
    var WVJBIframe = document.createElement('iframe');
    WVJBIframe.style.display = 'none';
    WVJBIframe.src = 'mtljcommand://__bridge_loaded__';
    document.documentElement.appendChild(WVJBIframe);
    setTimeout(function() { document.documentElement.removeChild(WVJBIframe) }, 0)
}
```

5) Finally, call `setupMTLJWebViewJavascriptBridge` and then use the bridge to register handlers and call ObjC handlers:

```javascript
setupMTLJWebViewJavascriptBridge(function(bridge) {
    
    /* Initialize your app here */
    bridge.registerHandler('mtljcommand://fetchFansInfo', function(data, responseCallback) {
    	log('ObjC called parameter with', data)
	var responseData = { 'Javascript Says info':'lilei' }
	log('JS responding parameter with', responseData)
	responseCallback(responseData)
    })
	
    bridge.callHandler('mtljcommand://fetchPhoneInfo', {'platform': 'ios'}, function(response) {
	log('JS got response', response)
    })
})
```
