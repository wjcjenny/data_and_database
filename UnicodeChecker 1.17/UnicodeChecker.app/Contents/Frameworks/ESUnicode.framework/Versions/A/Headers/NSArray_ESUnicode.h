//
//  NSArray_ESUnicode.h
//  UnicodeChecker
//
//  Created by Steffen Kamp on 20.05.06.
//  Copyright 2006 earthlingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSArray (ESUnicode)

- (BOOL)containsUnicodePropertyString:(NSString *)string;

@end
