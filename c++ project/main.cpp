#include <iostream>
#include <string>
using namespace std;

int t, n, drink, max_drink;
string name, max_name;

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        max_drink = 0;
        for(int i=0; i<n; i++){
            cin >> name >> drink;
            if(drink > max_drink){
                max_drink = drink;
                max_name = name;
            }
        }
        cout << max_name << "\n";
    }
}
