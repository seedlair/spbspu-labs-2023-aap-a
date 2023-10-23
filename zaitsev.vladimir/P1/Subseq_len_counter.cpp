#include "Subseq_len_counter.h"
#include <algorithm>
#include <limits>
#include <stdexcept>


zaitsev::Subseq_len_counter::Subseq_len_counter() : beg_element_(0), curr_len_(0), max_len_(0)
{}

unsigned long long zaitsev::Subseq_len_counter::get_max_len()
{
  return std::max(max_len_,curr_len_);
}

void zaitsev::Subseq_len_counter::reset(long long beg_element = 0)
{
  beg_element_ = beg_element;
  curr_len_ = beg_element == 0 ? 0 : 1;
  max_len_ = beg_element == 0 ? 0 : max_len_;
}

void zaitsev::Subseq_len_counter::operator()(long long next_element)
{
  if (next_element == beg_element_)
  {
    if (curr_len_ == std::numeric_limits<unsigned long long>::max())
    {
      throw std::overflow_error("Length of subsequence is too long to put it in the unsigned long long type");
    }
    else
    {
      ++curr_len_;
    }
  }
  else
  {
    reset(next_element);
  }
}
