#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define max_int 502

using namespace std;

int check[max_int];
int cnt = 0;

struct info {
    int num;
    double ratio;
};

vector<info> result;

bool cmp(const info &a, const info &b){
    if(a.ratio == b.ratio) return a.num < b.num;
    else return a.ratio > b.ratio;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    cnt = (int)stages.size();
    
    for(int i=0; i<cnt; i++){
        int num = stages[i];
        check[num]++;
    }
    
    for(int i=1; i<=N; i++){
        double ratio;
        if(check[i] != 0) ratio = (double)((double)check[i]/(double)cnt);
        else ratio = 0;
        
        result.push_back({i, ratio});
        cnt -= check[i];
    }
    
    sort(result.begin(), result.end(), cmp);
    
    for(int i=0; i<result.size(); i++){
        cout << result[i].num << " " << result[i].ratio << endl;
        answer.push_back(result[i].num);
    }
    
    return answer;
}
