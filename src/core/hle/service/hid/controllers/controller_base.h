// Copyright 2018 yuzu emulator team
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "common/common_types.h"
#include "common/swap.h"

namespace Core::Timing {
class CoreTiming;
}

namespace Core::HID {
class HIDCore;
}

namespace Service::HID {
class ControllerBase {
public:
    explicit ControllerBase(Core::HID::HIDCore& hid_core_);
    virtual ~ControllerBase();

    // Called when the controller is initialized
    virtual void OnInit() = 0;

    // When the controller is released
    virtual void OnRelease() = 0;

    // When the controller is requesting an update for the shared memory
    virtual void OnUpdate(const Core::Timing::CoreTiming& core_timing, u8* data,
                          std::size_t size) = 0;

    // When the controller is requesting a motion update for the shared memory
    virtual void OnMotionUpdate(const Core::Timing::CoreTiming& core_timing, u8* data,
                                std::size_t size) {}

    void ActivateController();

    void DeactivateController();

    bool IsControllerActivated() const;

    static const std::size_t hid_entry_count = 17;

protected:
    bool is_activated{false};

    Core::HID::HIDCore& hid_core;
};
} // namespace Service::HID
