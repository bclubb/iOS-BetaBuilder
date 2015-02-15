//
//  NSObject+DeepMutableCopy.h
//  ILSAd
//
//  Created by 周和生 on 14/11/20.
//  Copyright (c) 2014年 iLegendSoft. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (DeepMutableCopy)
- (id)deepMutableCopy;
@end

@interface NSDate (DeepMutableCopy)
- (id)deepMutableCopy;
@end

@interface NSData (DeepMutableCopy)
- (id)deepMutableCopy;
@end

@interface NSNumber (DeepMutableCopy)
- (id)deepMutableCopy;
@end

@interface NSDictionary (DeepMutableCopy)
- (id)deepMutableCopy;
@end

@interface NSArray (DeepMutableCopy)
- (id)deepMutableCopy;
@end


