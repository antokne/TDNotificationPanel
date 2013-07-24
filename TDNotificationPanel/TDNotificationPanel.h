// TDNotificationPanel.h
// Version 0.2
// Created by Tom Diggle 08.02.2013

/**
 * Copyright (c) 2013, Tom Diggle
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum {
    TDNotificationModeText,
    TDNotificationModeProgressBar
} TDNotificationMode;

typedef enum {
    TDNotificationTypeError,
    TDNotificationTypeMessage,
    TDNotificationTypeSuccess,
} TDNotificationType;

@interface TDNotificationPanel : UIView

/**
 * The notification type that will be used to determine the color of the background & icon.
 *
 * @see TDNotificationType
 */
@property (nonatomic, assign) TDNotificationType notificationType;

/**
 * The notification operation mode. The default is TDNotificationModeText.
 *
 * @see TDNotificationMode
 */
@property (nonatomic, assign) TDNotificationMode notificationMode;

/**
 * A short message to be displayed. If the text is too long it will get clipped by displaying "..." at the end. If set to nil no title is displayed.
 */
@property (nonatomic, copy) NSString *titleText;

/**
 * Font to be used for the title. Default is system bold font.
 */
@property (nonatomic, copy) UIFont *titleFont;

/**
 * A message to be displayed underneath the title. If set to nil no subtitle is displayed.
 */
@property (nonatomic, copy) NSString *subtitleText;

/**
 * Font to be use for the subtitle. Default is system font.
 */
@property (nonatomic, copy) UIFont *subtitleFont;

/**
 * The progress of the progress bar, from 0.0 to 1.0. Defaults to 0.0.
 *
 * @see notificationMode
 */
@property (nonatomic, assign) float progress;

//@property (nonatomic, strong) UIProgressView *progressIndicator;

/**
 * When set to YES notification will be dismissable when tapped. When set to NO notification will only be able to be dismissed using hideNotificationInView:animated method. Default is YES.
 */
@property (nonatomic, assign, getter = isDismissable) BOOL dismissable;

/**
 * Initializes a new notification, adds it to the provided view, shows it and then removes it after the delay given.
 *
 * @param view The view that the notification will be added to.
 * @param title The title that will be displayed.
 * @param subtitle The subtitle that will be displayed under the title.
 * @param type The notification type.
 * @param mode The notification mode.
 * @param dismissable The notification is dismissable by tapping.
 * @param delay The delay in seconds before the notification will be removed.
 *
 * @return A reference to the created notification.
 *
 * @see TDNotificationType
 * @see TDNotificationMode
 */
+ (instancetype)showNotificationInView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissable:(BOOL)dismissable hideAfterDelay:(NSTimeInterval)delay;

/**
 * Hides the top-most notification in the view provided.
 *
 * @param view The view that the notification will be removed from.
 * 
 * @return YES if notification is hidden, NO otherwise.
 *
 * @see showNotificationInView:animated:
 */
+ (BOOL)hideNotificationInView:(UIView *)view;

/**
 * Returns an array of notifications in the view provided.
 *
 * @param view The view that will be searched for notifications.
 *
 * @return An array of notifications for the view provided, or nil if none exists.
 */
+ (NSArray *)notificationsInView:(UIView *)view;

/**
 * Initializes a new notification.
 *
 * @param view The view instance that will provided the bounds for the notification.
 * @param title The title that will be displayed.
 * @param subtitle The subtitle that will be displayed under the title.
 * @param type The notification type.
 * @param mode The notification mode.
 * @param dismissable The notification is dismissable by tapping.
 *
 * @see notificationtype
 * @see notificationMode
 * @see dismissable
 */
- (id)initWithView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissable:(BOOL)dismissable;

/**
 * Displays the notification.
 */
- (void)show;

/**
 * Hides the notification.
 */
- (void)hide;

/**
 * Hides the notification after a delay.
 *
 * @param delay Delay in seconds until the notification if hidden.
 */
- (void)hideAfterDelay:(NSTimeInterval)delay;

@end
