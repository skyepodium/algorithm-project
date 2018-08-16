#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> bi_pattern;
vector<int> result;

void int_to_bi(int num){
    
    vector<int> v;
    while(num>0){
        v.push_back(num%2);
        num = num/2;
    }
    if(v.size() < 6){
        for(int i=0; i<6-v.size(); i++){
            v.push_back(0);
        }
    }
    for(int i=5; i>=0; i--){
        bi_pattern.push_back(v[i]);
        cout << v[i] <<" ";
    }
//    cout << endl;
}

char ch_to_bi(char ch){
    char num;
    
    if(ch >= 65) num = ch - 65;
    else if(ch >= 48) num = ch + 4;
    else if(ch == 43) num = 62;
    else num = 63;
    
    return num;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        bi_pattern.clear();
        string word;
        cin >> word;
        
        string bi_word;
        vector<int> num_word;
        for(int i=0; i<word.size(); i++){
            num_word.push_back(ch_to_bi(word[i]));
        }
        
        for(int i=0; i<num_word.size(); i++){
//            cout << num_word[i] << endl;
            int_to_bi(num_word[i]);
        }
        
        cout << endl;
        cout << endl;
        for(int i=0; i<bi_pattern.size(); i++){
            cout << bi_pattern[i] << " ";
        }
        cout << endl;
        
        /*
         
        int count = 0;
        int num = 0;
        for(int i=((int)bi_pattern.size()-1); i>=0; i--){
            num = num + bi_pattern[i]*pow(2, count);
            count++;
            if(count >7){
                result.push_back(num);
                cout << num << endl;
                
                count = 0;
                num = 0;
            }
        }
        */
        
//        cout << result.size() << endl;
        for(int i=0; i<result.size(); i++){
//            cout << result[i] << endl;
        }
    }
    return 0;
}
