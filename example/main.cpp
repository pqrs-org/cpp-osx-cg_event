#include <chrono>
#include <iostream>
#include <pqrs/osx/cg_event.hpp>
#include <thread>

int main(void) {
  auto position = pqrs::osx::cg_event::mouse::cursor_position();
  std::cout << "x " << position.x << " y " << position.y << std::endl;

  pqrs::osx::cg_event::mouse::post_single_click(position, kCGMouseButtonLeft);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  pqrs::osx::cg_event::mouse::post_double_click(position, kCGMouseButtonLeft);

  return 0;
}
