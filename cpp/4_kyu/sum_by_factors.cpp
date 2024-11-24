#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iostream>

class SumOfDivided {
public:
    static std::string sumOfDivided(std::vector<int> &lst);

private:
    static int simple_abs(int num);
    static std::vector<int> generate_primes(int largest);
    static std::vector<std::pair<int, int>> sum_for_list(const std::vector<int> &lst);
};

int SumOfDivided::simple_abs(int num) {
    return (num < 0) ? -num : num;
}

std::vector<int> SumOfDivided::generate_primes(int largest) {
    std::vector<int> primes;
    for (int count = 2; count <= largest; ++count) {
        bool isprime = true;
        for (int x = 2; x <= std::sqrt(count); ++x) {
            if (count % x == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            primes.push_back(count);
        }
    }
    return primes;
}

std::vector<std::pair<int, int>> SumOfDivided::sum_for_list(const std::vector<int> &lst) {
    if (lst.empty()) return {};

    std::vector<int> abs_value_lst;
    for (int num : lst) {
        abs_value_lst.push_back(simple_abs(num));
    }

    int largest = *std::max_element(abs_value_lst.begin(), abs_value_lst.end());
    if (largest < 2) return {}; // No primes less than 2

    std::vector<int> primes = generate_primes(largest);

    std::vector<std::pair<int, int>> sum_list;
    for (int prime : primes) {
        int sum = 0;
        for (int num : lst) {
            if (num % prime == 0) {
                sum += num;
            }
        }
        if (sum != 0) {
            sum_list.push_back({prime, sum});
        }
    }
    return sum_list;
}

std::string SumOfDivided::sumOfDivided(std::vector<int> &lst) {
    std::vector<std::pair<int, int>> sum_list = sum_for_list(lst);
    std::ostringstream oss;
    for (const auto &pair : sum_list) {
        oss << "(" << pair.first << " " << pair.second << ")";
    }
    return oss.str();
}
