#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: Brute Force Search
//사용한 자료구조: 배열

bool check[10];
int base = 100;
int last = 0;

int check_number(int n){
    
    if(n == 0){
        if(check[0]){
            return 1;
        }else{
            return -1;
        }
    }
    
    if(n == 100){
        return 0;
    }
    
    int cnt = 0;
    while(n>0){
        if(!check[n%10]){
            return -1;
        }else{
            n /= 10;
            cnt++;
        }
    }
    
    return cnt;
}


int main(){

    int n;
    cin >> last >> n;
    
    for(int i=0; i<10; i++){
        check[i] = true;
    }
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        check[a] = false;
    }
    
    int pressed = 0, result = 0, min_value = 1000000;
    
    for(int i=0; i<=1000000; i++){
        pressed = check_number(i);
        if(pressed > -1){
            result = abs(last-i) + pressed;
            min_value = min(result, min_value);
        }
    }

    cout << min_value << endl;
}


