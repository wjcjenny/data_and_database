//
//  ESXHTMLDatabase.h
//  ESUnicode
//
//  Created by Steffen Kamp on Mon Oct 21 2002.
//  Copyright (c) 2002 earthlingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ESXHTMLDatabase : NSObject {
    NSMutableDictionary *XHTMLEntities;
}

- (id)initWithDirectory:(NSString *)directoryPath;

- (void)readXHTMLEntitiesFromDirectory:(NSString *)directoryPath;
- (NSDictionary *)XHTMLEntitiesForPath:(NSString *)path;
- (NSString *)XHTMLEntityForCodepoint:(int)code; // may return nil
- (NSString *)stringForXHTMLEntity:(NSString *)entity; // may return nil
- (NSString *)XHTMLEntityForCodepoint:(int)code preferNamed:(BOOL)named decimal:(BOOL)decimal;

- (NSString *)unicodeStringFromXHTML:(NSString *)XHTML;
- (NSString *)unicodeStringFromXHTML:(NSString *)XHTML numberOfReplacements:(int *)count;
- (NSString *)unicodeStringFromXHTML:(NSString *)XHTML lowASCII:(BOOL)lowASCII numberOfReplacements:(int *)count;
- (NSString *)unicodeStringFromXHTML:(NSString *)XHTML preservingCharactersFromSet:(NSCharacterSet *)charset numberOfReplacements:(int *)count;

- (NSString *)XHTMLStringFromUnicode:(NSString *)string lowASCII:(BOOL)lowASCII;
- (NSString *)XHTMLStringFromUnicode:(NSString *)string lowASCII:(BOOL)lowASCII numberOfReplacements:(int *)count;
- (NSString *)XHTMLStringFromUnicode:(NSString *)string lowASCII:(BOOL)lowASCII decimal:(BOOL)decimalFlag numberOfReplacements:(int *)count;
- (NSString *)XHTMLStringFromUnicode:(NSString *)string lowASCII:(BOOL)lowASCII preferNamed:(BOOL)named decimal:(BOOL)decimalFlag numberOfReplacements:(int *)count;
- (NSString *)XHTMLStringFromUnicode:(NSString *)string preservingCharactersFromSet:(NSCharacterSet *)charset preferNamed:(BOOL)named decimal:(BOOL)decimalFlag numberOfReplacements:(int *)count;

@end
