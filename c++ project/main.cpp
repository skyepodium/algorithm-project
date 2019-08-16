#include <iostream>

using namespace std;

int s, k, h, minNum;

int min(int a, int b){
    return a > b ? b : a;
}

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int main(){
    scanf("%d %d %d", &s, &k, &h);
    minNum = min3(s, k, h);
    
    
    if(s + k + h >= 100){
        printf("OK\n");
    }
    else{
        if(minNum == s) printf("Soongsil\n");
        else if(minNum == k) printf("Korea\n");
        else if(minNum == h) printf("Hanyang\n");
    }
    
}
