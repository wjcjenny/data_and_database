//
//  UCUtility.h
//  UnicodeChecker
//
//  Created by Steffen Kamp on 03.07.05.
//  Copyright 2005 earthlingsoft. All rights reserved.
//

#import <Cocoa/Cocoa.h>

// API for developing your own UCUtility plug-ins.
// Place your plug-in in any of the "Library" folders in "Application Support/UnicodeChecker/Plug-Ins/" (case sensitive).

// Protocol your UCUtility plug-in must conform to
@protocol UCUtility
- (NSString *)identifier;
- (NSString *)toolbarLabel;
- (NSString *)toolbarToolTip;
- (NSImage *)toolbarImage;
- (void)newInput:(id)sender;
- (NSView *)utilityView;
@end

// Optional methods
@interface NSObject (UCUtility)
- (NSView *)initialKeyView; // if you provide input fields you should return the first key view so the key view loop gets set up correctly
- (void)setUtilityProperties:(NSDictionary *)dict;
- (void)detachFromUtilityController; // will be called when the utility window closes and the utilities controller will be released. this gives you an opportunity to clean up (e.g. invoke -setContents:nil on your nib's object controllers)
@end

// If your plug-in wants to modify the string in the input text field of the utility window you must post a notification with name UCUtilityModifyInputNotificationName to the default notification center. The userInfo of the notification must provide an NSString containing the new input string for the UCUtilityNewInputKey key. Be careful to avoid recursion when posting this notification from your -newInput: method as this method will be invoked when UnicodeChecker receives the notification.
extern NSString *UCUtilityModifyInputNotificationName;
extern NSString *UCUtilityNewInputKey;

// If your plug-in wants to set the codepoint shown in the main window you must post a notification with name UCUtilityShowCodepointNotificationName to the default notification center. The userInfo must provide an NSNumber representing the codepoint for the UCUtilityShowCodepointNotificationCodepointKey.
extern NSString *UCUtilityShowCodepointNotificationName;
extern NSString *UCUtilityShowCodepointNotificationCodepointKey;
