#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//시간 복잡도: O(2^n)
//공간 복잡도: O(n)
//사용한 알고리즘: 재귀 함수, 백트래킹
//사용한 자료구조: 1차원 배열, 1차원 벡터

using namespace std;

bool check[10];
int n = 0;
vector<int> v;

long long int max_num = 0;
long long int min_num = 9223372036854775807;

long long int convert_li(string num){
    
    long long int result = 0;
    
    int size = (int)num.size();
    for(int i=0; i<size; i++){
        result = result*10 + (num[i]-48);
    }
    
    return result;
}

void vector_to_int(vector<int> &pick){
    
    string num;
    
    for(int i=0; i<n; i++){
        num = num + to_string(pick[i]);
    }
    
    long long int result = convert_li(num);
    
    if(result > max_num) max_num = result;
    if(result < min_num) min_num = result;
}

void go(int cnt, vector<int> &pick){
    
    if(cnt == n){
        
        vector_to_int(pick);
        
        return;
    }
    
    for(int i=0; i<n; i++){
        if(check[i] == false){
            check[i] = true;
            pick.push_back(v[i]);
            go(cnt+1, pick);
            check[i] = false;
            pick.pop_back();
        }
    }
    
}

int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        check[i] = false;
    }
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    vector<int> pick;
    go(0, pick);
    
    cout << max_num << endl;
    cout << min_num << endl;
    
    cout << max_num + min_num << endl;
}

