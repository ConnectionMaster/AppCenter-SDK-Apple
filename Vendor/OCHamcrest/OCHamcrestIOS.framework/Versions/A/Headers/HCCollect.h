//  OCHamcrest by Jon Reid, http://qualitycoding.org/about/
//  Copyright 2016 hamcrest.org. See LICENSE.txt

#import <Foundation/Foundation.h>

#import <stdarg.h>


/*!
 * @abstract Returns an array of values from a variable-length comma-separated list terminated
 * by <code>nil</code>.
 */
FOUNDATION_EXPORT NSArray * HCCollectItems(id item, va_list args);

/*!
 * @abstract Returns an array of matchers from a variable-length comma-separated list terminated
 * by <code>nil</code>.
 * @discussion Each item is wrapped in HCWrapInMatcher to transform non-matcher items into equality
 * matchers.
 *
 * <b>Deprecated:</b> Follow the example of HCAllOf.m and break this call into two steps:
 * HCCollectItems, then HCWrapIntoMatchers. This will let you expose a new interface to your matcher
 * that takes an NSArray.
 */
FOUNDATION_EXPORT NSArray * HCCollectMatchers(id item, va_list args) __attribute__((deprecated));

/*!
 * @abstract Returns an array of matchers from a mixed array of items and matchers.
 * @discussion Each item is wrapped in HCWrapInMatcher to transform non-matcher items into equality
 * matchers.
 */
FOUNDATION_EXPORT NSArray * HCWrapIntoMatchers(NSArray *items);