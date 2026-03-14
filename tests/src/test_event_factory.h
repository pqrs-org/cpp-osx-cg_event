#pragma once

#include <CoreGraphics/CoreGraphics.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

CGEventRef pqrs_test_create_aux_control_button_event(uint16_t value);
CGEventRef pqrs_test_create_aux_control_button_event_with_type(uint16_t value, uint8_t event_type);

#ifdef __cplusplus
}
#endif
