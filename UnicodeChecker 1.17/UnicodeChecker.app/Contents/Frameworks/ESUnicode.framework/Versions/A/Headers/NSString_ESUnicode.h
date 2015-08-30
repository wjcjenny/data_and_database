//
//  NSString_ESUnicode.h
//  ESUnicode
//
//  Created by Steffen Kamp on Mon Feb 25 2002.
//  Copyright (c) 2002 earthlingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESUnicode_Defines.h"

ESUNICODE_EXPORT NSString * const ESURLStringEscapingMethod; // CFURLCreateStringByAddingPercentEscapes() is more powerful for escaping URLs
ESUNICODE_EXPORT NSString * const ESC99StringEscapingMethod;
ESUNICODE_EXPORT NSString * const ESCOctStringEscapingMethod;
ESUNICODE_EXPORT NSString * const ESCSS1StringEscapingMethod;
ESUNICODE_EXPORT NSString * const ESCSS2StringEscapingMethod;
ESUNICODE_EXPORT NSString * const ESCSS2_1StringEscapingMethod;
ESUNICODE_EXPORT NSString * const ESJavaStringEscapingMethod;

@interface NSString (ESUnicode)

+ (NSString *)stringWithCodepoint:(UTF32Char)code;

+ (NSString *)UTF8RepresentationOfCodepoint:(UTF32Char)code numberSystem:(int)base withPrefix:(BOOL)withPrefix;

+ (NSString *)stringWithContentsOfUTF8File:(NSString *)path;

- (NSString *)UTF8RepresentationAtIndex:(int)index; // hexadecimal with 0x prefix
- (NSString *)UTF8RepresentationAtIndex:(int)index numberSystem:(int)base; // base must be either 8 or 16, with 0x prefix for whole string (base 16) or \ prefixes for each byte (base 8)
- (NSString *)UTF8RepresentationAtIndex:(int)index numberSystem:(int)base withPrefix:(BOOL)withPrefix;
- (NSString *)UTF16RepresentationAtIndex:(int)index; // returns string of the form @"0xnnnn" or @"0xnnnnmmmm"

- (NSArray *)codepoints; // returns an array of NSString

- (NSString *)hexCodepointsJoinedBySpaces; // invokes -hexCodepointsJoinedBySpacesWithMaximumLength: with 0 as argument
- (NSString *)hexCodepointsJoinedBySpacesWithMaximumLength:(int)maxlen; // unlimited length for maxlen==0
- (NSArray *)hexCodepointsArrayWithMaximumLength:(int)maxlen; // unlimited length for maxlen==0

- (int)UTF32Length;
- (UTF32Char)codepointAtIndex:(int)index; // index is codepoint index (i.e. surrogate pairs consume 1 index slot)
- (UTF32Char)codepointAtIndex:(int)index fromCharacterOffset:(int)offset nextCodepointCharacterOffset:(int *)nextCharOffset;
- (UTF32Char)codepointAtUnicharIndex:(int)index higherPlanes:(BOOL)high; // index is unichar index (default for NSString). if unichar at index is high surrogate and index+1 is low surrogate they will be combined to the scalar unicode value

- (NSString *)trimmedString; // returns string with leading and trailing characters from set [NSCharacterSet whitespaceAndNewlineCharacterSet] removed. if NSString responds to -stringByTrimmingCharactersInSet: (OSX >= 10.2) that method will be invoked
- (NSString *)stringWithoutLeadingCharactersFromSet:(NSCharacterSet *)charset;
- (NSString *)stringWithoutTrailingCharactersFromSet:(NSCharacterSet *)charset;

- (NSString *)stringByInsertingString:(NSString *)insertString atCodepointIndex:(int)index;
- (NSString *)stringByRemovingCodepointsAtIndexes:(NSIndexSet *)indexes;
- (NSString *)stringByReplacingCodepointAtIndex:(int)index withString:(NSString *)replaceString;

- (NSArray *)componentsSeparatedByCodepoint:(UTF32Char)codepoint; // while this method is currently not optimized for speed, it returns correct results when splitting the string @"a.\u0308b" at U+002e (FULL STOP ".") compared to -componentsSeparatedByString:

+ (NSString *)escapingMethodForOSType:(OSType)type;
+ (NSCharacterSet *)preserveSetForStringEscapingMethod:(NSString *)escapingMethod;

- (NSString *)stringByAddingEscapes:(NSString *)escapingMethod;
- (NSString *)stringByAddingEscapes:(NSString *)escapingMethod preservingCharactersFromSet:(NSCharacterSet *)preserveSet preservingDefaultSet:(BOOL)preserveDefault countingReplacements:(int *)count;

- (NSString *)stringByReplacingEscapes:(NSString *)escapingMethod;
- (NSString *)stringByReplacingEscapes:(NSString *)escapingMethod countingReplacements:(int *)count; // when using ESURLStringEscapingMethod, count will be set to -1

- (NSString *)matchableUnicodePropertyString;
- (BOOL)isEqualToUnicodePropertyString:(NSString *)string;

@end
