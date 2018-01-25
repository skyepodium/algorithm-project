#include <iostream>

using namespace std;

int d[6] = {500, 100, 50, 10, 5, 1};

int main(){
    
    int n;
    cin >> n;
    
    int money = 1000-n;
    
    int cnt = 0;
    int i=0;
    while(money>0){

        if(money >= d[i]){
            money = money - d[i];
            cnt++ ;
        }else{
            i++;
        }

    }
    
    cout << cnt << endl;
    
}
