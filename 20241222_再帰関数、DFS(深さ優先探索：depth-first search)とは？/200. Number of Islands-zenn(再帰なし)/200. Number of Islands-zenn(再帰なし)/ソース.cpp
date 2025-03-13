#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;  // 空のグリッド処理

        int landsCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // 4方向移動用のベクトル (上下左右)
        std::vector<std::pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

        for (int c = 0; c < rows; c++) {
            for (int r = 0; r < cols; r++) {
                if (grid[c][r] == '1') {  // 新しい島を発見
                    landsCount++;

                    // スタックを使った反復的DFS
                    std::stack<std::pair<int, int>> stack;
                    stack.push({ c, r });
                    grid[c][r] = '0';  // 訪問済みとしてマーク

                    while (!stack.empty()) {
                        std::pair<int, int> current = stack.top();
                        stack.pop();
                        int curC = current.first;
                        int curR = current.second;

                        for (auto dir : directions) {
                            int newC = curC + dir.first;
                            int newR = curR + dir.second;

                            // 境界条件と未訪問チェック
                            if (newC >= 0 && newC < rows && newR >= 0 && newR < cols && grid[newC][newR] == '1') {
                                stack.push({ newC, newR });
                                grid[newC][newR] = '0';  // 訪問済みとしてマーク
                            }
                        }
                    }
                }
            }
        }

        return landsCount;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> a = {
        {'0','1','0','0','0'},
        {'1','1','1','0','0'},
        {'0','1','0','0','0'},
        {'0','0','0','1','0'},
    };
    std::cout << s.numIslands(a) << std::endl;  // 出力: 2

    return 0;
}
