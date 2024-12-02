import type {TurboModule} from 'react-native/Libraries/TurboModule/RCTExport';
import {TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
    enableDevMode():void;

    initWithPlainTextAccessKey(accessKey: string, secretKey: string, endPoint: string, configuration: Object): void;

    initWithSecurityToken(securityToken: string, accessKey: string, secretKey: string, endPoint: string, configuration: Object): void;

    upload(bucketName: string, objectKey: string, filepath: string, options: Object): Promise<Object>;
}

export default TurboModuleRegistry.get<Spec>(
  'RTNObs',
) as Spec | null;