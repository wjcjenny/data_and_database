//
//  ESUnicodeArabicShaping.h
//  ESUnicode
//
//  Created by Steffen Kamp on Mon Mar 25 2002.
//  Copyright (c) 2001 earthlingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ESUnicodeArabicShaping : NSObject {
    NSNumber *codeValue;
    NSString *schematicName;
    NSString *joiningType;
    NSString *joiningGroup;
}

+ (id)arabicShapingWithString:(NSString *)string;
- (id)initWithString:(NSString *)string;

- (NSNumber *)codeValue;
- (NSString *)schematicName;
- (NSString *)joiningType;
- (NSString *)joiningGroup;

@end
