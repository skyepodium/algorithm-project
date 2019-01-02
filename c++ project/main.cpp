#include <iostream>
#include <vector>
#define max_int 1000
using namespace std;

int t, num;
bool check[max_int];
int cnt[max_int];
vector<int> v;
void eratos(){
    check[1] = true;
    for(int i=2; i<=max_int-1; i++){
        for(int j=i*2; j<=max_int-1; j=j+i){
            check[j] = true;
        }
    }
    for(int i=2; i<max_int-1; i++){
        if(check[i] == false) v.push_back(i);
    }

}

int main(){
    scanf("%d", &t);
    eratos();

    int size = (int)v.size();
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            for(int k=j; k<size; k++){
                int temp = v[i] + v[j] + v[k];
                if(temp <max_int){
                    cnt[temp]++;
                }
            }
        }
    }

    for(int test_case = 1; test_case<=t; test_case++){
        scanf("%d", &num);
        printf("#%d %d\n", test_case, cnt[num]);
    }
}