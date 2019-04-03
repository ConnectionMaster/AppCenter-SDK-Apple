// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MSAuthTokenContext;
@class MSUserInformation;

@protocol MSAuthTokenContextDelegate <NSObject>

@optional

/**
 * A callback that is called when an auth token is received.
 *
 * @param authTokenContext The auth token context.
 * @param authToken The new auth token.
 */
- (void)authTokenContext:(MSAuthTokenContext *)authTokenContext didUpdateAuthToken:(nullable NSString *)authToken;

/**
 * A callback that is called when a new user signs in.
 *
 * @param authTokenContext The auth token context.
 * @param userInformation The new user information. `nil` if a user signed out.
 */
- (void)authTokenContext:(MSAuthTokenContext *)authTokenContext didUpdateUserInformation:(nullable MSUserInformation *)userInformation;

@end

NS_ASSUME_NONNULL_END
