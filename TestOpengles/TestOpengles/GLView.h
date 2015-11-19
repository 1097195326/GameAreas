//
//  GLView.h
//  TestOpengles
//
//  Created by oceantech02 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@interface GLView : UIView
{
@private
    EAGLContext * m_context;
    float   m_timeStamp;
    
}
- (void) drawView:(CADisplayLink *) displayLink;

@end
