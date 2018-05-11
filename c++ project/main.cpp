#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int ar1[100001];
int ar2[100001];

bool bsearch(int start, int end, int key){
    
    if(start > end){
        return false;
    }
    
    int mid = (start + end) / 2;
    
    if(ar1[mid] == key) return true;
    else if(ar1[mid] < key) return bsearch(mid+1, end, key);
    else return bsearch(start, mid-1, key);
    
}



int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> ar1[i];
    }
    
    sort(ar1, ar1+n);
    
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        cout << bsearch(0, n-1,  num) << endl;
    }
    
}
