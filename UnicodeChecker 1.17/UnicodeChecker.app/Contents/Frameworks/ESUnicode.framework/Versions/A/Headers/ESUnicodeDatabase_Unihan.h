//
//  ESUnicodeDatabase_Unihan.h
//  UnicodeChecker
//
//  Created by Steffen Kamp on 30.07.09.
//  Copyright 2009 earthlingsoft. All rights reserved.
//

#import "ESUnicodeDatabase.h"

extern NSString *ESUnicodeDidReadUnihanNotificationName;
extern NSString *ESUnicodeReadingUnihanNotificationName;

extern NSString *ESUnicodeUnihanReadingFileCountKey;
extern NSString *ESUnicodeUnihanReadingFilenameKey;
extern NSString *ESUnicodeUnihanReadingFileIndexKey;
extern NSString *ESUnicodeUnihanReadingFileProgressKey;
extern NSString *ESUnicodeUnihanReadingProgressKey;

@interface ESUnicodeDatabase (Unihan)

- (BOOL)isUnihanAvailable;
- (BOOL)isUnihanRead;
- (BOOL)isReadingUnihan; // bindable
- (void)readUnihanAsynchronously;

- (NSDictionary *)unihan; // key: NSNumber, value: NSDictionary
- (NSDictionary *)unihanDataForCodepoint:(UTF32Char)code;

- (NSSet *)unihanNumericKeys;
- (NSSet *)unihanKeys;

@end
