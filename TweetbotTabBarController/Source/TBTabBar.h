//
//  TBTabBar.h
//  TBTabBarController
//
//  Copyright (c) 2019 Timur Ganiev
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

#import "TBSimpleBar.h"

@class TBTabBar, TBTabBarItem;

typedef NS_ENUM(NSInteger, TBTabBarLayoutOrientation) {
    TBTabBarLayoutOrientationHorizontal,
    TBTabBarLayoutOrientationVertical
};

NS_ASSUME_NONNULL_BEGIN

@protocol TBTabBarDelegate <NSObject>

@optional

- (void)tabBar:(TBTabBar *)tabBar didSelectItem:(TBTabBarItem *)item;

@end

@interface TBTabBar : TBSimpleBar

/** @brief Items to display. */
@property (weak, nonatomic, nullable) NSArray <TBTabBarItem *> *items;

/** @brief When a tab is not selected, its tint color. Default is 0.6 white. */
@property (strong, nonatomic, null_resettable) UIColor *defaultTintColor UI_APPEARANCE_SELECTOR;

/** @brief When a tab is selected, its tint color. Default is nil. */
@property (strong, nonatomic, nullable) UIColor *selectedTintColor UI_APPEARANCE_SELECTOR;

/** @brief Dots tint color. Default equals to the tab bar's tint color. */
@property (strong, nonatomic, null_resettable) UIColor *dotTintColor UI_APPEARANCE_SELECTOR;

/** @brief The currently selected tab index. */
@property (assign, nonatomic) NSUInteger selectedIndex;

/** @brief Additional area around content. Affects the size of the tab bar. Default is UIEdgeInsetsZero. */
@property (assign, nonatomic) UIEdgeInsets contentInsets UI_APPEARANCE_SELECTOR;

/** @brief The space between tabs. Default is 4pt. */
@property (nonatomic) CGFloat spaceBetweenTabs;

@property (weak, nonatomic, nullable) id <TBTabBarDelegate> delegate;

@property (assign, nonatomic, readonly) TBTabBarLayoutOrientation layoutOrientation;

/** @brief Returns YES whenever layout orientation is vertical */
@property (assign, nonatomic, readonly, getter = isVertical) BOOL vertical;

- (instancetype)initWithLayoutOrientation:(TBTabBarLayoutOrientation)layoutOrientation;

@end

NS_ASSUME_NONNULL_END
