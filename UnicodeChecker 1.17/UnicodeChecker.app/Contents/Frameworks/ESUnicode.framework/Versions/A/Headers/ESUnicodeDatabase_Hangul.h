//
//  ESUnicodeDatabase_Hangul.h
//  ESUnicode
//
//  Created by Steffen Kamp on Sat Mar 16 2002.
//  Copyright (c) 2001 earthlingsoft. All rights reserved.
//

#import "ESUnicodeDatabase.h"


@interface ESUnicodeDatabase (Hangul)

- (NSArray *)decomposeHangul:(UTF32Char)s;
- (NSArray *)composeHangul:(NSArray *)source;
- (NSArray *)composeHangul:(NSArray *)source replacementCount:(out NSInteger *)replacementCount;
- (NSString *)getHangulName:(UTF32Char)s;
- (BOOL)codepointIsHangul:(UTF32Char)code;

@end
