//
//  RRTouchRemoteService.h
//  RRTouchRemote
//
//  Created by Rolandas Razma on 20/03/2015.
//  Copyright (c) 2015 Rolandas Razma. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, RRGroupType) {
    RRGroupTypeArtists,
    RRGroupTypeAlbums,
};


@interface RRTouchRemoteService : NSObject

@property (nonatomic, readonly) NSString *name;

- (instancetype)initWithNetService:(NSNetService *)service pairID:(NSUInteger)pairID;

- (void)loginWithCompletionHandler:(void (^)(NSError *error))completionHandler;
- (void)serverInfoWithCompletionHandler:(void (^)(id serverInfo, NSError *error))completionHandler;
- (void)databasesWithCompletionHandler:(void (^)(id databases, NSError *error))completionHandler;
- (void)groupsInDatabase:(NSUInteger)databaseID type:(RRGroupType)type meta:(NSArray *)meta query:(NSString *)query completionHandler:(void (^)(id groups, NSError *error))completionHandler;
- (void)containersInDatabase:(NSUInteger)databaseID meta:(NSArray *)meta completionHandler:(void (^)(id containers, NSError *error))completionHandler;
- (void)itemsInDatabase:(NSUInteger)databaseID meta:(NSArray *)meta query:(NSString *)query completionHandler:(void (^)(id items, NSError *error))completionHandler;
- (void)itemsInDatabase:(NSUInteger)databaseID containerID:(NSUInteger)containerID meta:(NSArray *)meta query:(NSString *)query completionHandler:(void (^)(id items, NSError *error))completionHandler;
- (void)artworkForItemID:(NSUInteger)itemID inDatabaseID:(NSUInteger)databaseID completionHandler:(void (^)(UIImage *image, NSError *error))completionHandler;
- (void)artworkForGroupID:(NSUInteger)groupID inDatabaseID:(NSUInteger)databaseID type:(RRGroupType)type completionHandler:(void (^)(UIImage *image, NSError *error))completionHandler;
- (void)playItemID:(NSUInteger)itemID databaseID:(NSUInteger)databaseID completionHandler:(void (^)(NSError *error))completionHandler;
- (void)playSpecItemID:(NSUInteger)itemID databaseID:(NSUInteger)databaseID containerID:(NSUInteger)containerID completionHandler:(void (^)(NSError *error))completionHandler;

@end
