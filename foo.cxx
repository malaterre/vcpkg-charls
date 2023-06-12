#include <string>
#include <vector>

#include <charls/charls.h>

static std::vector<uint8_t> read_all_bytes(const char *filename) {
  std::vector<uint8_t> result;
  return result;
}

void foo(std::string input)
{
  auto source = read_all_bytes(input.c_str());
  std::vector<uint8_t> destination;

  auto ret = charls::jpegls_decoder::decode(source, destination);
  auto frame_info = ret.first;
  auto interleave_mode = ret.second;

  if (interleave_mode != charls::interleave_mode::None &&
      interleave_mode != charls::interleave_mode::Sample) {
    throw std::invalid_argument("invalid interleave_mode");
  }

  std::vector<uint8_t> destination2 =
      charls::jpegls_encoder::encode(destination, frame_info, interleave_mode);

}

int main()
{
  return 0;
}