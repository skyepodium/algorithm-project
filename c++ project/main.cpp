#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cur_num = 0;
string val = "";
int val_size = 0;

vector<string> arr;

int val_max[11];

vector<string> v[11];

void go(int idx, string cur){
    
    if(idx == val_size) {
        if(cur.size() == cur_num) {
            arr.push_back(cur);
        }
        return;
    }
    
    go(idx + 1, cur + val[idx]);
    
    go(idx + 1, cur);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i<course.size(); i++) {
        cur_num = course[i];
        
        for(int j=0; j<orders.size(); j++){
            
            sort(orders[j].begin(), orders[j].end());
            val = orders[j];
            val_size = (int)val.size();
            go(0, "");
        }
    }
    
    sort(arr.begin(), arr.end());

    string pre = "";
    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        string cur = arr[i];
        int cur_size = (int)cur.size();
        if(pre != cur) {
            
            pre = cur;
            cnt = 1;
        }else{
            cnt++;
        }
        
        if(val_max[cur_size] < cnt) {
            val_max[cur_size] = cnt;
            v[cur_size].clear();
            v[cur_size].push_back(cur);
        } else if(val_max[cur_size] == cnt){
            v[cur_size].push_back(cur);
        }
    }
    
    for(int i=0; i<11; i++){
        for(int j=0; j<v[i].size(); j++){
            
//            cout << val_max[i] << endl;
//            cout << v[i][j] << endl;
//            cout << endl;
            
            if(val_max[i] > 1) {
                answer.push_back(v[i][j]);
            }
        }
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}


int main () {
    
    vector<string> result;
    
    vector<string> orders;
    vector<int> course;
    
//    orders.push_back("ABCFG");
//    orders.push_back("AC");
//    orders.push_back("CDE");
//    orders.push_back("ACDE");
//    orders.push_back("BCFG");
//    orders.push_back("ACDEH");
//
//    course.push_back(2);
//    course.push_back(3);
//    course.push_back(4);
    
//    orders.push_back("ABCDE");
//    orders.push_back("AB");
//    orders.push_back("CD");
//    orders.push_back("ADE");
//    orders.push_back("XYZ");
//    orders.push_back("XYZ");
//    orders.push_back("ACD");
//
//    course.push_back(2);
//    course.push_back(3);
//    course.push_back(5);
    
    orders.push_back("XYZ");
    orders.push_back("XWY");
    orders.push_back("XWA");

    course.push_back(2);
    course.push_back(3);
    course.push_back(4);

    result = solution(orders, course);
    
    cout << endl;
    cout << endl;
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
}
