#include <boost/ut.hpp>
#include <pqrs/osx/cg_event.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "mouse_down_event_type"_test = [] {
    expect(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(0)) == kCGEventLeftMouseDown);
    expect(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(1)) == kCGEventRightMouseDown);
    expect(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(2)) == kCGEventOtherMouseDown);
    expect(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(3)) == kCGEventOtherMouseDown);
    expect(pqrs::osx::cg_event::mouse::mouse_down_event_type(CGMouseButton(4)) == kCGEventOtherMouseDown);
  };

  "mouse_up_event_type"_test = [] {
    expect(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(0)) == kCGEventLeftMouseUp);
    expect(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(1)) == kCGEventRightMouseUp);
    expect(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(2)) == kCGEventOtherMouseUp);
    expect(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(3)) == kCGEventOtherMouseUp);
    expect(pqrs::osx::cg_event::mouse::mouse_up_event_type(CGMouseButton(4)) == kCGEventOtherMouseUp);
  };

  return 0;
}
