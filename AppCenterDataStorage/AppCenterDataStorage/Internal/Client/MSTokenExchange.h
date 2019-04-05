// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

#import "MSDataStorageConstants.h"
#import "MSTokenResult.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MSHttpClientProtocol;
@class MSTokensResponse;

typedef void (^MSGetTokenAsyncCompletionHandler)(MSTokensResponse *tokenResponses, NSError *_Nullable error);

/**
 * This class retrieves and caches Cosmosdb access token.
 */
@interface MSTokenExchange : NSObject

/**
 * Get token from token exchange.
 *
 * @param httpClient http client.
 * @param tokenExchangeUrl API url to exchange token.
 * @param appSecret application secret.
 * @param partition cosmosdb partition.
 * @param completionHandler callback that gets the token.
 */
+ (void)performDbTokenAsyncOperationWithHttpClient:(id<MSHttpClientProtocol>)httpClient
                                  tokenExchangeUrl:(NSURL *)tokenExchangeUrl
                                         appSecret:(NSString *)appSecret
                                         partition:(NSString *)partition
                                 completionHandler:(MSGetTokenAsyncCompletionHandler)completionHandler;

/**
 * Return a cached (CosmosDB resource) token for a given partition name.
 *
 * @param partition The partition for which to return the token.
 * @param expiredTokenIncluded The flag that indicates whether the method returns expired token or not.
 *
 * @return The cached token or `nil`.
 */
+ (MSTokenResult *_Nullable)retrieveCachedToken:(NSString *)partition expiredTokenIncluded:(BOOL)expiredTokenIncluded;

/*
 * When the user logs out, all the cached tokens are deleted.
 */
+ (void)removeAllCachedTokens;

@end

NS_ASSUME_NONNULL_END
