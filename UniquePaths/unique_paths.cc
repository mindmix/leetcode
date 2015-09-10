#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[m][n];
        int i, j;

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                map[i][j] = 0;
            }
        }

        map[0][0] = 1;
        
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                map[i][j] += (i - 1 >= 0 ? map[i - 1][j] : 0) + (j - 1 >= 0 ? map[i][j - 1] : 0);
            }
        }

        return map[m - 1][n - 1];
    }
};

int main()
{
    Solution s;

    cout << s.uniquePaths(4, 5) << endl;

    return 0;
}

