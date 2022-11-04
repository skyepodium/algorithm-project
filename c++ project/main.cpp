#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string reverseVowels(string s) {
        // 1. init
        vector<int> vowels;
        set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        // 2. find vowels
        for (int i = 0; i < (int)s.size(); i++) {
            if (vowelSet.find(s[i]) != vowelSet.end()) {
                vowels.push_back(i);
            }
        }

        // 3. reverse vowels
        int i = 0;
        int j = vowels.size() - 1;
        while (i < j) {
            swap(s[vowels[i]], s[vowels[j]]);
            i++;
            j--;
        }

        return s;
    }
};

int main() {
    Solution s;
    string str = "hello";
    string res = s.reverseVowels(str);

    cout << res << endl;
    return 0;
}