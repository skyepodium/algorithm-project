#include <iostream>
#include <algorithm>

#define max_val 100001

using namespace std;

//시간 복잡도: O(mlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: 이분 탐색(반복문), STL sort
//사용한 자료구조: 1차원 배열


int n, m, num;
int d[max_val];


//이분 탐색 재귀적 구현
bool binary_search(int val){
    
    int start = 0;
    int end = n;
    int mid = 0;
    
    while(start <= end){
        
        mid = (start + end)/2;
        
        if(d[mid] == val) return true;
        else if(d[mid] < val) start = mid + 1;
        else end = mid - 1;
        
    }
    
    return false;
}


int main(){
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) scanf("%d", &d[i]);
    
    sort(d, d+n);
    
    scanf("%d", &m);
    
    for(int i=0; i<m; i++){
        scanf("%d", &num);
        printf("%d\n", binary_search(num));
    }
}
