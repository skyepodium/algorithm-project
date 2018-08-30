#include <iostream>
#include <algorithm>

#define max_val 1000001

using namespace std;

int n, m, input;

int a[100001];

bool binary_search(int num){
    
    int start = 0;
    int end = n;
    int mid = 0;
    while(start <= end){
        
        mid = (start + end)/2;
        
        if(a[mid] == num) return true;
        else if(num < a[mid]) end = mid - 1;
        else start = mid + 1;
    }
    
    return false;
}

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    
    cin >> m;
    for(int i=0; i<m; i++){
        scanf("%d", &input);
        printf("%d\n", binary_search(input));
    }
    
}
