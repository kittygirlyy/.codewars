#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <cmath>

struct Position {
    int x, y;

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }

    bool operator<(const Position& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

struct PositionHash {
    std::size_t operator()(const Position& pos) const {
        return std::hash<int>()(pos.x) ^ std::hash<int>()(pos.y);
    }
};

int path_finder(std::string maze) {
    std::vector<std::vector<int>> arr;
    std::stringstream ss(maze);
    std::string line;

    while (std::getline(ss, line)) {
        std::vector<int> row;
        for (char ch : line) {
            row.push_back(ch - '0');
        }
        arr.push_back(row);
    }

    int rows = arr.size();
    int cols = arr[0].size();
    Position start = {0, 0};
    Position finish = {rows - 1, cols - 1};
    std::vector<std::pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    std::priority_queue<std::pair<int, Position>, std::vector<std::pair<int, Position>>, std::greater<>> pq;
    std::unordered_map<Position, int, PositionHash> memory;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_cost, cur_pos] = pq.top();
        pq.pop();

        if (memory.find(cur_pos) != memory.end() && memory[cur_pos] <= cur_cost) {
            continue;
        }
        memory[cur_pos] = cur_cost;

        if (cur_pos == finish) {
            break;
        }

        for (const auto& [dx, dy] : neighbors) {
            Position tmp_pos = {cur_pos.x + dx, cur_pos.y + dy};

            if (tmp_pos.x >= 0 && tmp_pos.x < rows && tmp_pos.y >= 0 && tmp_pos.y < cols) {
                int tmp_cost = std::abs(arr[tmp_pos.x][tmp_pos.y] - arr[cur_pos.x][cur_pos.y]);

                if (memory.find(tmp_pos) != memory.end() && memory[tmp_pos] <= tmp_cost + cur_cost) {
                    continue;
                }
                pq.push({tmp_cost + cur_cost, tmp_pos});
            }
        }
    }

    return memory[finish];
}
