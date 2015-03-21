//
//  RRItemsTableViewController.h
//  RRTouchRemote
//
//  Created by Rolandas Razma on 20/03/2015.
//  Copyright (c) 2015 Rolandas Razma. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RRTouchRemoteService.h"


@interface RRItemsTableViewController : UITableViewController

@property (nonatomic, retain) RRTouchRemoteService *touchRemoteService;
@property (nonatomic, assign) NSUInteger databaseID;
@property (nonatomic, assign) NSUInteger containerID;

@end
