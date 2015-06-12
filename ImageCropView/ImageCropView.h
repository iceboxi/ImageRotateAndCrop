//
//  ImageCropView.h
//  ImageRotateAndCrop
//
//  Created by iceboxi on 2015/6/11.
//  Copyright (c) 2015年 iceboxi. All rights reserved.
//

#import <UIKit/UIKit.h>

CGRect SquareCGRectAtCenter(CGFloat centerX, CGFloat centerY, CGFloat size);

UIView* dragView;
typedef struct {
    CGPoint dragStart;
    CGPoint topLeftCenter;
    CGPoint bottomLeftCenter;
    CGPoint bottomRightCenter;
    CGPoint topRightCenter;
    CGPoint clearAreaCenter;
} DragPoint;

// Used when working with multiple dragPoints
typedef struct {
    DragPoint mainPoint;
    DragPoint optionalPoint;
    NSUInteger lastCount;
} MultiDragPoint;

@class CropperOverlayView, ControlPointView, ShadeView;
@interface ImageCropView : UIView {
    UIImageView* imageView;
    CGRect imageFrameInView;
    CGFloat imageScale;
    
    CGFloat controlPointSize;
    ControlPointView* topLeftPoint;
    ControlPointView* bottomLeftPoint;
    ControlPointView* bottomRightPoint;
    ControlPointView* topRightPoint;
    NSArray *PointsArray;
    UIColor* controlColor;
    
    CropperOverlayView* cropAreaView;
    DragPoint dragPoint;
    MultiDragPoint multiDragPoint;
    
    UIView* dragViewOne;
    UIView* dragViewTwo;
}
- (id)initWithFrame:(CGRect)frame blurOn:(BOOL)blurOn;
- (void)setImage:(UIImage*)image;

@property (nonatomic) CGFloat controlPointSize;
@property (nonatomic, retain) UIImage* image;
@property (nonatomic) CGRect cropAreaInView;
@property (nonatomic) CGRect cropAreaInImage;
@property (nonatomic, readonly) CGFloat imageScale;
@property (nonatomic) CGFloat maskAlpha;
@property (nonatomic, retain) UIColor* controlColor;
@property (nonatomic, strong) ShadeView* shadeView;
@property (nonatomic) BOOL blurred;
@property (nonatomic) NSUInteger rotateFlag;

@end
