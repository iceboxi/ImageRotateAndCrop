//
//  ShadeView.h
//  ImageRotateAndCrop
//
//  Created by iceboxi on 2015/6/11.
//  Copyright (c) 2015年 iceboxi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ShadeView : UIView {
    CGFloat cropBorderRed, cropBorderGreen, cropBorderBlue, cropBorderAlpha;
    CGRect cropArea;
    CGFloat shadeAlpha;
}

@property (nonatomic, retain) UIColor* cropBorderColor;
@property (nonatomic) CGRect cropArea;
@property (nonatomic) CGFloat shadeAlpha;
@property (nonatomic, strong) UIImageView *blurredImageView;

@end
