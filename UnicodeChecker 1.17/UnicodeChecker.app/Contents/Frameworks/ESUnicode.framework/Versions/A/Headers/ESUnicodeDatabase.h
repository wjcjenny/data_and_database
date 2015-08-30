//
//  ESUnicodeDatabase.h
//  ESUnicode
//
//  Created by Steffen Kamp on Sat Mar 16 2002.
//  Copyright (c) 2001 earthlingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESUnicodeData.h"

#define ESUNICODE_MAX_CODEPOINT 0x10ffff

@class ESUnicodeData, ESUnicodeArabicShaping, ESUnicodeNamesList_CharEntry, ESUnicodeRangeDirectory, ESUnicodePrefixTree;

// file name prefixes for data files
extern NSString *ESUnicodeFilePrefixArabicShaping;
extern NSString *ESUnicodeFilePrefixBlocks;
extern NSString *ESUnicodeFileCaseFolding;
extern NSString *ESUnicodeFilePrefixCompositionExclusions;
extern NSString *ESUnicodeFilePrefixDerivedAge;
extern NSString *ESUnicodeFilePrefixDerivedCoreProperties;
extern NSString *ESUnicodeFilePrefixHangulSyllableType;
extern NSString *ESUnicodeFilePrefixIndex;
extern NSString *ESUnicodeFilePrefixJamo;
extern NSString *ESUnicodeFilePrefixLineBreak;
extern NSString *ESUnicodeFilePrefixNamesList;
extern NSString *ESUnicodeFilePrefixPropertyValueAliases;
extern NSString *ESUnicodeFilePrefixPropList;
extern NSString *ESUnicodeFilePrefixScripts;
extern NSString *ESUnicodeFilePrefixSpecialCasing;
extern NSString *ESUnicodeFilePrefixUnihan;
extern NSString *ESUnicodeFilePrefixUnicodeData;

// keys for dictionaries returned by -dataFilenamesAndVersions
extern NSString *ESUnicodeFilePrefixKey; // value: NSString
extern NSString *ESUnicodeFilePathsKey; // value: NSSet of NSStrings
extern NSString *ESUnicodeFileVersionsKey; // value: NSArray of NSStrings 

@interface ESUnicodeDatabase : NSObject {
    NSMutableArray *_allUnicodeData; // contains all UnicodeData objects
    __weak ESUnicodeData **_databaseIndex;   // lookup table: _databaseIndex[<codepoint>] gets desired UnicodeData pointer
    NSUInteger _unicodeDataLineCount;
    
    NSArray *_dataDirectories;
    NSArray *_descDirectories;

    NSMutableDictionary *_mappingDictionary; // key: aCodepoint, object: (NSDictionary key: bCodepoint, object: combinedCodepoint)
    NSMutableArray *_compositionExclusions; // objects: NSRange
    NSMutableArray *_identicalPropertyRanges; // objects: NSRange

    NSMutableDictionary *_propertyValueAliases; // key: NSString (PropertyAlias), object: NSDictionary
    NSMutableDictionary *_compatibilityMappingTagDescriptions; // key: NSString, object: NSString - note: mapping tag descriptions are not part of PropertyValueAliases.txt (only the alias names)

    NSDictionary *_extendedProperties; // key: property, object: NSArray of NSRanges
    NSDictionary *_derivedCoreProperties; // key: property, object: NSArray of NSRanges
    NSDictionary *_scripts; // key: scriptname, object: NSArray of NSRanges
    NSMutableDictionary *_blocks; // key: NSRange, object: NSString
    NSMutableDictionary *_specialCasings; // key: codepoint, object: NSArray of UnicodeSpecialCasing
    NSMutableDictionary *_arabicShapings; // key: codepoint, object: UnicodeArabicShaping
    NSMutableDictionary *_jamoShortNames; // key: codepoint, object: NSString
    NSMutableArray      *_namesList; // objects: ESUnicodeNamesList_CharEntry
    NSDictionary *_hangulSyllableTypes; // key: property, object: NSArray of NSRanges
    NSMutableDictionary *_caseFolding; // key: case folding type, object: NSDictionary (key: codepoint, object: NSString)
    ESUnicodePrefixTree *_lineBreaks;

    NSDictionary *_versionDesignated; // key: versionname, object: NSArray of NSRanges
   
