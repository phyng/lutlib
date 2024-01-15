#include <iostream>
#include "rust/cxx.h"

#include "bridge.h"

#include "vendor/lut.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "vendor/stb_image_write.h"

BridgeClient::BridgeClient() {}

std::unique_ptr<BridgeClient> new_bridge_client() {
  return std::unique_ptr<BridgeClient>(new BridgeClient());
}

rust::String BridgeClient::apply_lut(rust::String r_lut_path, rust::String r_image_path, rust::String r_output_path) const {

  std::string lut_path = std::string(r_lut_path);
  std::string image_path = std::string(r_image_path);
  std::string output_path = std::string(r_output_path);

  auto lut = octoon::image::lut::parse(lut_path);

  int width, height, channels;
  auto *img = stbi_load(image_path.c_str(), &width, &height, &channels, 3);

  if (img == nullptr)
  {
      return "error:image_not_found";
  }

  for (int j = 0; j < height; j++)
  {
      for (int i = 0; i < width; i++)
      {
          auto *px = img + (j * width + i) * 3;

          auto data = lut.lookup(px[0], px[1], px[2]);

          px[0] = data[0];
          px[1] = data[1];
          px[2] = data[2];
      }
  }


  stbi_write_jpg(output_path.c_str(), width, height, 3, img, width * 3);

  stbi_image_free(img);

  return "success:ok";
}
