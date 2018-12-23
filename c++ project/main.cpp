#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> result;
string word;
int main(){
    cin >> word;
    for(int i=0; i<(int)word.size(); i++){
        string temp;
        for(int j=i; j<(int)word.size(); j++){
            temp += word[j];
        }
        result.push_back(temp);
    }
    sort(result.begin(), result.end());
    for(int i=0; i<(int)result.size(); i++){
        printf("%s\n", result[i].c_str());
    }
}
