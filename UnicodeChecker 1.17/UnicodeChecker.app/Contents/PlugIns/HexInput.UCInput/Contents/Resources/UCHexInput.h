//
//  UCHexInput.h
//  UnicodeChecker
//
//  Created by Steffen Kamp on 20.04.05.
//  Copyright 2005 earthlingsoft. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "UCInput.h"

@class UCHexCodepointFormatter;

@interface UCHexInput : NSObject <UCInput> {
    UCHexCodepointFormatter *_formatter;
}

@end
