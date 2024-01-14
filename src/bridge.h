#pragma once
#include <memory>
#include "rust/cxx.h"

class BridgeClient {
public:
  BridgeClient();

  rust::String apply_lut(rust::String lut_path, rust::String image_path, rust::String output_path) const;
};

std::unique_ptr<BridgeClient> new_bridge_client();
