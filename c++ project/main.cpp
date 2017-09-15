#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
    int a[7] = {22, 21, 24, 20, 18, 25, 23};
    
    int max = a[0];
    int index=0;
    for(int i=1; i<7; i++){
        
        if(a[i]%2 == 0){
            if(max<a[i]){
                max = a[i];
                index = i;
            }
        }
    }
    cout<<max<<endl;
    cout<<index<<endl;
}
