#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b){
    
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
    
    
    int n;
    cin>>n;
    
    while(n--){

        int num;
        cin>>num;
        
        int ar[num];
        for(int i=0; i<num; i++){
            cin>>ar[i];
        }
        
        
        int total = 0;
        for(int i=0; i<num-1; i++){
            for(int j=i+1; j<num; j++){
                total+=gcd(ar[i], ar[j]);
            }
        }
        cout<<total<<endl;

    }
}
