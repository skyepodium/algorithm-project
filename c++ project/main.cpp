#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

    int n;
    cin>>n;
    
    while(n--){
        int a;
        cin>>a;
        int arr[a];
 
        int temp;
        float sum = 0;
        for(int i=0; i<a; i++){
            cin>>temp;
            arr[i] = temp;
            sum = sum+arr[i];
        }
        
        float average = sum/(float)a;
        
        float count = 0;
        for(int i=0; i<a; i++){
            if(arr[i]>average){
                count = count+1;
            }
        }
        
        float result;
        result = count/a*100;
        printf("%.3f", result);
        cout<<"%"<<endl;
    }
    
}

