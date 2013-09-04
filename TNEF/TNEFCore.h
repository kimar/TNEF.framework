//
//  TNEF.h
//  TNEF
//
//  Created by Marcus Kida on 04.09.13.
//  Copyright (c) 2013 Marcus Kida. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TNEFCore : NSObject

+ (BOOL) extractWinmailDatFromPathWithURL:(NSURL *)fromUrl toPathAtURL:(NSURL *)toUrl;

@end
