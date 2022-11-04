#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string reverseVowels(string s) {
        // 1. init
        vector<char> vowels;
        set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        // 2. find vowels
        for (auto c : s) {
            if (vowelSet.find(c) != vowelSet.end()) {
                vowels.push_back(c);
            }
        }

        // 3. reverse vowels
        int i = 0;
        int j = vowels.size() - 1;
        while (i < j) {
            swap(vowels[i], vowels[j]);
            i++;
            j--;
        }

        // 4. replace vowels
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowelSet.find(s[i]) != vowelSet.end()) {
                s[i] = vowels[k];
                k++;
            }
        }

        return s;
    }
};