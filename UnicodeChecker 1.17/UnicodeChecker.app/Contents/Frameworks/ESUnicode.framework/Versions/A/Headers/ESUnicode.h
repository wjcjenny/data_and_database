//
//  ESUnicode.h
//  ESUnicode
//
//  Created by Steffen Kamp on 07.08.05.
//  Copyright 2005 earthlingsoft. All rights reserved.
//

//
// Usage notes:
//
// The ESUnicode framework is a part of UnicodeChecker. You are not allowed
// to redistribute this framework without the UnicodeChecker application
// or bundle it with other software without my prior agreement.
// Should you want to bundle the ESUnicode framework with your own
// software, please contact me at steffen@earthlingsoft.net
//
//
// Disclaimer:
//
// The ESUnicode framework is not really in a stable state.
// Methods may be removed or change their semantics in any version
// without prior notice. However, please feel free to play around,
// suggest improvements, report bugs and have fun.
// If you need help using ESUnicode send me an e-mail: steffen@earthlingsoft.net
//
//
// Status:
//
// Documentation of ESUnicode is limited (non-existent?!). I hope most of the
// methods are somewhat self-explanatory.
// Not all UnicodeChecker functionality can be found in ESUnicode. I may add
// some of the missing features (e.g. IDNA) in a future release or even open-source
// the whole framework. Tell me what you think.
//
//
// Getting started:
//
// To get started, here are simplified versions of the methods UnicodeChecker uses
// to instantiate the main ESUnicode classes ESUnicodeDatabase and ESXHTMLDatabase.
// These methods are not part of ESUnicode because of hard-coded paths.
// However, +sharedDatabase of ESUnicodeDatabase is used internally. It is therefore
// declared in ESUnicodeDatabase.h but not implemented, so you need to provide an
// implementation for ESUnicode to work.
//
//@implementation ESUnicodeDatabase (UCSharedDatabase)
//+ (id)sharedDatabase {
//  static ESUnicodeDatabase *_sharedDatabase = nil;
//  if (!_sharedDatabase) {
//    NSString *path = nil;
//    
//    path = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"Unicode Data"];
//    NSArray *unidataPath = [NSArray arrayWithObject:path];
//    
//    path = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"Unicode Descriptions"];
//    NSArray *descPath    = [NSArray arrayWithObject:path];
//    
//    NSString *infoFile = [[NSBundle mainBundle] pathForResource:@"UnicodeData Hashes" ofType:@"plist"];
//    
//    _sharedDatabase = [[ESUnicodeDatabase allocWithZone:[self zone]] initWithUnidataDirectoryPaths:unidataPath
//                                                                         descriptionDirectoryPaths:descPath
//                                                                                          infoFile:infoFile];
//  }
//  return _sharedDatabase;
//}
//@end
//
//@implementation ESXHTMLDatabase (UCSharedDatabase)
//+ (id)sharedDatabase {
//  static ESXHTMLDatabase *_sharedDatabase = nil;
//  if (!_sharedDatabase) {
//    NSString *path = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"XHTML Entities"];
//    _sharedDatabase = [[ESXHTMLDatabase allocWithZone:[self zone]] initWithDirectory:path];
//  }
//  return _sharedDatabase;
//}
//@end
//


#import "ESUnicode_Defines.h"

#import "ESUnicodeArabicShaping.h"
#import "ESUnicodeData.h"
#import "ESUnicodeDatabase.h"
#import "ESUnicodeDatabase_Hangul.h"
#import "ESUnicodeDatabase_IDNA.h"
#import "ESUnicodeDatabase_Unihan.h"
#import "ESUnicodeNamesList.h"
#import "ESUnicodeSpecialCasing.h"
#import "ESUnicodeStringprepProcessor.h"
#import "ESXHTMLDatabase.h"
#import "NSString_ESUnicode.h"
#import "NSArray_ESUnicode.h"
