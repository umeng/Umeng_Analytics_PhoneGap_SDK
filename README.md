# Umeng PhoneGap SDK 集成文档

## 概述
  Umeng PhoneGap SDK 适用于Cordova和PhoneGap跨平台项目。
  统计所有指标，均和标准移动统计完全相同。

## 集成文档

### 下载

   在官方地址下载最新版本的统计SDK. 下载链接:[友盟+统计分析 Android SDK](http://dev.umeng.com/analytics/android-doc/sdk-download)、[友盟+统计分析 IOS SDK](http://dev.umeng.com/analytics/ios-doc/sdk-download)


### 导入SDK
    - 请将`umeng_plugin/src/`中的sdk替换成下载的即可
    - 默认使用的是idfa版本sdk，如需要使用非idfa版本的sdk请去官网下载即可
### 基本功能集成


* 新建工程步骤

    - 创建工程 
    
       ```
       cordova create hello
       ```
    - 增加工程支持平台
    
       ``` 
       //ios工程: 
       cordova platforms add ios
       //android工程:
       cordova platforms add android
       ```
    
    - 使用友盟统计SDK
    
      ```
      cordova plugins add [Plugin 路径]
      ```
    - 注意
      如果替换最新SDK 需要修改plugin.xml中的对应文件名字信息. 如果找不到`UMMobClick.framework`里的文件，请将sdk内的`UMMobClick.framework`手工导入工程中

* 友盟初始化
     - IOS

        需要加入代码引用

        ```
        #import <UMMobClick/MobClick.h>
        ```

       在 `%Cordova工程目录%\/platforms/ios/demo/Classes/AppDelegate.m` 文件中，找到方法 `(BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions`，添加下面的代码：

       ```
       UMConfigInstance.appKey = @"Your Appkey";
       UMConfigInstance.channelId = @"Your ChannelId";"

       UMConfigInstance.eSType=E_UM_GAME;//友盟游戏统计，如不设置默认为应用统计

       [MobClick startWithConfigure:UMConfigInstance];
      ```

      `[Your Appkey]` 就是刚刚申请的 Appkey，`[Your ChannelId]` 是应用的渠道号。        
    - android
      
      配置appkey和channel见文档底部
      
      在主界面集成友盟初始化
      
       ```
        /**
         * onCreate中调用
         */
        private void initUmengSDK() {
            MobclickAgent.setScenarioType(this, EScenarioType.E_UM_NORMAL);
            MobclickAgent.setDebugMode(true);
            MobclickAgent.openActivityDurationTrack(false);
            // MobclickAgent.setSessionContinueMillis(1000);
        }
    
        @Override
        protected void onResume() {
            super.onResume();
            MobclickAgent.onResume(this);
        }
    
        @Override
        protected void onPause() {
            super.onPause();
            MobclickAgent.onPause(this);
        }
       ```
    
    - 问题
    
      1.检查<meta http-equiv="Content-Security-Policy" content="script-src 'self' 'unsafe-inline'; default-src 'self' data: gap: https://ssl.gstatic.com 'unsafe-eval'; style-src 'self' 'unsafe-inline'; media-src *">
是否有script-src 'self' 'unsafe-inline';

      2.如果找不到`UMMobClick.framework`里的文件，请将sdk内的`UMMobClick.framework`手工导入工程中


* 统计方法使用
    
- JavaScript方法介绍

    *  MobclickAgent.getDeviceId(deviceId) 获取Android IMEI
    *  MobclickAgent.onEvent(eventId)  自定义事件
    *  MobclickAgent.onCCEvent(evenArray, evenValue, eventLabel) 结构化自定义事件
    *  MobclickAgent.onEventWithLabel(eventId, eventLabel) 自定义事件
    *  MobclickAgent.onEventWithParameters(eventId, eventData) 自定义事件
    *  MobclickAgent.onEventWithCounter(eventId, eventData, eventNum) 自定义事件
    *  MobclickAgent.onPageBegin(pageName) 页面开始的时候调用此方法
    *  MobclickAgent.onPageEnd(pageName) 页面结束的时候调用此方法
    *  MobclickAgent.profileSignInWithPUID(puid) 统计帐号登录接口
    *  MobclickAgent.profileSignInWithPUIDWithProvider(puid, provider)  统计帐号登录接口
    *  MobclickAgent.profileSignOff()      帐号统计退出接口
    *  MobclickAgent.setUserLevelId(level) 当玩家建立角色或者升级时,需调用此接口
    *  MobclickAgent.startLevel(level) 在游戏开启新的关卡的时候调用
    *  MobclickAgent.finishLevel(level) 关卡结束时候调用
    *  MobclickAgent.failLevel(level) 关卡失败时候调用
    *  MobclickAgent.exchange(orderId, currencyAmount, currencyType, virtualAmount, channel) 真实消费统计
    *  MobclickAgent.pay(cash, source, coin) 真实消费统计
    *  MobclickAgent.payWithItem(cash, source, item, amount, price) 真实消费统计
    *  MobclickAgent.buy(item, amount, price)  虚拟消费统计
    *  MobclickAgent.use(item, amount, price)  物品消耗统计
    *  MobclickAgent.bonusWithItem(item, amount, price, source) 额外奖励
    *  MobclickAgent.(coin, source) 额外奖励
    *  MobclickAgent.setLogEnabled(enabled) log是否进入调试模式
  
###android配置appkey和channel
* 配置manifest和appkey
    
    - 修改`plugin.xml`文件：
        * 统计集成如果使用jar包方式则修改包含`umeng-analytics-vX.X.X.jar`行最新的jar名字,如果使用gradle方式集成SDK,则删除包含`umeng-analytics-vX.X.X.jar`行的脚本
        * UMENG_APPKEY 的value修改为友盟官方申请的appkey
        * UMENG_CHANNEL 的value修改为渠道
    
    - 如果不在manifest里配置友盟的appkey,可以在html代码的body 的onload()时候调用此接口：`MobclickAgent.init("appkey", "channel");`



