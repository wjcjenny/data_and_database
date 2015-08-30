//
//  ESUnicodeDatabase_IDNA.h
//  UnicodeChecker
//
//  Created by Steffen Kamp on 04.08.09.
//  Copyright 2009 earthlingsoft. All rights reserved.
//

#import "ESUnicodeDatabase.h"

ESUNICODE_EXPORT NSString *IDNA2008DerivedProperty_PVALID;
ESUNICODE_EXPORT NSString *IDNA2008DerivedProperty_CONTEXTJ;
ESUNICODE_EXPORT NSString *IDNA2008DerivedProperty_CONTEXTO;
ESUNICODE_EXPORT NSString *IDNA2008DerivedProperty_DISALLOWED;
ESUNICODE_EXPORT NSString *IDNA2008DerivedProperty_UNASSIGNED;

ESUNICODE_EXPORT NSString *ESUnicodeACELabel;


typedef enum {
   IDNA2003 = 0,
   IDNA2008 = 1
} ESUnicodeIDNAType;


@interface ESUnicodeDatabase (IDNA)

- (NSString *)IDNA:(ESUnicodeIDNAType)type ToASCII:(NSString *)inStr;
- (NSString *)IDNA:(ESUnicodeIDNAType)type ToASCII:(NSString *)inStr error:(NSString **)error;

- (NSString *)IDNA:(ESUnicodeIDNAType)type ToUnicode:(NSString *)inStr;
- (NSString *)IDNA:(ESUnicodeIDNAType)type ToUnicode:(NSString *)inStr error:(NSString **)error;

// IDNA 2003 returns the unassigned codepoints in the input string. In order to obtain those, use the following two
// methods. IDNA 2008 does not do this, so the more general methods above can be used.
- (NSString *)IDNA2003ToASCII:(NSString *)inStr containsUnassignedCodepoints:(BOOL *)unassigned error:(NSString **)error;
- (NSString *)IDNA2003ToUnicode:(NSString *)inStr containsUnassignedCodepoints:(BOOL *)unassigned error:(NSString **)error;

// The following methods can be used to investigate the results of individual IDNA 2008 tests. They are all used as part
// of the regular IDNA:ToASCII: methods when requesting IDNA 2008 conversion.
- (NSArray *)IDNA2008CategoriesForCodepoint:(UTF32Char)codepoint;
- (NSString *)IDNA2008DerivedPropertyForCodepoint:(UTF32Char)codepoint;
- (BOOL)IDNA2008BidiTestForDomainName:(NSString *)inString error:(NSString **)error;
- (BOOL)IDNA2008BidiTestForLabel:(NSString *)inString error:(NSString **)error;
- (BOOL)IDNA2008ContextRuleTestForCodepointAtPosition:(unsigned)position inLabel:(NSString *)label isLookup:(BOOL)isLookup error:(NSString **)error;

@end

@interface NSString (ESUnicode_IDNA)
- (NSString *)punycodeEncodedStringWithError:(NSString **)error;
- (NSString *)punycodeDecodedStringWithError:(NSString **)error;

- (BOOL)containsRTLCharacter;
@end
