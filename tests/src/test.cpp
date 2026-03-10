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

  "make_aux_control_button"_test = [] {
    expect(pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::keyboard_or_keypad,
                                                        pqrs::hid::usage::keyboard_or_keypad::keyboard_volume_up) ==
           std::optional<pqrs::osx::cg_event::aux_control_button::value_t>(pqrs::osx::cg_event::aux_control_button::sound_up));

    expect(pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::consumer,
                                                        pqrs::hid::usage::consumer::scan_next_track) ==
           std::optional<pqrs::osx::cg_event::aux_control_button::value_t>(pqrs::osx::cg_event::aux_control_button::next));

    expect(pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::apple_vendor_keyboard,
                                                        pqrs::hid::usage::apple_vendor_keyboard::brightness_up) ==
           std::optional<pqrs::osx::cg_event::aux_control_button::value_t>(pqrs::osx::cg_event::aux_control_button::brightness_up));

    expect(pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::apple_vendor_top_case,
                                                        pqrs::hid::usage::apple_vendor_top_case::illumination_toggle) ==
           std::optional<pqrs::osx::cg_event::aux_control_button::value_t>(pqrs::osx::cg_event::aux_control_button::illumination_toggle));
  };

  "make_key_code"_test = [] {
    expect(pqrs::osx::cg_event::make_key_code(pqrs::hid::usage_page::keyboard_or_keypad,
                                              pqrs::hid::usage::keyboard_or_keypad::keyboard_a) ==
           std::optional<pqrs::osx::cg_event::key_code::value_t>(pqrs::osx::cg_event::key_code::keyboard_a));

    expect(pqrs::osx::cg_event::make_key_code(pqrs::hid::usage_page::consumer,
                                              pqrs::hid::usage::consumer::voice_command) ==
           std::optional<pqrs::osx::cg_event::key_code::value_t>(pqrs::osx::cg_event::key_code::consumer_voice_command));

    expect(pqrs::osx::cg_event::make_key_code(pqrs::hid::usage_page::apple_vendor_keyboard,
                                              pqrs::hid::usage::apple_vendor_keyboard::spotlight) ==
           std::optional<pqrs::osx::cg_event::key_code::value_t>(pqrs::osx::cg_event::key_code::apple_vendor_keyboard_spotlight));

    expect(pqrs::osx::cg_event::make_key_code(pqrs::hid::usage_page::apple_vendor_top_case,
                                              pqrs::hid::usage::apple_vendor_top_case::keyboard_fn) ==
           std::optional<pqrs::osx::cg_event::key_code::value_t>(pqrs::osx::cg_event::key_code::apple_vendor_top_case_keyboard_fn));

    expect(pqrs::osx::cg_event::make_key_code(pqrs::hid::usage_page::generic_desktop,
                                              pqrs::hid::usage::generic_desktop::do_not_disturb) ==
           std::optional<pqrs::osx::cg_event::key_code::value_t>(pqrs::osx::cg_event::key_code::generic_desktop_do_not_disturb));
  };

  "make_usage_pair"_test = [] {
    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::key_code::keyboard_a) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::keyboard_or_keypad,
                                                                      pqrs::hid::usage::keyboard_or_keypad::keyboard_a)));

    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::key_code::consumer_voice_command) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::consumer,
                                                                      pqrs::hid::usage::consumer::voice_command)));

    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::key_code::apple_vendor_keyboard_spotlight) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::apple_vendor_keyboard,
                                                                      pqrs::hid::usage::apple_vendor_keyboard::spotlight)));

    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::key_code::generic_desktop_do_not_disturb) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::generic_desktop,
                                                                      pqrs::hid::usage::generic_desktop::do_not_disturb)));

    //
    // fn
    //

    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::key_code::apple_vendor_top_case_keyboard_fn) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::apple_vendor_top_case,
                                                                      pqrs::hid::usage::apple_vendor_top_case::keyboard_fn)));

    expect(pqrs::osx::cg_event::make_key_code(pqrs::hid::usage_page::apple_vendor_top_case,
                                              pqrs::hid::usage::apple_vendor_top_case::keyboard_fn) ==
           pqrs::osx::cg_event::make_key_code(pqrs::hid::usage_page::apple_vendor_keyboard,
                                              pqrs::hid::usage::apple_vendor_keyboard::function));
  };

  "make_usage_pair_from_aux_control_button"_test = [] {
    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::aux_control_button::next) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::consumer,
                                                                      pqrs::hid::usage::consumer::scan_next_track)));

    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::aux_control_button::sound_up) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::consumer,
                                                                      pqrs::hid::usage::consumer::volume_increment)));

    expect(pqrs::osx::cg_event::make_usage_pair(pqrs::osx::cg_event::aux_control_button::brightness_up) ==
           std::optional<pqrs::hid::usage_pair>(pqrs::hid::usage_pair(pqrs::hid::usage_page::consumer,
                                                                      pqrs::hid::usage::consumer::display_brightness_increment)));

    expect(pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::keyboard_or_keypad,
                                                        pqrs::hid::usage::keyboard_or_keypad::keyboard_volume_up) ==
           pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::consumer,
                                                        pqrs::hid::usage::consumer::volume_increment));

    expect(pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::apple_vendor_top_case,
                                                        pqrs::hid::usage::apple_vendor_top_case::brightness_up) ==
           pqrs::osx::cg_event::make_aux_control_button(pqrs::hid::usage_page::apple_vendor_keyboard,
                                                        pqrs::hid::usage::apple_vendor_keyboard::brightness_up));
  };

  return 0;
}
