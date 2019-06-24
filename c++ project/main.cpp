#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[26];
string name, result;
vector<string> v;


bool cmp(const string &a, const string &b){
    return a[0] < b[0];
}

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        cin >> name;
        v.push_back(name);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int cur = v[0][0];
    int cnt = 1;
    bool flag = false;
    for(int i=1; i<(int)v.size(); i++){
        if(cur != v[i][0]){
            if(cnt >= 5){
                result += cur;
            }
            cur = v[i][0];
            cnt = 1;
        }else{
            if(i == v.size() - 1) flag = true;
            cnt++;
        }
    }
    if(flag && cnt >= 5)  result += cur;
    if(result.size() > 0) cout << result << endl;
    else cout << "PREDAJA" << endl;
}
