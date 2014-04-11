//
//  IOSResource.mm
//  3DGameEngineIOS
//
//  Created by Mark on 10/04/2014.
//  Copyright (c) 2014 bennybox&marko5049. All rights reserved.
//

#include "IOSResource.h"

std::string getPath(void) {
    NSString* path = [[NSBundle mainBundle] resourcePath];
    return (std::string([path UTF8String] + std::string("/")));
}

FILE *IOSfopen(char const *file, char const *mode) {
    NSArray *dirs = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *dir = [dirs objectAtIndex:0];
    
    NSString *fileName = [NSString stringWithCString:file encoding:NSASCIIStringEncoding];
    NSString *path = [dir stringByAppendingPathComponent:fileName];
    const char *fileDir = [path cStringUsingEncoding:NSASCIIStringEncoding];
    FILE* res = fopen(fileDir, mode);
    return res;
}

GLKTextureInfo* loadTexture(const std::string& fileName) {
    NSString *file = [NSString stringWithCString:fileName.c_str() encoding:[NSString defaultCStringEncoding]];
    CGImageRef textRef = [[UIImage imageNamed:file] CGImage];
    GLKTextureInfo *textInfo = [GLKTextureLoader textureWithCGImage:textRef options:nil error:NULL];
    return textInfo;
}