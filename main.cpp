#include "algo_all.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <cassert>

int main(){
  std::array myArr{ 1, 2, 3, 4, 4, 4, 5, 4, 4, 5, 6, -1 };
  auto all = stdext::find_all(myArr.begin(), myArr.end(), 4);
  auto all2 = stdext::find_all(myArr, 4);
  assert(all.size() == 5);
  assert(all2.size() == 5);

  auto all_if_even = stdext::find_all_if(myArr.begin(), myArr.end(), [](auto i){ return i % 2 == 0;});
  auto all_if_even2 = stdext::find_all_if(myArr, [](auto i){ return i % 2 == 0;});
  assert(all_if_even.size() == 7);
  assert(all_if_even2.size() == 7);

  auto all_if_odd = stdext::find_all_if_not(myArr.begin(), myArr.end(), [](auto i){ return i % 2 == 0;});
  auto all_if_odd2 = stdext::find_all_if_not(myArr, [](auto i){ return i % 2 == 0;});
  assert(all_if_odd.size() == 5);
  assert(all_if_odd2.size() == 5);

  return 0;
}
