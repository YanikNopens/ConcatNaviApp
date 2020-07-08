//
//  MRMapViewController.h
//  Meridian
//
//  Copyright (c) 2016 Aruba Networks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Meridian/MRMapView.h>
#import <Meridian/MREditorKey.h>
#import <Meridian/MRDSheetSearchProtocols.h>

@protocol MRDAnnotationTableDataSource;
@class MRDBottomSheetViewController;

NS_ASSUME_NONNULL_BEGIN

/**
 Ability to provide information for the map annotation details. The sheet has a
 tableview that can be filled with information the way the implementor needs. A
 tableview is provided for registering cells and other direct manipulation. This
 is the tableview inside the sheet for the details of that placemark.
 */
__attribute__((deprecated("since version 6.0", "subclass MRDBottomSheetAbstractController")))
@protocol MRDMapViewControllerDelegate

@optional
/**
 A chance to supply a datasource for the sheet's tableview for a map annotation.

 @param tableview The tableview that is in the sheet. Allows ability to register 
 cells and deselect if necessary.
 @param placemark The placemark data of the annotation selected.
 @return A UITableDataSource compliant with MRDAnnotationTableDataSource.
 */
- (id<MRDAnnotationTableDataSource>)dataSourceForTableView:(UITableView *)tableview
                                             withPlacemark:(MRPlacemark *)placemark;
@end

typedef void (^MRAddSheetCompletion)(MRDBottomSheetViewController *__nullable addedSheet);

/**
 * A view controller implementing `MRMapViewDelegate` that handles all essential `MRMapView` tasks and events.
 */
@interface MRMapViewController : UIViewController <MRMapViewDelegate, MRDSheetSearchDelegate>

/// The map view this controller is responsible for.
@property (nonatomic, strong) MRMapView *mapView;

/// If set, this controller will initiate directions to the specified destination as soon as the map view is displayed.
@property (nullable, nonatomic, strong) MRPlacemark *pendingDestination;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
/// Provides the data and actions related to the placemark annotation sheet.
@property (nullable, nonatomic, strong) id<MRDMapViewControllerDelegate> sheetDelegate;
#pragma clang diagnostic pop

/// Allow for silencing no route found alerts.
/// Default value is `NO`
@property (nonatomic, assign) BOOL silenceNoRouteFoundAlerts;

/// Automatically index all placemarks after they've been loaded
/// Default value is `YES` if `disableCoreSpotlightIndexing` is `NO` on
/// your `MRConfig`
/// Default value is `YES` if `disableHapticFeedback` is `NO` on
/// your `MRConfig`
@property (nonatomic, assign) BOOL shouldIndexAnnotations;

/// Always show a search card in the map view controller.  Defaults to NO.
@property (nonatomic, assign) BOOL displaysSearchSheet;

/// Set the initial default route to be Accessible.  Defaults to NO.
@property (nonatomic, assign) BOOL useAccessiblePathsDefault;

/// Set this to always show the provided sheet unless it's displaying selected content or directions are active.
@property (nullable, nonatomic, strong) MRDBottomSheetAbstractController *persistentSheet;

/**
 A convenient initializer to add an associated editor key along with instantiation.

 @param key An instance of MREditorKey
 @return An instance of a MRMapViewController
 */
- (_Nullable instancetype)initWithEditorKey:(MREditorKey *)key;

/**
 A convenient initializer to add an associated editor key along with instantiation.
 
 @param key An instance of MREditorKey
 @param isChild tells the view controller it should be treated as being inside
 a subview as a child view controller. This will manipulate the style of the sheet
 so it does not slide up from the bottom but appears over the subview itself.
 @return An instance of a MRMapViewController
 */
- (_Nullable instancetype)initWithEditorKey:(MREditorKey *)key
                      isChildViewController:(BOOL)isChild;

/**
 * Begins directions to the given Placemark from the user's current location.
 *
 * @param placemark  The destination for the route.
 */
- (void)startDirectionsToPlacemark:(MRPlacemark *)placemark;

/**
 * Begins directions to the given friend from the user's current location.
 *
 * @param friend_  The destination for the route.
 */
- (void)startDirectionsToFriend:(MRFriend *)friend_;

/**
 * Begins directions from one given Placemark to another.
 *
 * @param placemark  The destination for the route.
 * @param fromPlacemark  The starting point for the route.
 */
- (void)startDirectionsToPlacemark:(MRPlacemark *)placemark
                     fromPlacemark:(MRPlacemark * _Nullable)fromPlacemark;

/**
 * Adds a bottom sheet with the provided child as a child view controller. will remove any existing floating sheet.
 * Uses sheetController's isExpandable and isFloatable properties to determine sheet functionality.
 * @param completion Called after the sheet is shown. If the sheet is not shown, nil is passed to the completion block.
 */
- (void)addSheetWithDetailController:(MRDBottomSheetAbstractController *)sheetController
                            animated:(BOOL)animated
                          completion:(nullable MRAddSheetCompletion)completion;

/**
* Removes any sheet managed by MRMapViewController.
* @param animated Should the sheet removal be animated.
* @param completion Called after the viewController is removed from the view hierarchy. It's called immediately if there's
*  no bottom sheet to remove.
*/
- (void)removeSheet:(BOOL)animated completion:(void (^__nullable)(void))completion;

/// Zooms the map view to the selected annotation.
/// @param annotation An annotation target.
- (void)zoomToAnnotation:(id<MRAnnotation>)annotation;

/**
 * In an MRDBottomSheetViewController, shows the provided annotations in a list.
 * @param annotations Annotations to show in the bottom sheet.
 */
- (void)showAnnotationsInBottomSheet:(NSArray<MRAnnotation> *)annotations;

/**
 * Called after addSheetWithDetailController:animated:completion is called and MRMapViewController is showing a bottom
 * sheet view controller.
 * @param currentSheetController The sheet currently being displayed by the map view controller.
 * @param incomingSheetController The sheet that would replace the currentSheetController if this method returns YES.
 * @return whether incoming should replace current. If YES, currentSheetController is replaced by incomingSheetController.
 * If NO, nothing happens.
 */
- (BOOL)shouldReplaceSheet:(MRDBottomSheetAbstractController *)currentSheetController
                      with:(MRDBottomSheetAbstractController *)incomingSheetController;

@end


/**
 * Convenience methods for presenting directions.
 */
@interface UIViewController (Directions)

/**
 * Presents directions modally.
 *
 * @param placemark  The destination for the route.
 */
- (void)presentDirectionsToPlacemark:(MRPlacemark *)placemark;

/**
 * Present directions modally
 * @param placemark The destinantion for the route
 * @param accessible Whether the initial default route will be an accessible route (YES) or the shortest route (NO)
 */
- (void)presentDirectionsToPlacemark:(MRPlacemark *)placemark withAccessibleRoute:(BOOL)accessible;
@end

NS_ASSUME_NONNULL_END
