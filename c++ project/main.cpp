#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: 0
//사용한 알고리즘: Brute Force Search
//사용한 자료구조: 배열

bool check[10];
int base = 100;
int last = 0;

int check_number(int n){
    
    if(n == 0){
        if(check[0]){//버튼 0이 고장나지 않았을때
            return 1;
        }else{//버튼 0이 고장 났을때
            return -1;
        }
    }
    
    if(n == 100){//이동하고자 하는 채널이 0이면 cnt는 0이다.
        return 0;
    }
    
    int cnt = 0;
    while(n>0){
        if(!check[n%10]){//버튼이 고장났으면 1을 바로 리턴한다.
            return -1;
        }else{//이동하고자 하는 채널의 버튼이 고장나지 않았으면 누르는 cnt를 계산한다.
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
    
    for(int i=0; i<=1000000; i++){//채널은 무한대, 최악의 상황 999900일때, 위에서 내려올때 고려
        pressed = check_number(i);
        if(pressed > -1){//-1보다 클때로 정했다. 100일때는 아무것도 누르지 않기 때문에 0리턴
            result = abs(last-i) + pressed;
            min_value = min(result, min_value);
        }
    }

    cout << min_value << endl;
}


