//
//  ImageCropViewController.h
//  ImageRotateAndCrop
//
//  Created by iceboxi on 2015/6/11.
//  Copyright (c) 2015年 iceboxi. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ImageCropViewControllerDelegate <NSObject>

- (void)ImageCropViewController:(UIViewController* )controller didFinishCroppingImage:(UIImage *)croppedImage;
- (void)ImageCropViewControllerDidCancel:(UIViewController *)controller;

@end

@class ImageCropView;
@interface ImageCropViewController : UIViewController  <UIActionSheetDelegate > {
    ImageCropView * cropView;
    UIActionSheet * actionSheet;
}
@property (nonatomic, weak) id<ImageCropViewControllerDelegate> delegate;
@property (nonatomic) BOOL blurredBackground;
@property (nonatomic, retain) UIImage* image;
@property (nonatomic, retain) ImageCropView* cropView;

- (id)initWithImage:(UIImage*)image;
- (IBAction)cancel:(id)sender;
- (IBAction)done:(id)sender;

@end
