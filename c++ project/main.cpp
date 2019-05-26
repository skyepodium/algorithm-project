#include <iostream>
#include <vector>
#include <cmath>
#define max_int 2147483647
using namespace std;

int n;
vector<int> pick;
vector<int> result;
void go(int idx){

    if(idx == 20){
        
        int num = 0;
        for(int i=0; i<(int)pick.size(); i++){
            num += pow(3, pick[i]);
        }
        result.push_back(num);
        
        return;
    }
    
    pick.push_back(idx);
    go(idx+1);
    pick.pop_back();
    
    go(idx+1);
}

int main(){
    scanf("%d", &n);
    
    go(0);
    
    bool flag = false;
    for(int i=0; i<(int)result.size(); i++){
        if(result[i] == n){
            flag = true;
            break;
        }
    }
    
    if(n == 0) flag = false;
    
    if(flag){
        printf("YES");
    }else{
        printf("NO");
    }
    
}
