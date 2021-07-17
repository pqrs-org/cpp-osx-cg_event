#import "AppDelegate.h"
#include <pqrs/osx/cg_event.hpp>

@interface AppDelegate ()

@property(weak) IBOutlet NSWindow* window;

@end

@implementation AppDelegate

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication {
  return YES;
}

- (IBAction)click0x0:(id)sender {
  pqrs::osx::cg_event::mouse::post_single_click(CGPointZero, kCGMouseButtonLeft);
}

@end
