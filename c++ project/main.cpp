#include <iostream>
#include <vector>

#define max_int 10000001

using namespace std;
int n;
vector<int> v;
bool check[max_int];
void eratos(){
    for(int i=2; i*i<=n; i++){
        for(int j=i*i; j<=n; j=j+i){
            check[j] = true;
        }
    }
}
int main(){
    scanf("%d", &n);
    eratos();
    for(int i=2; i<=n; i++){
        if(!check[i]) v.push_back(i);
    }

    for(int i=0; i<v.size(); i++){
        while(n%v[i] == 0){
            n /= v[i];
            printf("%d\n", v[i]);
        }
    }

}