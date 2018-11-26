#include <iostream>
#include <vector>
#include <algorithm>

#define lld long long int
#define max_int 41
using namespace std;

int n, idx1, idx2;
lld s;
int a[max_int];
int b[max_int];
bool check1[1000001];
bool check2[1000001];
vector<lld> v;
vector<lld> w;

void go1(int index, lld sum){
    if(index == idx1+1){
        
        if(sum > 0){
            if(check1[sum] == false){
                check1[sum] = true;
                v.push_back(sum);
            }
        }
        else{
            if(sum != 0 && check2[sum*-1] == false){
                check2[sum*-1] = true;
                v.push_back(sum);
            }
        }
        
        return;
    }
    
    sum = sum + a[index];
    go1(index+1, sum);
    sum = sum - a[index];
    go1(index+1, sum);
}

void go2(int index, lld sum){
    if(index == idx2+1){
        
        if(sum > 0){
            if(check1[sum] == false){
                check1[sum] = true;
                w.push_back(sum);
            }
        }
        else{
            if(sum != 0 && check2[sum*-1] == false){
                check2[sum*-1] = true;
                w.push_back(sum);
            }
        }
        
        return;
    }
    
    sum = sum + b[index];
    go2(index+1, sum);
    sum = sum - b[index];
    go2(index+1, sum);
}

int binary_search(int num){
    int cnt = 0;
    int start = 0;
    int end = (int)w.size()-1;
    int mid = 0;
    
    while(start <= end){
        mid = (start+end)/2;
        
        if(w[mid] < num){
            start = mid + 1;
        }
        else if(w[mid] > num){
            end = mid - 1;
        }
        else{
            cnt++;
            start = mid + 1;
        }
    }
    
    return cnt;
}

int main(){
    scanf("%d %lld", &n, &s);
    
    idx1 = n/2;
    idx2 = n/2;
    if(n%2 == 1){
        idx1 = n/2;
        idx2 = n/2+1;
    }
    for(int i=0; i<idx1; i++) scanf("%d", &a[i]);
    for(int i=0; i<idx2; i++) scanf("%d", &b[i]);
    
    go1(0, 0);
    for(int i=0; i<=n; i++){
        check1[i] = false;
        check2[i] = false;
    }
    go2(0, 0);
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    int result = 0;
    for(int i=0; i<(int)v.size(); i++){
        result += binary_search(s-v[i]);
        result += binary_search(v[i]-s);
    }
    printf("%d\n", result);
}

