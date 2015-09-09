#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result = 0;
        int mask = 1;
        int r0 = 0;
        int r1 = 0;
        vector<int>ret;
        vector<int>::iterator iter = nums.begin();

        for (; iter != nums.end(); ++iter) {
            result ^= *iter;
        }

        while (0 == (result & 1)) {
            result >>= 1;
            mask <<= 1;
        }

        for (iter = nums.begin(); iter != nums.end(); ++iter) {
            if (mask & *iter) {
                r0 ^= *iter;
            }
            else {
                r1 ^= *iter;
            }
        }

        ret.push_back(r0);
        ret.push_back(r1);

        return ret;
    }
};

int main()
{
    vector<int> in;
    vector<int> out;

    in.push_back(1);
    in.push_back(1);
    in.push_back(2);
    in.push_back(-3);
    in.push_back(1024);
    in.push_back(16);
    in.push_back(1024);
    in.push_back(16);

    Solution s;
    out = s.singleNumber(in);

    vector<int>::iterator iter = out.begin();
    for (; iter != out.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
