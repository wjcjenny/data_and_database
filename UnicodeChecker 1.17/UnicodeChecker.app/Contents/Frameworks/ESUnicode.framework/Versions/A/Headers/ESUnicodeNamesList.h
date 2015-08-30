//
//  ESUnicodeNamesList.h
//  UnicodeChecker
//
//  Created by Steffen Kamp on 02.09.06.
//  Copyright 2006 earthlingsoft. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface ESUnicodeNamesList_CharEntry : NSObject {
  UTF32Char _codepoint;
  NSMutableArray *_aliases;
  NSMutableArray *_formalAliases;
  NSMutableArray *_comments;
  NSMutableArray *_crossRefs;
  NSMutableArray *_decompositions;
  NSMutableArray *_compatMappings;
  NSMutableArray *_notices;
}

+ (NSMutableArray *)readNamesListAtPath:(NSString *)path;

+ (id)charEntryWithScanner:(NSScanner *)scanner;
- (id)initWithScanner:(NSScanner *)scanner;

- (UTF32Char)codepoint;
- (NSArray *)aliases;
- (NSArray *)formalAliases;
- (NSArray *)comments;
- (NSArray *)crossRefs;
- (NSArray *)decompositions;
- (NSArray *)compatMappings;
- (NSArray *)notices;

- (NSString *)allLinesString;

@end
