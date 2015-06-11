//
//  ViewController.h
//  ImageRotateAndCrop
//
//  Created by iceboxi on 2015/6/11.
//  Copyright (c) 2015年 iceboxi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ImageCropViewController.h"

@interface ViewController : UIViewController <UINavigationControllerDelegate, UIImagePickerControllerDelegate, ImageCropViewControllerDelegate> {
    IBOutlet UIImageView *imageView;
}

- (IBAction)openBarButtonClick:(id)sender;
- (IBAction)cropBarButtonClick:(id)sender;
- (IBAction)rotateBarButtonClick:(id)sender;

@end

