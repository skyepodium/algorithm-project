#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
string word, first_value, original_value, result;

vector<string> words, a;

string lower_string(string value) {
    string result = "";
    
    for(int i=0; i<value.size(); i++) {
        char cur = value[i];
        if(cur < 97) {
            cur = cur + 32;
        }
        result += cur;
    }
    
    return result;
}

int main() {
    
    while (true) {
        scanf("%d", &n);
        
        if (n == 0) break;
        
        words.clear();
        
        for(int i=0; i<n; i++){
            cin >> word;

            a.push_back(word);
            words.push_back(lower_string(word));
        }
        
        sort(words.begin(), words.end());
        
        first_value = words[0];
        
        for(int i=0; i<(int)a.size(); i++) {
            original_value = a[i];
            
            if (first_value == lower_string(original_value)) {
                result = original_value;
                break;
            }
        }
        
        cout << result << endl;
    }
}
