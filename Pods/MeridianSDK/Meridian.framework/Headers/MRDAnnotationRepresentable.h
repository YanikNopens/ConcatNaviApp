//
//  MRDAnnotationRepresentable.h
//  Meridian
//
//  Created by Alex Belliotti on 12/3/19.
//  Copyright © 2019 Aruba Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MRDAnnotationRepresentable <NSObject>

@required
- (BOOL)representsAnnotation:(id<MRAnnotation>)annotation;

@end

NS_ASSUME_NONNULL_END
