#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int total_num, find_order;

string result[11] = {"", "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

struct student{
    float score;
    int origin_order;
};

bool cmp(const student &a, const student &b ){
    return a.score > b.score;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        
        vector<student> v;
        cin >> total_num >> find_order;
        for(int i=0; i<total_num; i++){
            float a, b, c;
            cin >> a >> b >> c;
            float score = a*0.35 + b*0.45 + c*0.2;
            v.push_back({score, i});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        float mid_order = 0;
        for(int i=0; i<v.size(); i++){
            if((v[i].origin_order + 1) == find_order){
                mid_order = i+1;
            }
        }
        
        int result_order = mid_order/(total_num/10);
        float d = mid_order/(total_num/10);
        if(d != (int)d){
            result_order++;
        }
        
        
        cout << "#" << test_case << " " << result[result_order] << endl;
        
    }
    return 0;
}

