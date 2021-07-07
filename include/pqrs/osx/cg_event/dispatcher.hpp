#pragma once

// (C) Copyright Takayama Fumihiko 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See http://www.boost.org/LICENSE_1_0.txt)

#include <CoreGraphics/CoreGraphics.h>
#include <pqrs/cf/cf_ptr.hpp>

namespace pqrs {
namespace osx {
namespace cg_event {
class dispatcher final {
public:
  dispatcher(void) {
    if (auto s = CGEventSourceCreate(kCGEventSourceStateHIDSystemState)) {
      source_ = s;
      CFRelease(s);
    }
  }

private:
  pqrs::cf::cf_ptr<CGEventSourceRef> source_;
};
} // namespace cg_event
} // namespace osx
} // namespace pqrs
