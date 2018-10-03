#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>

#define max_int 100001

using namespace std;

int t;
char word[max_int];
vector<int> bit_pattern;

void make_bit(int num){
    
    int cnt = 0;
    while(num>0){
        bit_pattern.push_back(num%2);
        num = num/2;
        cnt++;
    }
    
    for(int i=0; i<6-cnt; i++){
        bit_pattern.push_back(0);
    }
}

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        memset(word, 0, sizeof(word));
        bit_pattern.clear();
        
        scanf("%s", word);
        int size = (int)strlen(word);
        
        vector<int> idx;
        for(int i=0; i<size; i++){
            if(word[i] == '+') idx.push_back(62);
            else if(word[i] == '/') idx.push_back(63);
            else if(word[i] >=65 && word[i] <=90) idx.push_back(word[i]-65);
            else if(word[i] >=97 && word[i] <=122) idx.push_back(word[i]-71);
            else idx.push_back(word[i]+4);
        }
        
        for(int i=(int)idx.size()-1; i>=0; i--){
            make_bit(idx[i]);
        }
        
        printf("#%d ", test_case);
        int cnt = 7;
        int num = 0;
        for(int i=(int)bit_pattern.size()-1; i>=0; i--){
            
//            cout << bit_pattern[i];
            num = num + pow(2, cnt)*bit_pattern[i];
            cnt--;
            if(cnt == -1){
                printf("%c", num);
                cnt = 7;
                num = 0;
            }
        }
        printf("\n");
        
    }
    
    return 0;
}

