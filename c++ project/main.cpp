#include <iostream>

using namespace std;

int n, a, b;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", (a*b)/gcd(a, b));
    }

}