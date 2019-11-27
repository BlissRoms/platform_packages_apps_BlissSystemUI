/*
 *
 *  Copyright 2019 The Android Open Source Project
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#pragma once

#include <memory>
#include <utility>

#include "hci/address_with_type.h"

namespace bluetooth {
namespace security {
namespace record {

enum BondState { NOT_BONDED, PAIRING, PAIRED, BONDED };

class SecurityRecord {
 public:
  explicit SecurityRecord(hci::AddressWithType device) : device_(device), state_(NOT_BONDED) {}

  /**
   * Returns true if the device is bonded to another device
   */
  bool IsBonded() {
    return state_ == BONDED;
  }

  bool IsPaired() {
    return state_ == PAIRED;
  }

  /**
   * Returns true if a device is currently pairing to another device
   */
  bool IsPairing() {
    return state_ == PAIRING;
  }

  void SetLinkKey(std::array<uint8_t, 16> link_key, hci::KeyType key_type) {
    link_key_ = link_key;
    key_type_ = key_type;
  }

  std::array<uint8_t, 16> GetLinkKey() {
    return link_key_;
  }

  hci::KeyType GetKeyType() {
    return key_type_;
  }

  hci::AddressWithType GetDevice() {
    return device_;
  }

 private:
  const hci::AddressWithType device_;
  BondState state_;
  std::array<uint8_t, 16> link_key_ = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  hci::KeyType key_type_ = hci::KeyType::DEBUG_COMBINATION;
};

}  // namespace record
}  // namespace security
}  // namespace bluetooth
