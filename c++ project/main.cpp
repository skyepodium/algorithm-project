#include <iostream>
#include <map>

#define max_int 100001
using namespace std;

int t, n;
int d[max_int*2];
int num[max_int*2];
char a[21];
char b[21];

int find(int node){
    if(d[node] == node) return node;
    else return d[node] = find(d[node]);
}

int merge(int x, int y){
    
    x = find(x);
    y = find(y);
    
    if(x != y){
        d[x] = y;
        num[y] += num[x];
        num[x] = 1;
    }
    
    return num[y];
}


int main(){
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
        
        for(int i=1; i<=2*n; i++){
            d[i] = i;
            num[i] = 1;
        }
        
        int idx = 1;
        map<string, int> mp;
        for(int i=0; i<n; i++){
            scanf("%s %s", a, b);
            
            if(mp.count(a) == 0){
                mp[a] = idx++;
            }

            if(mp.count(b) == 0){
                mp[b] = idx++;
            }

            printf("%d\n", merge(mp[a], mp[b]));
        }
    }
}
