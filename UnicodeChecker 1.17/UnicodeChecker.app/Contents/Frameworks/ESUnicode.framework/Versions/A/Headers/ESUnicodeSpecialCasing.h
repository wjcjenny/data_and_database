//
//  ESUnicodeSpecialCasing.h
//  ESUnicode
//
//  Created by Steffen Kamp on Mon Mar 25 2002.
//  Copyright (c) 2001 earthlingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ESUnicodeSpecialCasing : NSObject {
    NSNumber *codeValue;
    NSString *lowercaseMapping;
    NSMutableArray *lowercaseMappingArray;
    NSString *titlecaseMapping;
    NSMutableArray *uppercaseMappingArray;
    NSString *uppercaseMapping;
    NSMutableArray *titlecaseMappingArray;
    NSString *conditionList;
}

+ (id)specialCasingWithString:(NSString *)string;
- (id)initWithString:(NSString *)string;

- (NSNumber *)codeValue;
- (NSString *)lowercaseMapping;
- (NSArray *)lowercaseMappingArray;
- (NSString *)uppercaseMapping;
- (NSArray *)uppercaseMappingArray;
- (NSString *)titlecaseMapping;
- (NSArray *)titlecaseMappingArray;
- (NSString *)conditionList; // may return nil!
@end
