#include <iostream>

#define max_int 10001
using namespace std;

int n, m;
int a[max_int];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int left = 0;
    int right = 0;
    int cur = a[0];
    int cnt = 0;
    while(left < n && right < n){
        if(cur < m){
            right++;
            cur += a[right];
        }
        else if(cur > m){
            cur -= a[left];
            left++;
        }
        else{
            cnt++;
            cur -= a[left];
            left++;
        }
    }
    printf("%d\n", cnt);

}