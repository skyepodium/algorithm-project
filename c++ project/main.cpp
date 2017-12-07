#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
bool check[1001];

void eratos(int a){
    for(int i=2; i*i<=a; i++){
        for(int j=i*i; j<=a; j=j+i){
            check[j] = false;
        }
    }
}

int main() {

    check[1] = false;
    for(int i=2; i<=1001; i++){
        check[i] = true;
    }
    
    int n;
    scanf("%d", &n);

    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    eratos(1001);

    for(int i=0; i<n; i++){
        if(check[v[i]]){
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
}

