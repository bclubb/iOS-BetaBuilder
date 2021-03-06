//
//  BuilderController.h
//  BetaBuilder
//
//  Created by Hunter Hillegas on 8/7/10.
//  Copyright 2010 Hunter Hillegas. All rights reserved.
//

/* 
 iOS BetaBuilder - a tool for simpler iOS betas
 Version 1.6
 
 Condition of use and distribution:
 
 This software is provided 'as-is', without any express or implied
 warranty.  In no event will the authors be held liable for any damages
 arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it
 freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not
 claim that you wrote the original software. If you use this software
 in a product, an acknowledgment in the product documentation would be
 appreciated but is not required.
 2. Altered source versions must be plainly marked as such, and must not be
 misrepresented as being the original software.
 3. This notice may not be removed or altered from any source distribution.
 */


//
// https://github.com/blindsightcorp/BSMobileProvision
//
typedef NS_ENUM(NSInteger, UIApplicationReleaseMode) {
    UIApplicationReleaseUnknown = 0,
    UIApplicationReleaseSim,
    UIApplicationReleaseDev,
    UIApplicationReleaseAdHoc,
    UIApplicationReleaseAppStore,
    UIApplicationReleaseEnterprise,
};

#import <Cocoa/Cocoa.h>

@interface NSString (MyAdditions)
- (NSString *)md5;
@end

@interface NSData (MyAdditions)
- (NSString*)md5;
@end

@interface BuilderController : NSObject <NSFileManagerDelegate>

@property (nonatomic) IBOutlet NSTextField *bundleIdentifierField;
@property (nonatomic) IBOutlet NSTextField *bundleVersionField;
@property (nonatomic) IBOutlet NSTextField *bundleNameField;
@property (nonatomic) IBOutlet NSTextField *webserverDirectoryField;
@property (nonatomic) IBOutlet NSTextField *archiveIPAFilenameField;
@property (nonatomic) IBOutlet NSButton *overwriteFilesButton;
@property (nonatomic) IBOutlet NSButton *includeZipFileButton;
@property (nonatomic) IBOutlet NSButton *generateFilesButton;
@property (nonatomic) IBOutlet NSButton *openInFinderButton;
@property (nonatomic) IBOutlet NSProgressIndicator *progressIndicator;

@property (nonatomic, copy) NSString *mobileProvisionFilePath;
@property (nonatomic, copy) NSString *appIconFilePath;
@property (nonatomic, copy) NSString *templateFile;
@property (nonatomic, copy) NSURL *destinationPath;
@property (nonatomic, copy) NSString *previousDestinationPathAsString;

@property (nonatomic, assign) BOOL saveToDefaultFolder, uploadToAppStore;
@property (nonatomic, strong) NSString *folderName;
@property (nonatomic, strong) NSString *ipaFilename;
@property (nonatomic, strong) NSString *manifest;
@property (nonatomic, strong) NSDictionary *bundlePlistFile;
@property (nonatomic, strong) NSString *artworkDestinationFilename;
@property (nonatomic, strong) NSDictionary *mobileProvision;
@property (nonatomic, strong) NSMutableArray *certificates;
@property (nonatomic, strong) NSMutableArray *devices;
@property (nonatomic, strong) NSString *modeString;

- (IBAction)specifyIPAFile:(id)sender;
- (IBAction)generateFiles:(id)sender;
- (IBAction)openInFinder:(id)sender;

- (void)generateFilesWithWebserverAddress:(NSString *)webserver andOutputDirectory:(NSString *)outputPath;
- (BOOL)saveFilesToOutputDirectory:(NSURL *)saveDirectoryURL forManifestDictionary:(NSDictionary *)outerManifestDictionary withTemplateHTML:(NSString *)htmlTemplateString;

- (void)setupFromIPAFile:(NSString *)ipaFilename;

- (void)populateFieldsFromHistoryForBundleID:(NSString *)bundleID;
- (void)storeFieldsInHistoryForBundleID:(NSString *)bundleID;

@end
