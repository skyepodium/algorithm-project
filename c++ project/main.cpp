#include <iostream>
#include <algorithm>

#define max_val 500001

using namespace std;

//시간 복잡도: O(mlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: 이분 탐색
//사용한 자료구조: 1차원 배열

int n, m, input;
int d[max_val];

bool binary_search(int num){
    
    int start = 0;
    int end = n;
    int mid = 0;
    
    while(start <= end){
        
        mid = (start + end)/2;
        
        if(d[mid] == num) return true;
        else if(num < d[mid]) end = mid - 1;
        else start = mid + 1;
    }
    
    return false;
}

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &d[i]);
    
    sort(d, d+n);
    
    cin >> m;
    for(int i=0; i<m; i++){
        scanf("%d", &input);
        printf("%d ", binary_search(input));
    }
    cout << endl;
    
}
