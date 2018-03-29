#include <iostream>
#include <algorithm>

using namespace std;

long long int a[1000001];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    sort(a, a+n);
    
    long long int current_cnt = 1;
    long long int max_cnt = 1;
    long long int result = a[0];
    
    for(int i=1; i<n; i++){
        if(a[i] == a[i-1]){
            current_cnt++;
        }else{
            current_cnt = 1;
        }
        
        if(max_cnt < current_cnt){
            max_cnt = current_cnt;
            result = a[i];
        }
    }
    
    cout << result << endl;
    
}
