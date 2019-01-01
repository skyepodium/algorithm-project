#include <iostream>
#include <vector>

using namespace std;

int a, b, n, temp, num;

int main(){
    scanf("%d %d %d", &a, &b, &n);

    num = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        num = num * a + temp;
    }

    vector<int> v;
    while(num>0){
        v.push_back(num%b);
        num /= b;
    }

    for(int i=(int)v.size()-1; i>=0; i--){
        printf("%d ", v[i]);
    }
}