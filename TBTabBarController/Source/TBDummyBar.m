//
//  TBDummyBar.m
//  TBTabBarController
//
//  Copyright (c) 2019-2020 Timur Ganiev
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import "TBDummyBar.h"

#import "_TBUtils.h"
#import "UIView+_TBTabBarController.h"

@implementation TBDummyBar

#pragma mark - Public

#pragma mark Lifecycle

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        [self tbfknvbr_commonInit];
    }
    
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    
    self = [super initWithFrame:frame];
    
    if (self) {
        [self tbfknvbr_commonInit];
    }
    
    return self;
}

#pragma mark Overrides

- (void)layoutSubviews {
    
    [super layoutSubviews];
    
    CGRect const bounds = self.bounds;
    
    CGFloat const width = CGRectGetWidth(bounds);
    CGFloat const height = CGRectGetHeight(bounds);
    CGFloat const displayScale = self.tb_displayScale;
    
    UIEdgeInsets const safeAreaInsets = self.safeAreaInsets;
    UIEdgeInsets const contentInsets = self.contentInsets;
    
    UIView *subview = self.subview;
    
    CGRect frame = subview.frame;
    frame.size = [subview sizeThatFits:(CGSize){width - safeAreaInsets.left - safeAreaInsets.right - contentInsets.left, height - contentInsets.top - contentInsets.bottom - safeAreaInsets.top}];
    frame.origin = (CGPoint){safeAreaInsets.left + (((width - safeAreaInsets.left) - frame.size.width) / 2.0) , height + contentInsets.top - contentInsets.bottom - frame.size.height};
    
    subview.frame = _TBFloorRectWithScale(frame, displayScale);
}

- (TBSimpleBarSeparatorPosition)separatorPosition {
    
    return self.tb_isLeftToRight ? TBSimpleBarSeparatorPositionRight : TBSimpleBarSeparatorPositionLeft;
}

#pragma mark - Private

#pragma mark Setup

- (void)tbfknvbr_commonInit {
    
    self.contentInsets = UIEdgeInsetsMake(0.0, 0.0, 6.0, 0.0);
}

#pragma mark Setters

- (void)setSubview:(__kindof UIView *)subview {
    
    if (subview != nil) {
        [self addSubview:subview];
    } else {
        [_subview removeFromSuperview];
    }
    
    _subview = subview;
}

@end
