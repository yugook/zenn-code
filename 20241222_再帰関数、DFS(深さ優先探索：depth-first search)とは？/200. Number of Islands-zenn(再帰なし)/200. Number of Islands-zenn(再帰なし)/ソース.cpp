#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;  // ��̃O���b�h����

        int landsCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // 4�����ړ��p�̃x�N�g�� (�㉺���E)
        std::vector<std::pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

        for (int c = 0; c < rows; c++) {
            for (int r = 0; r < cols; r++) {
                if (grid[c][r] == '1') {  // �V�������𔭌�
                    landsCount++;

                    // �X�^�b�N���g���������IDFS
                    std::stack<std::pair<int, int>> stack;
                    stack.push({ c, r });
                    grid[c][r] = '0';  // �K��ς݂Ƃ��ă}�[�N

                    while (!stack.empty()) {
                        std::pair<int, int> current = stack.top();
                        stack.pop();
                        int curC = current.first;
                        int curR = current.second;

                        for (auto dir : directions) {
                            int newC = curC + dir.first;
                            int newR = curR + dir.second;

                            // ���E�����Ɩ��K��`�F�b�N
                            if (newC >= 0 && newC < rows && newR >= 0 && newR < cols && grid[newC][newR] == '1') {
                                stack.push({ newC, newR });
                                grid[newC][newR] = '0';  // �K��ς݂Ƃ��ă}�[�N
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
    std::cout << s.numIslands(a) << std::endl;  // �o��: 2

    return 0;
}
