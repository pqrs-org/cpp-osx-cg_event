#include "test_event_factory.h"

#import <AppKit/AppKit.h>
#import <IOKit/hidsystem/IOLLEvent.h>

CGEventRef pqrs_test_create_aux_control_button_event(uint16_t value) {
  return pqrs_test_create_aux_control_button_event_with_type(value, 0);
}

CGEventRef pqrs_test_create_aux_control_button_event_with_type(uint16_t value, uint8_t event_type) {
  auto data1 = (static_cast<NSInteger>(value) << 16) | (static_cast<NSInteger>(event_type) << 8);

  auto event = [NSEvent otherEventWithType:NSEventTypeSystemDefined
                                  location:NSZeroPoint
                             modifierFlags:0
                                 timestamp:0
                              windowNumber:0
                                   context:nil
                                   subtype:NX_SUBTYPE_AUX_CONTROL_BUTTONS
                                     data1:data1
                                     data2:0];
  if (!event) {
    return nullptr;
  }

  auto cg_event = [event CGEvent];
  if (!cg_event) {
    return nullptr;
  }

  return reinterpret_cast<CGEventRef>(const_cast<void*>(CFRetain(cg_event)));
}
