#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        // Œ³‚Ìtriangle‚ð‰ó‚³‚È‚¢‚½‚ß
        std::vector<std::vector<int>> copyTriangle(triangle.size());
        std::copy(triangle.begin(), triangle.end(), copyTriangle.begin());

        // DPˆ—
        for (int row = copyTriangle.size() - 2; row >= 0; row--)
        {
            for (int column = 0; column < copyTriangle.at(row).size(); column++)
            {
                copyTriangle.at(row).at(column) += std::min(copyTriangle.at(row + 1).at(column), copyTriangle.at(row + 1).at(column + 1));
            }
        }
        return copyTriangle[0][0];
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> a;
    a = {
        {-1},
        {5,4},
        {1,-1,-3},
    };
    std::cout << s.minimumTotal(a) << std::endl;

	return 0;
}