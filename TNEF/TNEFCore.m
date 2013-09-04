//
//  TNEF.m
//  TNEF
//
//  Created by Marcus Kida on 04.09.13.
//  Copyright (c) 2013 Marcus Kida. All rights reserved.
//

#import "TNEFCore.h"
#include "options.h"
#include "tnef.h"

@implementation TNEFCore

+ (BOOL) extractWinmailDatFromPathWithURL:(NSURL *)fromUrl toPathAtURL:(NSURL *)toUrl
{
    // Create destiantion dir (if not exists)
    if(![[NSFileManager defaultManager] fileExistsAtPath:[toUrl path]])
    {
        [[NSFileManager defaultManager] createDirectoryAtURL:toUrl withIntermediateDirectories:YES attributes:nil error:nil];
    }
    
    // Make a copy of the string, cause parse_file wants a 'char *', not 'const char *'
    const char *toDirC = [[toUrl path] cStringUsingEncoding:NSUTF8StringEncoding];
    size_t tempDirLen = strlen(toDirC);
    char *out_dir = malloc(tempDirLen + 1);
    strlcpy(out_dir, toDirC, tempDirLen + 1);
    
    // Make a copy of the body file name
    const char *bodyC = [[NSString stringWithFormat:@"MailBody"] cStringUsingEncoding:NSUTF8StringEncoding];
    size_t bodyLen = strlen(bodyC);
    char *body = malloc(bodyLen + 1);
    strlcpy(body, bodyC, bodyLen + 1);
    
    int flags = SAVEBODY;
    
    NSAssert((fromUrl && [fromUrl isFileURL]), @"fromUrl must be a valid file URL!");
    NSAssert((toUrl && [toUrl isFileURL]), @"toUrl must be a valid file URL!");

    FILE *fp = fopen([[fromUrl path] cStringUsingEncoding:NSUTF8StringEncoding], "rb");

    // Now unpack the TNEF file
    int ret = parse_file (fp,
                          out_dir,
                          body,
                          "all",
                          flags);
    free(out_dir);
    free(body);
    return (ret == 0)?YES:NO;
}

@end
