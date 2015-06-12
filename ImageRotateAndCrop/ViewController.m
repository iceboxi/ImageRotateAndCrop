//
//  ViewController.m
//  ImageRotateAndCrop
//
//  Created by iceboxi on 2015/6/11.
//  Copyright (c) 2015年 iceboxi. All rights reserved.
//

#import "ViewController.h"
#import "ImageCropView.h"
#import "UIImage-Extension.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    if ([self.navigationController respondsToSelector:@selector(edgesForExtendedLayout)])
        self.navigationController.edgesForExtendedLayout = UIRectEdgeNone;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)openBarButtonClick:(id)sender {
    UIImagePickerController *imagePickerController = [[UIImagePickerController alloc] init];
    imagePickerController.delegate = self;
    [self presentViewController:imagePickerController animated:YES completion:nil];
}

#pragma mark UIImagePickerController Delegate
- (void) imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    imageView.image = [info valueForKey:UIImagePickerControllerOriginalImage];
    [[self navigationController] dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark -

- (IBAction)cropBarButtonClick:(id)sender {
    if(imageView.image != nil){
        ImageCropViewController *controller = [[ImageCropViewController alloc] initWithImage:imageView.image];
        controller.delegate = self;
        controller.blurredBackground = NO;
        [[self navigationController] pushViewController:controller animated:YES];
    }
}

#pragma mark ImageCropViewController Delegate
- (void)ImageCropViewController:(ImageCropViewController *)controller didFinishCroppingImage:(UIImage *)croppedImage{
    imageView.image = croppedImage;
    [[self navigationController] popViewControllerAnimated:YES];
}

- (void)ImageCropViewControllerDidCancel:(ImageCropViewController *)controller{
    [[self navigationController] popViewControllerAnimated:YES];
}

#pragma mark -

- (IBAction)rotateBarButtonClick:(id)sender {
    imageView.image = [[imageView.image fixOrientation] imageRotatedByRadians:M_PI_2];
}

@end
