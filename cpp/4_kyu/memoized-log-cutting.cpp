#include <iostream>
#include <vector>
#include <algorithm>

int cut_log(const std::vector<int>& p, int n) {
    if (n == 0) {
        return 0;
    }

    std::vector<int> prices(n + 1, 0);

    for (std::vector<int>::size_type j = 0; j < p.size(); ++j) {
        if (j + 1 <= n) {
            prices[j + 1] = p[j];
        }
    }
    for (int j = 0; j <= n; ++j) {
        for (int i = 0; i <= n - j; ++i) {
            int small_board = i + j;
            if (small_board <= n && prices[small_board] < p[i] + prices[j]) {
                prices[small_board] = p[i] + prices[j];
            }
        }
    }
    return prices[n];
}
