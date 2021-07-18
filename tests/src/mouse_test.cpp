#include <catch2/catch.hpp>

#include <pqrs/osx/cg_event.hpp>

TEST_CASE("mouse_down_event_type") {
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(0)) == kCGEventLeftMouseDown);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(1)) == kCGEventRightMouseDown);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(2)) == kCGEventOtherMouseDown);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(3)) == kCGEventOtherMouseDown);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(4)) == kCGEventOtherMouseDown);
}

TEST_CASE("mouse_up_event_type") {
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(0)) == kCGEventLeftMouseUp);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(1)) == kCGEventRightMouseUp);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(2)) == kCGEventOtherMouseUp);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(3)) == kCGEventOtherMouseUp);
  REQUIRE(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(4)) == kCGEventOtherMouseUp);
}
