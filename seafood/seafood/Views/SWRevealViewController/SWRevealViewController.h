#import <UIKit/UIKit.h>

@class SWRevealViewController;
@protocol SWRevealViewControllerDelegate;

#pragma mark - SWRevealViewController Class

typedef NS_ENUM( NSInteger, FrontViewPosition)
{
    FrontViewPositionLeftSideMostRemoved,
    FrontViewPositionLeftSideMost,
    FrontViewPositionLeftSide,
	FrontViewPositionLeft,
	FrontViewPositionRight,
	FrontViewPositionRightMost,
    FrontViewPositionRightMostRemoved,
    
};

typedef NS_ENUM(NSInteger, SWRevealToggleAnimationType)
{
    SWRevealToggleAnimationTypeSpring,    // <- produces a spring based animation
    SWRevealToggleAnimationTypeEaseOut,   // <- produces an ease out curve animation
};


@interface SWRevealViewController : UIViewController

/* Basic API */

// Object instance init and rear view setting
- (id)initWithRearViewController:(UIViewController *)rearViewController frontViewController:(UIViewController *)frontViewController;

// Rear view controller, can be nil if not used
@property (nonatomic) UIViewController *rearViewController;
- (void)setRearViewController:(UIViewController *)rearViewController animated:(BOOL)animated;

// Optional right view controller, can be nil if not used
@property (nonatomic) UIViewController *rightViewController;
- (void)setRightViewController:(UIViewController *)rightViewController animated:(BOOL)animated;

// Front view controller, can be nil on initialization but must be supplied by the time the view is loaded
@property (nonatomic) UIViewController *frontViewController;
- (void)setFrontViewController:(UIViewController *)frontViewController animated:(BOOL)animated;

- (void)pushFrontViewController:(UIViewController *)frontViewController animated:(BOOL)animated;

@property (nonatomic) FrontViewPosition frontViewPosition;
- (void)setFrontViewPosition:(FrontViewPosition)frontViewPosition animated:(BOOL)animated;

- (IBAction)revealToggle:(id)sender;
- (IBAction)rightRevealToggle:(id)sender; // <-- simetric implementation of the above for the rightViewController

- (void)revealToggleAnimated:(BOOL)animated;
- (void)rightRevealToggleAnimated:(BOOL)animated; // <-- simetric implementation of the above for the rightViewController

- (UIPanGestureRecognizer*)panGestureRecognizer;

- (UITapGestureRecognizer*)tapGestureRecognizer;

@property (nonatomic) CGFloat rearViewRevealWidth;
@property (nonatomic) CGFloat rightViewRevealWidth;
@property (nonatomic) CGFloat rearViewRevealOverdraw;
@property (nonatomic) CGFloat rightViewRevealOverdraw;
@property (nonatomic) CGFloat rearViewRevealDisplacement;
@property (nonatomic) CGFloat rightViewRevealDisplacement;
@property (nonatomic) CGFloat draggableBorderWidth;
@property (nonatomic) BOOL bounceBackOnOverdraw;
@property (nonatomic) BOOL bounceBackOnLeftOverdraw;
@property (nonatomic) BOOL stableDragOnOverdraw;
@property (nonatomic) BOOL stableDragOnLeftOverdraw;
@property (nonatomic) BOOL presentFrontViewHierarchically;
@property (nonatomic) CGFloat quickFlickVelocity;
@property (nonatomic) NSTimeInterval toggleAnimationDuration;
@property (nonatomic) SWRevealToggleAnimationType toggleAnimationType;
@property (nonatomic) CGFloat springDampingRatio;
@property (nonatomic) NSTimeInterval replaceViewAnimationDuration;
@property (nonatomic) CGFloat frontViewShadowRadius;
@property (nonatomic) CGSize frontViewShadowOffset;
@property (nonatomic) CGFloat frontViewShadowOpacity;
@property (nonatomic) UIColor *frontViewShadowColor;
@property (nonatomic) BOOL clipsViewsToBounds;
@property (nonatomic) BOOL extendsPointInsideHit;
@property (nonatomic,weak) id<SWRevealViewControllerDelegate> delegate;

