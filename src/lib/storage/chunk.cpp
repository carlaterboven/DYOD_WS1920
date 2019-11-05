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
  for (size_t curSeg = 0; curSeg < _segments.size(); curSeg++) {
    _segments[curSeg]->append(values.at(curSeg));
  }
}

std::shared_ptr<BaseSegment> Chunk::get_segment(ColumnID column_id) const {
  return _segments.at(column_id);
}

uint16_t Chunk::column_count() const {
  return static_cast<uint16_t>(_segments.size());
}

uint32_t Chunk::size() const {
  if(_segments.empty()) return 0;
  return static_cast<uint32_t>(_segments.front()->size());
}

}  // namespace opossum
