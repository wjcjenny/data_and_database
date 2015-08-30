//
//  ESUnicodeData.h
//  UnicodeChecker
//
//  Created by Steffen Kamp on 19.05.06.
//  Copyright 2006 earthlingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum {
   ESUnicode_GraphicType,
   ESUnicode_FormatType,
   ESUnicode_ControlType,
   ESUnicode_PrivateUseType,
   ESUnicode_SurrogateType,
   ESUnicode_NoncharacterType,
   ESUnicode_ReservedType
} ESUnicode_CodepointType;

typedef enum {
   ESUnicode_NumericType_None,
   ESUnicode_NumericType_Decimal,
   ESUnicode_NumericType_Digit,
   ESUnicode_NumericType_Numeric
} ESUnicode_NumericType;

typedef enum {
   ESUnicode_LineBreakClass_BK,
   ESUnicode_LineBreakClass_CR,
   ESUnicode_LineBreakClass_LF,
   ESUnicode_LineBreakClass_CM,
   ESUnicode_LineBreakClass_NL,
   ESUnicode_LineBreakClass_SG,
   ESUnicode_LineBreakClass_WJ,
   ESUnicode_LineBreakClass_ZW,
   ESUnicode_LineBreakClass_GL,
   ESUnicode_LineBreakClass_SP,
   
   ESUnicode_LineBreakClass_B2,
   ESUnicode_LineBreakClass_BA,
   ESUnicode_LineBreakClass_BB,
   ESUnicode_LineBreakClass_HY,
   ESUnicode_LineBreakClass_CB,
   
   ESUnicode_LineBreakClass_CL,
   ESUnicode_LineBreakClass_CP,
   ESUnicode_LineBreakClass_EX,
   ESUnicode_LineBreakClass_IN,
   ESUnicode_LineBreakClass_NS,
   ESUnicode_LineBreakClass_OP,
   ESUnicode_LineBreakClass_QU,
   
   ESUnicode_LineBreakClass_IS,
   ESUnicode_LineBreakClass_NU,
   ESUnicode_LineBreakClass_PO,
   ESUnicode_LineBreakClass_PR,
   ESUnicode_LineBreakClass_SY,
   
   ESUnicode_LineBreakClass_AI,
   ESUnicode_LineBreakClass_AL,
   ESUnicode_LineBreakClass_CJ, // 6.1.0
   ESUnicode_LineBreakClass_H2,
   ESUnicode_LineBreakClass_H3,
   ESUnicode_LineBreakClass_HL, // 6.1.0
   ESUnicode_LineBreakClass_ID,
   ESUnicode_LineBreakClass_JL,
   ESUnicode_LineBreakClass_JV,
   ESUnicode_LineBreakClass_JT,
   ESUnicode_LineBreakClass_RI, // 6.2.0
   ESUnicode_LineBreakClass_SA,
   ESUnicode_LineBreakClass_XX
} ESUnicode_LineBreakClass;

ESUNICODE_EXPORT NSString *ESUnicode_StringForNumericType(ESUnicode_NumericType type);
ESUNICODE_EXPORT NSString *ESUnicode_StringForLineBreakClass(ESUnicode_LineBreakClass lineBreakClass);
ESUNICODE_EXPORT ESUnicode_LineBreakClass ESUnicode_LineBreakClassForString(NSString *lineBreakClassString);


@interface ESUnicodeData : NSObject {
   NSString *_cachedScript;
}

- (UTF32Char)codepoint;
- (NSNumber *)codeValue;
- (NSString *)characterName;
- (NSString *)generalCategory;
- (NSUInteger)canonicalCombiningClass;
- (NSString *)bidirectionalCategory;
- (NSString *)characterDecompositionMapping;
- (NSArray *)characterDecompositionMappingArray;
- (ESUnicode_NumericType)numericType;
- (NSNumber *)numericValue;
- (NSString *)numericValueString;
- (BOOL)mirrored;
- (NSString *)unicode1Name;
- (NSString *)commentField;
- (NSString *)uppercaseMapping;
- (NSString *)lowercaseMapping;
- (NSString *)titlecaseMapping;

- (BOOL)canonicalMapping;
- (BOOL)compatibilityMapping;
@end

@interface ESUnicodeData (DerivedTypes)
- (ESUnicode_CodepointType)codepointType;
- (BOOL)isAssignedToAbstractCharacter;
- (BOOL)isAssignedCodePoint; // assigned == designated  in this context
@end

@interface ESUnicodeData (Others)
- (NSString *)age;
- (NSUInteger)plane;
- (NSString *)block;
- (ESUnicode_LineBreakClass)lineBreak;
- (NSString *)script;
- (NSDictionary *)unihanData;
@end
