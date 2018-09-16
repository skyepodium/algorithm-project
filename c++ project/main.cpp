#include <iostream>

using namespace std;

bool check[1001];
int a[101];
int n;

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
    check[1] = true;
    for(int i=2; i*i<1001; i++){
        for(int j=i*i; j<1001; j=j+i){
            check[j] = true;
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(check[a[i]] == false){
            cnt++;
        }
    }
    
    cout << cnt << endl;
}
