#include <iostream>
#include <vector>
#include <algorithm>

long nextBigger(long n) {
    std::string str = std::to_string(n);
    int len = str.length();
    
    std::vector<char> d(str.begin(), str.end());

    int p = -1;
    for (int i = len - 1; i > 0; i--) {
        if (d[i] > d[i - 1]) {
            p = i - 1;
            break;
        }
    }

    if (p == -1) return -1;

    std::vector<char> right(d.begin() + p, d.end());

    char pv = right[0];
    right.erase(right.begin());

    char mm = 0;
    int mmi = -1;
    for (int i = 0; i < right.size(); i++) {
        if (right[i] > pv) {
            if (mm == 0 || right[i] < mm) {
                mm = right[i];
                mmi = i;
            }
        }
    }

    if (mmi == -1) return -1;

    right.erase(right.begin() + mmi);

    right.push_back(pv);

    std::sort(right.begin(), right.end());

    std::string result(d.begin(), d.begin() + p);
    result.push_back(mm);
    result.append(right.begin(), right.end());

    long ret = std::stol(result);
    if (ret <= n) return -1;

    return ret;
}
