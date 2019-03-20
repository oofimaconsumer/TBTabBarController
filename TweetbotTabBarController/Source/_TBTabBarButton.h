//
//  _TBTabBarButton.h
//  TBTabBarController
//
//  Created by Timur Ganiev on 03/02/2019.
//  Copyright © 2019 Timur Ganiev. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TBTabBarItem, _TBDotView;

NS_ASSUME_NONNULL_BEGIN

@interface _TBTabBarButton : UIControl

@property (strong, nonatomic, readonly) UIImageView *imageView;

@property (strong, nonatomic, readonly) _TBDotView *dotView;

@property (assign, nonatomic) BOOL laysOutHorizontally;

@property (weak, nonatomic, readonly) TBTabBarItem *tabBarItem;

- (instancetype)initWithTabBarItem:(TBTabBarItem *)tabBarItem NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (nullable UIImage *)imageForState:(UIControlState)state;

- (void)setImage:(nullable UIImage *)image forState:(UIControlState)state;

@end

NS_ASSUME_NONNULL_END
