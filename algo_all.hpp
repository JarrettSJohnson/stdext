#include <algorithm>
#include <iostream>
#include <vector>

namespace stdext {

namespace {

template <class InputIt, class T>

inline auto

emplace_and_step(InputIt it, InputIt end, std::vector<T> &vec) {
  if (it != end) {
    vec.emplace_back(*it);
    it++;
  }
  return it;
}

};

// STD::FIND
template <class InputIt, class T>

auto

find_all(InputIt first, InputIt last, const T &value) {
  std::vector<T> vec;
  while (first != last) {
    first = std::find(first, last, value);
    first = emplace_and_step(first, last, vec);
  }
  return vec;
}

template <class Container, class T>

auto

find_all(const Container &container, const T &value) {
  return find_all(container.begin(), container.end(), value);
}

// STD::FIND_IF
template <class InputIt, class UnaryPredicate>

auto

find_all_if(InputIt first, InputIt last, UnaryPredicate p) {
  std::vector<typename InputIt::value_type> vec;
  while (first != last) {
    first = std::find_if(first, last, p);
    first = emplace_and_step(first, last, vec);
  }
  return vec;
}

template <class Container, class UnaryPredicate>

auto

find_all_if(const Container &container, UnaryPredicate p) {
  return find_all_if(container.begin(), container.end(), p);
}

// STD::FIND_IF_NOT
template <class InputIt, class UnaryPredicate>

auto

find_all_if_not(InputIt first, InputIt last, UnaryPredicate p) {
  std::vector<typename InputIt::value_type> vec;
  while (first != last) {
    first = std::find_if_not(first, last, p);
    first = emplace_and_step(first, last, vec);
  }
  return vec;
}

template <class Container, class UnaryPredicate>

auto

find_all_if_not(const Container &container, UnaryPredicate p) {
  return find_all_if_not(container.begin(), container.end(), p);
}

}; // namespace algoall
