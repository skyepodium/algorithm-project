#include <iostream>
#include <vector>
#include <algorithm>
#define max_int 9
using namespace std;

int a[max_int];
vector<int> pick;
bool flag = false;
void go(int idx){
    
    if(idx == max_int){
        if((int)pick.size() == 7){
            int result = 0;
            vector<int> temp;
            for(int i=0; i<7; i++){
                result += pick[i];
                temp.push_back(pick[i]);
            }
            if(result == 100 && !flag){
                flag = true;
                sort(temp.begin(), temp.end());
                for(int i=0; i<7; i++){
                    printf("%d\n", temp[i]);
                }
            }
        }
        return;
    }
    
    pick.push_back(a[idx]);
    go(idx + 1);
    pick.pop_back();
    
    go(idx + 1);
}

int main(){
    for(int i=0; i<max_int; i++){
        scanf("%d", &a[i]);
    }
    
    go(0);
    
}
