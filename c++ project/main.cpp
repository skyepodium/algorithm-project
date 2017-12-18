#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    while(t--){
        
        int people_num, chair_num;
        cin >> people_num >> chair_num ;
        
        bool *check;
        check = new bool[chair_num];
        
        for(int i=0; i<chair_num; i++){
            check[i] = true;
        }
        
        int cnt = 0;
        for(int i=0; i<people_num; i++){
            int a;
            cin >> a;
            if(check[a-1]){
                check[a-1] = false;
            }else{
                cnt++;
            }
        }
        cout << cnt <<endl;
        
    }

}