@end


#pragma mark - SWRevealViewControllerDelegate Protocol

typedef enum
{
    SWRevealControllerOperationNone,
    SWRevealControllerOperationReplaceRearController,
    SWRevealControllerOperationReplaceFrontController,
    SWRevealControllerOperationReplaceRightController,
    
} SWRevealControllerOperation;


@protocol SWRevealViewControllerDelegate<NSObject>

@optional

- (void)revealController:(SWRevealViewController *)revealController willMoveToPosition:(FrontViewPosition)position;
- (void)revealController:(SWRevealViewController *)revealController didMoveToPosition:(FrontViewPosition)position;

- (void)revealController:(SWRevealViewController *)revealController animateToPosition:(FrontViewPosition)position;

- (BOOL)revealControllerPanGestureShouldBegin:(SWRevealViewController *)revealController;

- (BOOL)revealControllerTapGestureShouldBegin:(SWRevealViewController *)revealController;

- (BOOL)revealController:(SWRevealViewController *)revealController
    panGestureRecognizerShouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer;

- (BOOL)revealController:(SWRevealViewController *)revealController
    tapGestureRecognizerShouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer;

- (void)revealControllerPanGestureBegan:(SWRevealViewController *)revealController;
- (void)revealControllerPanGestureEnded:(SWRevealViewController *)revealController;

- (void)revealController:(SWRevealViewController *)revealController panGestureBeganFromLocation:(CGFloat)location progress:(CGFloat)progress overProgress:(CGFloat)overProgress;
- (void)revealController:(SWRevealViewController *)revealController panGestureMovedToLocation:(CGFloat)location progress:(CGFloat)progress overProgress:(CGFloat)overProgress;
- (void)revealController:(SWRevealViewController *)revealController panGestureEndedToLocation:(CGFloat)location progress:(CGFloat)progress overProgress:(CGFloat)overProgress;

- (void)revealController:(SWRevealViewController *)revealController willAddViewController:(UIViewController *)viewController
    forOperation:(SWRevealControllerOperation)operation animated:(BOOL)animated;
- (void)revealController:(SWRevealViewController *)revealController didAddViewController:(UIViewController *)viewController
    forOperation:(SWRevealControllerOperation)operation animated:(BOOL)animated;

- (id<UIViewControllerAnimatedTransitioning>)revealController:(SWRevealViewController *)revealController
    animationControllerForOperation:(SWRevealControllerOperation)operation fromViewController:(UIViewController *)fromVC toViewController:(UIViewController *)toVC;

- (void)revealController:(SWRevealViewController *)revealController panGestureBeganFromLocation:(CGFloat)location progress:(CGFloat)progress; // (DEPRECATED)
- (void)revealController:(SWRevealViewController *)revealController panGestureMovedToLocation:(CGFloat)location progress:(CGFloat)progress; // (DEPRECATED)
- (void)revealController:(SWRevealViewController *)revealController panGestureEndedToLocation:(CGFloat)location progress:(CGFloat)progress; // (DEPRECATED)
@end


#pragma mark - UIViewController(SWRevealViewController) Category

@interface UIViewController(SWRevealViewController)

- (SWRevealViewController*)revealViewController;

@end


#pragma mark - StoryBoard support Classes

extern NSString* const SWSegueRearIdentifier;  // this is @"sw_rear"
extern NSString* const SWSegueFrontIdentifier; // this is @"sw_front"
extern NSString* const SWSegueRightIdentifier; // this is @"sw_right"

@interface SWRevealViewControllerSegueSetController : UIStoryboardSegue
@end

@interface SWRevealViewControllerSeguePushController : UIStoryboardSegue
@end

