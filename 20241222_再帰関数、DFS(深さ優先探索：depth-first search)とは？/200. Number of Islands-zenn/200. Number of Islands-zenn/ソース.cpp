#include <iostream>
#include <vector>

class Solution {
private:
    void dfs(std::vector<std::vector<char>>& grid, int col, int row)
    {
        if (col < 0 || row < 0 || grid.size() <= col || grid[col].size() <= row || grid[col][row] == '0')
            return;

        grid[col][row] = '0';

        dfs(grid, col - 1, row); // ã
        dfs(grid, col, row + 1); // ‰E
        dfs(grid, col + 1, row); // ‰º
        dfs(grid, col, row - 1); // ¶
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int landsCount = 0;
        for (int c = 0; c < grid.size(); c++)
        {
            for (int r = 0; r < grid[c].size(); r++)
            {
                if (grid[c][r] == '1')
                {
                    landsCount++;
                    dfs(grid, c, r);
                }
            }
        }
        return landsCount;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> a;

    a = {
        {'0','1','0','0','0'},
        {'1','1','1','0','0'},
        {'0','1','0','0','0'},
        {'0','0','0','1','0'},
    };
    std::cout << s.numIslands(a) << std::endl;

    return 0;
}