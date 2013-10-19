#pragma once

namespace Amulet {

  template <typename TIterator>
  class IteratorRange
  {
  public:

    using iterator = TIterator;
    using const_iterator = iterator;
    using value_type = typename std::iterator_traits<iterator>::value_type;
    using reference = typename std::iterator_traits<iterator>::reference;
    using const_reference = reference;
    using difference_type = typename std::iterator_traits<iterator>::difference_type;
    using size_type = typename std::make_unsigned<difference_type>::type;

    IteratorRange() = default;

    IteratorRange(iterator begin, iterator end) :
      mBegin(begin), mEnd(end)
    {
    }

    auto begin() const
    {
      return mBegin;
    }
    auto end() const
    {
      return mEnd;
    }
    auto cbegin() const
    {
      return begin();
    }
    auto cend() const
    {
      return end();
    }

    const_reference at(size_type pos) const
    {
      if (pos >= size())
        throw std::out_of_range("Amulet::IteratorRange");
      return *(mBegin + pos);
    }

    const_reference operator[](size_type pos) const
    {
      return *(mBegin + pos);
    }

    size_type size() const
    {
      return mEnd - mBegin;
    }

    bool empty() const
    {
      return size() == 0;
    }

  private:

    iterator mBegin, mEnd;
  };

}