#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int n, num;
int a[10001];

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        a[num]++;
    }

    for(int i=1; i<=10000; i++){
        if(a[i] > 0){
            for(int j=1; j<=a[i]; j++){
                printf("%d\n", i);
            }
        }
    }
}