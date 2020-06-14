#include <iostream>
#include <string>
#define max_int 100001
#define base_num 65536
using namespace std;

int check_a[max_int], check_b[max_int], duple_cnt=0, total_cnt;

int min(int a, int b){
    return a < b ? a: b;
}

int max(int a, int b){
    return a > b ? a : b;
}

bool is_character(char ch){
    
    bool result = false;
    
    if((ch >= 65 && ch <=90) || (ch>=97 && ch<=122)) result = true;
    
    return result;
}

char to_uppercase(char ch){
    char result = 'a';
    
    if(ch >= 97) result = ch - 32;
    else result = ch;

    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    string a, b;
    
    for(int i=0; i<(int)str1.size() - 1; i++){
        
        char first_ch = str1[i];
        char second_ch = str1[i+1];
        
        if(is_character(first_ch) && is_character(second_ch)){
            int num = to_uppercase(first_ch) * 100 + to_uppercase(second_ch);
            check_a[num]++;
        }
    }
    
    for(int i=0; i<(int)str2.size() - 1; i++){
        char first_ch = str2[i];
        char second_ch = str2[i+1];
        
        if(is_character(first_ch) && is_character(second_ch)){
            int num = to_uppercase(first_ch) * 100 + to_uppercase(second_ch);
            check_b[num]++;
        }
    }
    
    for(int i=6565; i<=9090; i++){
        total_cnt += max(check_a[i], check_b[i]);
        
        duple_cnt += min(check_a[i], check_b[i]);
    }
    
    if(total_cnt != 0){
        double jaccard = (double)duple_cnt / (double)total_cnt;
        answer = (int)(base_num * jaccard);
    }
    else{
        answer = 65536;
    }
    
    return answer;
}

int main(){
    cout << solution("E=M*C^2", "e=m*c^2") << endl;
}
