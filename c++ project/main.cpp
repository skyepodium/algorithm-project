#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    while(n--){
        int t;
        cin >> t;
        
        int price;
        string name;
        int max_price = 0;
        string max_name;
        while(t--){
            cin>>price>>name;
            if(max_price == 0){
                max_price = price;
                max_name = name;
            }else{
                if(max_price < price){
                    max_price = price;
                    max_name = name;
                }
            }
        }
        cout<<max_name<<endl;
    }
}
