// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import "MSDispatcherUtil.h"
#import "MSAppCenterInternal.h"

@implementation MSDispatcherUtil

+ (void)performBlockOnMainThread:(void (^)(void))block {

#if TARGET_OS_OSX
  [self performSelectorOnMainThread:@selector(runBlock:) withObject:block waitUntilDone:NO];
#else
  if ([NSThread isMainThread]) {
    block();
  } else {
    dispatch_async(dispatch_get_main_queue(), block);
  }
#endif
}

+ (void)runBlock:(void (^)(void))block {
  block();
}

+ (void)dispatchSyncWithTimeout:(int)timeout onQueue:(dispatch_queue_t)dispatchQueue withBlock:(dispatch_block_t)block {
  dispatch_semaphore_t delayedProcessingSemaphore = dispatch_semaphore_create(0);
  dispatch_async(dispatchQueue, ^{
    block();
    dispatch_semaphore_signal(delayedProcessingSemaphore);
  });
  dispatch_semaphore_wait(delayedProcessingSemaphore, dispatch_time(DISPATCH_TIME_NOW, timeout * NSEC_PER_SEC));
}
@end
