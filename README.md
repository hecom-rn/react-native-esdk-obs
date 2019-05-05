# 华为 OBS SDK for React Native

## 简介

本文档主要介绍OBS React Native SDK的安装和使用。本文档假设您已经开通了华为云OBS 服务，并创建了Access Key ID 和Access Key Secret。文中的ID 指的是Access Key ID，KEY 指的是Access Key Secret。如果您还没有开通或者还不了解OBS，请登录[OBS产品主页](https://support.huaweicloud.com/obs/index.html)获取更多的帮助。

## 安装

* yarn

```script
yarn install https://github.com/summer88123/react-native-esdk-obs.git
```

### 手动安装

#### iOS

- **CocoaPods**
```
pod 'react-native-esdk-obs', :path => '../node_modules/react-native-esdk-obs'
````

- **非CocoaPods**

1. 在XCode  Project navigator面板中, 右键单击工程Libraries文件 ➜ 选择`Add Files to <...>` 进入 `node_modules` ➜ `react-native-esdk-obs` ➜ `ios` ➜ select `RNAliyunOSS.xcodeproj`
2. 在XCode  Project navigator面板中, 添加`RNAliyunOSS.a` to `Build Phases -> Link Binary With Libraries`
3. 在XCode  Project navigator面板中，右键单击[framework] ➜ Add Files to [your project's name]. 进入node_modules ➜ aliyun-oss-rn-sdk ➜ AliyunSDK. Add AliyunOSSiOS.framework

#### Android
1. `settings.gradle`
    ```gradle
    include ':react-native-esdk-obs'
    project(':react-native-esdk-obs').projectDir = new File(rootProject.projectDir, '../node_modules/react-native-esdk-obs/android')
    ```
2. `build.gradle`
    ```gradle
    dependencies {
        implementation project(':react-native-esdk-obs')
    }
    ```

3. `MainApplication.java`
    ```java
   import com.hecom.obs.RNObsPackage;

    public class MainApplication extends Application implements ReactApplication {
     @Override
       protected List<ReactPackage> getPackages() {
         return Arrays.<ReactPackage>asList(
             new MainReactPackage(),
               new ImagePickerPackage(),
               new RNObsPackage()
         );
       }
    }
    ```

## License

* MIT