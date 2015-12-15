//
//  AppDelegate.m
//  TestOpengles
//
//  Created by 张洪星 on 15/11/10.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#import "AppDelegate.h"
#include <OpenGLES/ES3/glext.h>

//@interface AppDelegate ()
//
//@end

@implementation AppDelegate

@synthesize window = m_window;
@synthesize m_view;
@synthesize m_viewController;


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    CGRect screenBounds = [[UIScreen mainScreen] bounds];
    
    m_window = [[UIWindow alloc]initWithFrame:screenBounds];
    
    
    m_viewController = [[ViewController alloc]initWithNibName:nil bundle:nil];
    
    [m_window setRootViewController:m_viewController];
    [m_window makeKeyAndVisible];
    
    m_view   = [[GLView alloc]initWithFrame:screenBounds];
    [m_viewController setView:m_view];

    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}
- (void)dealloc
{
//    [m_window dealloc];
//    [m_view dealloc];
    
}
@end
