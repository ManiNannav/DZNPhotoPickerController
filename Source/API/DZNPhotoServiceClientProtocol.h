//
//  DZNPhotoServiceClientProtocol.h
//  Sample
//
//  Created by Ignacio on 2/12/14.
//  Copyright (c) 2014 DZN Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

UIKIT_EXTERN NSString *const DZNPhotoServiceClientConsumerKey;
UIKIT_EXTERN NSString *const DZNPhotoServiceClientConsumerSecret;

UIKIT_EXTERN NSString *NSStringHashFromServiceType(DZNPhotoPickerControllerService type, NSString *key);

typedef void (^DZNHTTPRequestCompletion)(NSArray *list, NSError *error);

/*
 * Base HTTP photo service protocol.
 */
@protocol DZNPhotoServiceClientProtocol <NSObject>

/*
 * Searches for a list of tags related to a keyword string.
 *
 * @param keyword The tag to fetch related tags for.
 * @param completion The completion block handler.
 */
- (void)searchTagsWithKeyword:(NSString *)keyword completion:(DZNHTTPRequestCompletion)completion;

/*
 * Searches for a list of photos mathing on a tag or keyword term.
 *
 * @param keyword The keyword term to fetch related tags for.
 * @param page The current page.
 * @param resultPerPage The amount of result per page.
 * @param completion The completion block handler.
 */
- (void)searchPhotosWithKeyword:(NSString *)keyword page:(NSInteger)page resultPerPage:(NSInteger)resultPerPage completion:(DZNHTTPRequestCompletion)completion;

/*
 * Cancels all HTTP request of the client.
 */
- (void)cancelRequest;

@end
