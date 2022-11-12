#include <string>

using namespace std;

class Solution {
   public:
    string decimalToBase(int num, int base) {
        string res = "";
        while (num > 0) {
            res += to_string(num % base);
            num /= base;
        }
        return res;
    }

    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++) {
            // 1. base convertor
            string s = decimalToBase(n, i);

            // 2. two pointer
            int l = 0, r = s.size() - 1;
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
        }
        return true;
    }
};