    NSMutableSet        *_generalCategoryValues;
    NSMutableSet        *_bidirectionalCategoryValues;
    
    BOOL _isDatabaseRead;
    
    BOOL _isUnihanAvailable;
    BOOL _isReadingUnihan;
    NSLock *_unihanReadingLock;
    NSMutableDictionary *_unihan;
    NSMutableSet *_unihanKeys;
    NSMutableSet *_unihanNumericKeys;

    NSMutableDictionary *_nameLookup; // key: NSString, object NSNumber
    NSMutableDictionary *_nameLookupWithoutUnihan; // key: NSString, object NSNumber
    BOOL                 _nameLookupContainsDatabase;
    BOOL                 _nameLookupContainsIndex;
    BOOL                 _nameLookupContainsUnihan;
    NSArray             *_sortedNameLookupKeys;
    NSArray             *_sortedNameLookupWithoutUnihanKeys;
    NSMutableDictionary *_indexNames; // contents of Index.txt - key: NSNumber, object: NSArray of NSStrings
    
    NSArray *_unicodeDataVersions;
    NSString *_consistentVersion;
    NSArray *_dataFilenamesAndVersions;
    
    NSDictionary *_infoDictionary; // contains e.g. MD5 hashes of Unidata files
    
    id _delegate;
}

//+ (id)sharedDatabase; // This method is declared in a category, see below.

// designated initialiser (descPathArray and infoDict may be nil)
- (id)initWithUnidataDirectoryPaths:(NSArray *)unidataPathArray descriptionDirectoryPaths:(NSArray *)descPathArray infoDictionary:(NSDictionary *)infoDict;

- (id)initWithUnidataDirectoryPaths:(NSArray *)unidataPathArray descriptionDirectoryPaths:(NSArray *)descPathArray infoFile:(NSString *)path;

- (void)setDelegate:(id)delegate;
- (id)delegate;

- (NSArray *)allUnicodeData;

- (ESUnicodeData *)unicodeDataForCodepoint:(UTF32Char)code;
- (ESUnicodeData *)unicodeDataForCodepointNumber:(NSNumber *)value;
- (NSArray *)extendedPropertiesForCodepoint:(UTF32Char)code;
- (NSArray *)derivedCorePropertiesForCodepoint:(UTF32Char)code;
- (NSString *)scriptForCodepoint:(UTF32Char)code; // never returns nil
- (NSString *)missingScript;
- (NSString *)characterBlockForCodepoint:(UTF32Char)code; // never returns nil - deprecated, use blockForCodepoint:
- (NSString *)blockForCodepoint:(UTF32Char)code; // never returns nil
- (NSString *)missingBlock;
- (NSArray *)specialCasingsForCodepoint:(UTF32Char)code;
- (ESUnicodeArabicShaping *)arabicShapingForCodepoint:(UTF32Char)code;
- (NSString *)jamoShortNameForCodepoint:(UTF32Char)code;
- (NSString *)versionCodepointWasDesignated:(UTF32Char)code;
- (ESUnicodeNamesList_CharEntry *)namesListCharEntryForCodepoint:(UTF32Char)codepoint;
- (NSString *)hangulSyllableTypeForCodepoint:(UTF32Char)codepoint;
- (NSString *)missingHangulSyllableType;
- (ESUnicode_LineBreakClass)lineBreakForCodepoint:(UTF32Char)codepoint;
- (ESUnicode_LineBreakClass)missingLineBreak;

- (NSDictionary *)scripts;
- (NSDictionary *)blocks;

- (NSDictionary *)caseFolding;

- (ESUnicodePrefixTree *)lineBreaks;

- (NSDictionary *)versionDesignated;

- (NSSet *)generalCategoryValues;
- (NSSet *)bidirectionalCategoryValues;

- (NSNumber *)primaryCompositeForCodepointNumber:(NSNumber *)aVal secondCodepointNumber:(NSNumber *)bVal;

// Normalization Forms according to "Unicode Standard Annex #15 - Unicode Normalization Forms"
// http://www.unicode.org/unicode/reports/tr15

