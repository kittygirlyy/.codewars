// https://www.codewars.com/kata/515f51d438015969f7000013
#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> pyramid(std::size_t n) {
      std::vector<std::vector<int>> result;
    for (int i = 1; i <= n; ++i) {
        std::vector<int> r(i, 1);
        result.push_back(r);
    }
    return result;
}
