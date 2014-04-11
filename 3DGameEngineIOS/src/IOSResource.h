//
//  IOSResource.h
//  3DGameEngineIOS
//
//  Created by Mark on 10/04/2014.
//  Copyright (c) 2014 bennybox&marko5049. All rights reserved.
//

#include <string>
#ifdef __OBJC__
#import <GLKit/GLKit.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
GLKTextureInfo* loadTexture(const std::string& fileName);
#endif

std::string getPath(void);