#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <time.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    
    int array[n][n];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>array[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=(i+1); j<n; j++){
            
            int temp;
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
            
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j != n-1){
                cout<<array[i][j]<<" ";
            }else{
                cout<<array[i][j];
            }
        }
        cout<<endl;
    }
    
}

