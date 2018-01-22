#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    while(true){
        
        vector<int> v(3);
        for(int i=0; i<3; i++){
            cin >> v[i];
        }
        
        if(v[0] == 0 || v[1] == 0 || v[2] == 0){
            break;
        }
        
        sort(v.begin(), v.end());
        
        if(v[2] >= v[0] + v[1]){
            
            cout << "Invalid" << endl;
            
        }else{

            if(v[0] == v[1] && v[1] == v[2]){
                cout << "Equilateral" << endl;
            }else if(v[0] != v[1] && v[1] != v[2] && v[0] != v[2]){
                cout << "Scalene" << endl;
            }else{
                cout << "Isosceles" << endl;
            }
            
        }
    }
    
    
}