- (NSString *)normalizationFormCForString:(NSString *)inStr;
- (NSString *)normalizationFormDForString:(NSString *)inStr;
- (NSString *)normalizationFormKCForString:(NSString *)inStr;
- (NSString *)normalizationFormKDForString:(NSString *)inStr;
- (NSString *)normalizationFormCForString:(NSString *)inStr decompositionReplacementCount:(out NSInteger *)outDecompReplacementCount decompositionReorderingCout:(out NSInteger *)outDecompReorderingCount compositionReplacementCount:(out NSInteger *)outCompReplacementCount;
- (NSString *)normalizationFormDForString:(NSString *)inStr decompositionReplacementCount:(out NSInteger *)outDecompReplacementCount decompositionReorderingCout:(out NSInteger *)outDecompReorderingCount;
- (NSString *)normalizationFormKCForString:(NSString *)inStr decompositionReplacementCount:(out NSInteger *)outDecompReplacementCount decompositionReorderingCout:(out NSInteger *)outDecompReorderingCount compositionReplacementCount:(out NSInteger *)outCompReplacementCount;
- (NSString *)normalizationFormKDForString:(NSString *)inStr decompositionReplacementCount:(out NSInteger *)outDecompReplacementCount decompositionReorderingCout:(out NSInteger *)outDecompReorderingCount;
- (NSString *)normalizationFormK:(BOOL)K C:(BOOL)C forString:(NSString *)inStr;
- (NSString *)normalizationFormK:(BOOL)K C:(BOOL)C forString:(NSString *)inStr decompositionReplacementCount:(out NSInteger *)outDecompReplacementCount decompositionReorderingCout:(out NSInteger *)outDecompReorderingCount compositionReplacementCount:(out NSInteger *)outCompReplacementCount;

// warning: running this test may take a while
- (BOOL)runNormalizationConformanceTestsForTestFileAtURL:(NSURL *)url;

// canonical or compatibility decomposition
- (NSMutableArray *)decomposeString:(NSString *)inStr usingCompatibilityMappings:(BOOL)compat;
- (NSMutableArray *)decomposeString:(NSString *)inStr usingCompatibilityMappings:(BOOL)compat replacementCount:(out NSInteger *)replacementCount reorderingCount:(out NSInteger *)reorderingCount;

- (NSDictionary *)propertyValueAliasesForProperty:(NSString *)property; // property currently must be an abbreviated property name (1st field of PropertyAliases.txt)
- (NSString *)generalCategoryDescriptionForCodepoint:(UTF32Char)code;
- (NSString *)bidirectionalCategoryDescriptionForCodepoint:(UTF32Char)code;
- (NSString *)lineBreakDescriptionForCodepoint:(UTF32Char)code;
- (NSString *)combiningClassDescriptionForCodepoint:(UTF32Char)code;
- (NSString *)arabicShapingJoiningTypeDescriptionForCodepoint:(UTF32Char)code;
- (NSString *)mappingDescriptionForCodepoint:(UTF32Char)code;

- (NSString *)fullCaseFoldingForString:(NSString *)inStr;

- (NSDictionary *)nameLookup;
- (NSDictionary *)nameLookupWithoutUnihan;
- (NSArray *)sortedNameLookupKeys;
- (NSArray *)sortedNameLookupWithoutUnihanKeys;
- (NSDictionary *)indexNames;

- (NSDictionary *)infoDictionary;
- (NSArray *)unicodeDataMD5Array;

- (NSArray *)unicodeDataVersions; // multiple versions may have the same data files
- (NSString *)unicodeDataVersion; // best matching version (either same as all other files or latest matching)
- (BOOL)isConsistent;
- (NSArray *)dataFilenamesAndVersions; // deprecated - use -unicodeDataFileInfos
- (NSArray *)unicodeDataFileInfos; // array containing  dictionaries. Each dictionary containes file prefix, file name and versions for the keys ESUnicodeFilePrefixKey, ESUnicodeFilePathKey, ESUnicodeFileVersionsKey
- (NSDictionary *)unicodeDataFileInfoForFilePrefix:(NSString *)filePrefix;

- (NSUInteger)unicodeDataLineCount;

- (NSArray *)filenamesWithPrefix:(NSString *)filePrefix;

@end

@interface ESUnicodeDatabase (SharedDatabase)
+ (id)sharedDatabase; // ESUnicode does not implement this method - this is your duty (see ESUnicode.h)
@end

@interface NSObject (UnicodeDatabaseDelegate)
- (void)unicodeDatabase:(ESUnicodeDatabase *)database couldNotFindFile:(NSString *)filename;
@end
