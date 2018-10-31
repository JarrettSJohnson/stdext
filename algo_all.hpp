#include <algorithm>
#include <iostream>
#include <vector>

namespace stdext {

namespace {

template <class InputIt, class T>

inline auto

_emplace_and_step(InputIt it, InputIt end, std::vector<T> &vec) {
  if (it != end) {
    vec.emplace_back(*it++);
  }
  return it;
}

};

/*
 * @brief: Finds all elements in the range [first, last) that specifies specific criteria
 * @first/last: The range of elements to examine
 * @value: The value to compare the elements to
 * @return: An std::vector<T> of elements that equal value
 */

template <class InputIt, class T>

auto

find_all(InputIt first, InputIt last, const T &value) {
  std::vector<T> vec;
  while (first != last) {
    first = std::find(first, last, value);
    first = _emplace_and_step(first, last, vec);
  }
  return vec;
}

/*
 * @brief: Finds all elements in a container that specifies specific criteria
 * @container: Container of elements to examine
 * @value: The value to compare the elements to
 * @return: An std::vector<T> of elements that equal value
 * Note: Container must have begin and end iterators
 */

template <class Container, class T>

auto

find_all(const Container &container, const T &value) {
  return find_all(container.begin(), container.end(), value);
}

/*
 * @brief: Finds all elements in the range [first, last) that specifies specific criteria
 * @first/last: The range of elements to examine
 * @p: The unary predicate which returns true for the required element
 * @return: An std::vector<T> of elements that equal value
 */

// STD::FIND_IF
template <class InputIt, class UnaryPredicate>

auto

find_all_if(InputIt first, InputIt last, UnaryPredicate p) {
  std::vector<typename InputIt::value_type> vec;
  while (first != last) {
    first = std::find_if(first, last, p);
    first = _emplace_and_step(first, last, vec);
  }
  return vec;
}

/*
 * @brief: Finds all elements in a container that specifies specific criteria
 * @container: Container of elements to examine
 * @value: The value to compare the elements to
 * @return: An std::vector<T> of elements that equal value
 * Note: Container must have begin and end iterators
 */

template <class Container, class UnaryPredicate>

auto

find_all_if(const Container &container, UnaryPredicate p) {
  return find_all_if(container.begin(), container.end(), p);
}

/*
 * @brief: Finds all elements in the range [first, last) that specifies specific criteria
 * @first/last: The range of elements to examine
 * @p: The unary predicate which returns true for the required element
 * @return: An std::vector<T> of elements that equal value
 */

// STD::FIND_IF_NOT
template <class InputIt, class UnaryPredicate>

auto

find_all_if_not(InputIt first, InputIt last, UnaryPredicate p) {
  std::vector<typename InputIt::value_type> vec;
  while (first != last) {
    first = std::find_if_not(first, last, p);
    first = _emplace_and_step(first, last, vec);
  }
  return vec;
}

/*
 * @brief: Finds all elements in a container that specifies specific criteria
 * @container: Container of elements to examine
 * @value: The value to compare the elements to
 * @return: An std::vector<T> of elements that equal value
 * Note: Container must have begin and end iterators
 */

template <class Container, class UnaryPredicate>

auto

find_all_if_not(const Container &container, UnaryPredicate p) {
  return find_all_if_not(container.begin(), container.end(), p);
}

}; // namespace stdext
