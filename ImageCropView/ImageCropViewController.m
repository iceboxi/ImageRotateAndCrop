//
//  ImageCropViewController.m
//  ImageRotateAndCrop
//
//  Created by iceboxi on 2015/6/11.
//  Copyright (c) 2015年 iceboxi. All rights reserved.
//

#import "ImageCropViewController.h"
#import "ImageCropView.h"
#import "UIImage-Extension.h"

@interface ImageCropViewController ()

@end

@implementation ImageCropViewController

@synthesize delegate;
@synthesize cropView;

-(id)initWithImage:(UIImage*) image{
    self =  [super init];
    if (self){
        self.image = [image fixOrientation];
    }
    
    return self;
}

- (void)loadView
{
    [super loadView];
}


- (void)viewDidLoad
{
    [super viewDidLoad];
    if (self){
//        if ([self.navigationController respondsToSelector:@selector(edgesForExtendedLayout)])
//            self.navigationController.edgesForExtendedLayout = UIRectEdgeNone;
        
        UIView *contentView = [[UIView alloc] init];
        contentView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        contentView.backgroundColor = [UIColor whiteColor];
        
        self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc]
                                                 initWithBarButtonSystemItem:UIBarButtonSystemItemCancel
                                                 target:self
                                                 action:@selector(cancel:)];
        
        self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]
                                                  initWithBarButtonSystemItem:UIBarButtonSystemItemDone
                                                  target:self
                                                  action:@selector(done:)];
        CGSize statusBarSize = [[UIApplication sharedApplication] statusBarFrame].size;
        CGRect view = CGRectMake(0, [[self navigationController] navigationBar].bounds.size.height, self.view.bounds.size.width, self.view.bounds.size.height - [[self navigationController] navigationBar].bounds.size.height - statusBarSize.height);
        self.cropView  = [[ImageCropView alloc] initWithFrame:view blurOn:self.blurredBackground];
        self.view = contentView;
        [contentView addSubview:cropView];
        [cropView setImage:self.image];
    }
}

- (IBAction)cancel:(id)sender
{
    
    if ([self.delegate respondsToSelector:@selector(ImageCropViewControllerDidCancel:)])
    {
        [self.delegate ImageCropViewControllerDidCancel:self];
    }
}

- (IBAction)done:(id)sender
{
    if ([self.delegate respondsToSelector:@selector(ImageCropViewController:didFinishCroppingImage:)])
    {
        UIImage *cropped;
        if (self.image != nil){
            CGRect CropRect = self.cropView.cropAreaInImage;
            CGImageRef imageRef = CGImageCreateWithImageInRect([self.image CGImage], CropRect) ;
            cropped = [UIImage imageWithCGImage:imageRef scale:0 orientation:self.image.imageOrientation];
            CGImageRelease(imageRef);
        }
        [self.delegate ImageCropViewController:self didFinishCroppingImage:cropped];
    }
}

@end
