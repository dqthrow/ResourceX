//
//  ResourceConfig.h
//  ResourceX
//
//  Created by dqdeng on 2020/4/3.
//  Copyright © 2020 Jaden. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ResourceConst.h"

NS_ASSUME_NONNULL_BEGIN
///服务器返回数据格式
//   {
//     "code": "0",
//     "result": {
//                "xx": 1,
//                "xx": "xx",
//                "xx": "xx"
//                },
//      "msg": "sucess!"
//    }
/// JT_REDUXDATCODE_SUCCES_STATE  -> "0"        对应返回success block 数据状态
/// JT_REDUXDAT_CODE              -> "code"
/// JT_REDUXDAT_MSG               -> "msg"
/// JT_REDUXDATA_KEY              -> "result"

extern NSString *JT_REDUXDATA_KEY; //The key of the data dictionary returned by the network request
extern NSString *JT_REDUXDAT_MSG; //The key of the request msg
extern NSString *JT_REDUXDAT_CODE; //The key of the request code
extern NSString *JT_REDUXDATCODE_SUCCES_STATE; //The key of the request code state
extern NSString *JT_BASEK_API_SERVER; // The key of the request baseApi

//如果服务器有加密返回数据的key
///extern NSString *JT_EnryptedResponse_Key;

typedef void(^NetWorkHitBlock)(id msg,NSInteger tag);
typedef id _Nullable (^ConfigerAFSessionManager)(void);
typedef NSDictionary* _Nullable (^SessionHeader)(NSString * _Nullable  url,id _Nullable parameters);

typedef id _Nullable (^ResponseDecryptor)(id _Nullable response);

@interface ResourceConfig : NSObject

@property (nonatomic,copy)NetWorkHitBlock netWorkErrorHit_block; //net return failure hit Block
@property (nonatomic,copy)NetWorkHitBlock netWorkSuccessHit_block; //net return success hit Block
@property (nonatomic,copy)ResponseDecryptor response_DE_block; //

@property (nonatomic,copy)SessionHeader param_EN_block; //数据请求加密

//@property (nonatomic,assign)BOOL setParamEncrypt; //设置请求参数加密 默认不设置
//@property (nonatomic,assign)BOOL setResponseDecode; //设置返回数据解密 默认不设置


@property (nonatomic,copy)dispatch_block_t finishedHidenHUD_block; //
@property (nonatomic,copy)dispatch_block_t startShowHUD_block; //

+ (instancetype)share;

+ (void)setReduxdata_Key:(NSString *)reduxdataKey;   /// key
+ (void)setReduxdata_Msg:(NSString *)reduxdataMsg;   /// msg
+ (void)setReduxdata_Code:(NSString *)reduxdataCode; /// code
+ (void)setBasek_Api_Server:(NSString *)baseApiServer;/// Api
+ (void)setReduxdatCode_succes_State:(NSString *)reduxdatCodesuccesState; /// State
///+ (void)setReduxdat_EnryptedResponse_Key:(NSString *)enryptedResponse_Key;
+ (void)configer_showErrorHit:(NetWorkHitBlock)hit;//错误提示HUD
+ (void)configer_showSuccessHit:(NetWorkHitBlock)hit;//错误提示HUD

/// 开始请求... 加载HUD  请求结束 隐藏HUD
+ (void)configer_showHUD_Begin:(dispatch_block_t)block; ///设置 请求开始 加载HUD
+ (void)configer_hideHUD_Finish:(dispatch_block_t)block;// 设置请求结束 隐藏HUD


///配置 AFHTTPSessionManager
+ (void)configerAFHTTPSessionManager:(ConfigerAFSessionManager)httpSssionManager;
+ (void)configerSessionHeader:(SessionHeader)headers;

///请求参数加密
+ (void)configer_RequestEncrypt:(SessionHeader)param_EN_block;
///服务器数据解密
+ (void)configer_ResponseDecode:(ResponseDecryptor)response_DE_block;

@end

NS_ASSUME_NONNULL_END
