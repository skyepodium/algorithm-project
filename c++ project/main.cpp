#include <iostream>
#include <cstring>
#include <vector>

#define max_int 10

using namespace std;

int t;

char num[max_int];
char rev_num[max_int];
vector<int> result;

void do_reverse(){
    
    int size = (int)strlen(num);
    
    for(int i=0; i<size; i++){
        rev_num[i] = num[size-i-1];
    }
}

void do_sum(){
    
    int size = (int)strlen(num);
    
    bool plus = false;
    for(int i=size-1; i>=0; i--){
        int sum_num = num[i] - '0' + rev_num[i] - '0';
        if(plus){
            sum_num += 1;
            plus = false;
        }

        if(sum_num > 9){
            plus = true;
            result.push_back(sum_num-10);
        }
        else{
            result.push_back(sum_num);
        }
        
        if(i == 0 && plus) result.push_back(1);
    }
}

int main(){
    scanf("%d", &t);
    
    while(t--){
        result.clear();
        scanf("%s", num);
        
        do_reverse();
        do_sum();

        bool is_ok = true;
        int size = (int)result.size();
        for(int i=0; i<size/2; i++){
            if(result[i] != result[size-i-1]){
                is_ok = false;
                break;
            }
        }
        
        if(is_ok) printf("YES\n");
        else printf("NO\n");


    }
    
    
}
