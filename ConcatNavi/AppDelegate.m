//
//  AppDelegate.m
//  ConcatNavi
//
//  Created by Benutzer on 30.04.20.
//  Copyright © 2020 Benutzer. All rights reserved.
//

#import "AppDelegate.h"
#import <Meridian/Meridian.h>


@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [NSThread sleepForTimeInterval:1.500];  //LaunchScreen wird fuer 1,5 Sekunden angezeigt.
    
    
    
    
    MRConfig *config = [MRConfig new];
    
    // If samples are to be run via Default/US servers, use these values
    [config domainConfig].domainRegion = MRDomainRegionDefault;
    config.applicationToken = @"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0IjoxNTg3NDY1MTc4LCJ2YWx1ZSI6ImIzNjMyZTYxNTY4YTI2OGU3Y2RiMTg0YTE0YjBmYmMwMWJmZWQwOTAifQ.LIxY6xfdZF5cqQU6hwYBKqG1CkaKA1i91IZbq6j4w3Y";
    
    
    [Meridian configure:config];
    [CLLocationManager locationServicesEnabled];
    
    
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


- (NSDictionary *) KampagneManager: (MRCampaignManager *) Manager userInfoForCampaign: (NSString *) KampagneIdentifier {
    return @ {@"custom_field_1": @"custom_data"};
};




@end
