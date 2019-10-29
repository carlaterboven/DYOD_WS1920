#include <iomanip>
#include <iterator>
#include <limits>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

#include "base_segment.hpp"
#include "chunk.hpp"

#include "utils/assert.hpp"

namespace opossum {

void Chunk::add_segment(std::shared_ptr<BaseSegment> segment) {
  _segments.push_back(segment);
}

void Chunk::append(const std::vector<AllTypeVariant>& values) {
  DebugAssert(values.size() == column_count(), "Incorrect number of columns.");
  for(size_t current_segment = 0; current_segment < column_count(); current_segment++) {
    _segments.at(current_segment)->append(values.at(current_segment));
  }
}

std::shared_ptr<BaseSegment> Chunk::get_segment(ColumnID column_id) const {
  // Implementation goes here
  return nullptr;
}

uint16_t Chunk::column_count() const {
  return static_cast<uint16_t>(_segments.size());
}

uint32_t Chunk::size() const {
  if(_segments.empty()) return 0;
  return static_cast<uint32_t>(_segments.front()->size());
}

}  // namespace opossum
