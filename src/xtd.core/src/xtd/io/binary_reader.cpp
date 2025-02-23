#include "../../../include/xtd/io/binary_reader.h"
#include "../../../include/xtd/io/end_of_stream_exception.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/bit_converter.h"

using namespace std;
using namespace xtd;
using namespace xtd::io;

binary_reader::binary_reader(const ustring& path) : stream_(new ifstream(path, ios::binary)), delete_when_destroy_(true) {
  if (path.trim(' ').length() == 0 || path.index_of_any(io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (!file::exists(path)) throw file_not_found_exception(csf_);
}

binary_reader::binary_reader(istream& stream) : stream_(&stream) {
}

binary_reader::~binary_reader() {
  if (delete_when_destroy_ && stream_) {
    if (dynamic_cast<ifstream*>(stream_)) static_cast<ifstream*>(stream_)->close();
    delete stream_;
  }
}

optional<reference_wrapper<istream>> binary_reader::base_stream() const {
  return stream_ ? optional<reference_wrapper<istream>>(*stream_) : optional<reference_wrapper<istream>>();
}

bool binary_reader::end_of_stream() const {
  return peek_char() == EOF;
}

void binary_reader::close() {
  if (stream_ && dynamic_cast<ifstream*>(stream_)) static_cast<ifstream*>(stream_)->close();
  if (delete_when_destroy_ && stream_) delete stream_;
  stream_ = nullptr;
}

int32_t binary_reader::peek_char() const {
  if (!stream_) return EOF;
  int32_t value = stream_->peek();
  return value;
}

int32_t binary_reader::read() {
  if (!stream_) return EOF;
  int32_t value = stream_->get();
  return value;
}

size_t binary_reader::read(std::vector<byte_t>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw argument_exception(csf_);
  for (auto i = 0U; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<byte_t>(current);
  }
  return count;
}

size_t binary_reader::read(std::vector<char>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw argument_exception(csf_);
  for (auto i = 0U; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<char>(current);
  }
  return count;
}

bool binary_reader::read_boolean() {
  return bit_converter::to_boolean(read_bytes(sizeof(bool)), 0);
}

byte_t binary_reader::read_byte() {
  return read_bytes(sizeof(byte_t))[0];
}

std::vector<byte_t> binary_reader::read_bytes(size_t count) {
  vector<byte_t> result(count);
  if (read(result, 0, count) != count)
    throw end_of_stream_exception(csf_);
  return result;
}

char binary_reader::read_char() {
  return read_bytes(sizeof(char))[0];
}

std::vector<char> binary_reader::read_chars(size_t count) {
  vector<char> result(count);
  if (read(result, 0, count) != count)
    throw end_of_stream_exception(csf_);
  return result;
}

double binary_reader::read_double() {
  return bit_converter::to_double(read_bytes(sizeof(double)), 0);
}

int16_t binary_reader::read_int16() {
  return bit_converter::to_int16(read_bytes(sizeof(int16_t)), 0);
}

int32_t binary_reader::read_int32() {
  return bit_converter::to_int32(read_bytes(sizeof(int32_t)), 0);
}

int64_t binary_reader::read_int64() {
  return bit_converter::to_int16(read_bytes(sizeof(int64_t)), 0);
}

sbyte_t binary_reader::read_sbyte() {
  return read_bytes(sizeof(sbyte_t))[0];
}

float binary_reader::read_single() {
  return bit_converter::to_single(read_bytes(sizeof(float)), 0);
}

ustring binary_reader::read_string() {
  int32_t length = read_int32();
  return ustring(read_chars(length).data(), static_cast<size_t>(length));
}

uint16_t binary_reader::read_uint16() {
  return bit_converter::to_int16(read_bytes(sizeof(int16_t)), 0);
}

uint32_t binary_reader::read_uint32() {
  return bit_converter::to_int32(read_bytes(sizeof(int32_t)), 0);
}

uint64_t binary_reader::read_uint64() {
  return bit_converter::to_int16(read_bytes(sizeof(int64_t)), 0);
}
