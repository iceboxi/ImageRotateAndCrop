//
//  CropperOverlayView.h
//  ImageRotateAndCrop
//
//  Created by iceboxi on 2015/6/11.
//  Copyright (c) 2015年 iceboxi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CropperOverlayView : UIView

// Corners
@property (readonly) CGRect topLeftCorner;
@property (readonly) CGRect topRightCorner;
@property (readonly) CGRect bottomLeftCorner;
@property (readonly) CGRect bottomRightCorner;

// Edges
@property (readonly) CGRect topEdgeRect;
@property (readonly) CGRect rightEdgeRect;
@property (readonly) CGRect bottomEdgeRect;
@property (readonly) CGRect leftEdgeRect;

- (BOOL)isCornerContainsPoint:(CGPoint)point;
- (BOOL)isEdgeContainsPoint:(CGPoint)point;

@end