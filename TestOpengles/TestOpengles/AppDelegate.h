//
//  AppDelegate.h
//  TestOpengles
//
//  Created by 张洪星 on 15/11/10.
//  Copyright © 2015年 张洪星. All rights reserved.
//

//#import <UIKit/UIKit.h>
#import "GLView.h"
#import "ViewController.h"


@interface AppDelegate : NSObject <UIApplicationDelegate>
{
@private
    UIWindow    *   m_window;
    GLView  *   m_view;
    ViewController  *   m_viewController;
    
}
@property (strong, nonatomic) UIWindow *window;
@property (nonatomic,retain) GLView  *   m_view;
@property (nonatomic,retain) ViewController  *   m_viewController;

@end

