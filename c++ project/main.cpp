#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct position{
    int x;
    int y;
};

bool cmp(const position &a, const position &b){
 
    if(a.x == b.x){
        
        return a.y < b.y;
    }else{
        return a.x < b.x;
    }
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    vector<position> position_list(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &position_list[i].x, &position_list[i].y);
    }
    
    sort(position_list.begin(), position_list.end(), cmp);
    
    for(int i=0; i<n; i++){
        printf("%d %d\n", position_list[i].x, position_list[i].y);
    }
    
    
}
