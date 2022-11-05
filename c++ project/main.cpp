#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }

        return a.second > b.second;
    }
};

class Solution {
   public:
    int mostFrequentEven(vector<int>& nums) {
        // 1. init
        unordered_map<int, int> map;

        // 2. count
        for (auto num : nums) {
            if (num & 1 == 1) continue;
            map[num]++;
        }

        // 3. sort
        vector<pair<int, int>> v(map.begin(), map.end());
        sort(v.begin(), v.end(), cmp());

        // 4. return
        return v.size() > 0 ? v[0].first : -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 4, 4, 9, 2, 4};
    cout << s.mostFrequentEven(nums) << endl;
    return 0;
}