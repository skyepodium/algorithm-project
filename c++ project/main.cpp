#include <iostream>
#include <algorithm>

#define max_val 500001

using namespace std;

//시간 복잡도: O(mlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: 이분 탐색(재귀), STL sort
//사용한 자료구조: 1차원 배열


int n, m, num;
int d[max_val];


//이분 탐색 재귀
bool binary_search(int val, int start, int end){
    
    if(start > end) return false;
    
    int mid = (start + end)/2;
    
    if(d[mid] == val) return true;
    else if(d[mid] < val) return binary_search(val, mid+1, end);
    else return binary_search(val, start, mid-1);
}


int main(){
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) scanf("%d", &d[i]);
    
    sort(d, d+n);
    
    scanf("%d", &m);
    
    for(int i=0; i<m; i++){
        scanf("%d", &num);
        printf("%d ", binary_search(num, 0, n));
    }
    printf("\n");
}
