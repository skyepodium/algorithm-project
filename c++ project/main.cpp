#include <iostream>

using namespace std;

int main(){
 
    int d[5] = {5, 2, 3, 4, 1};
    
    for(int i=0; i<5; i++){
        for(int j=1; j<5-i; j++){
            if(d[j-1] > d[j]){
                int temp;
                temp = d[j-1];
                d[j-1] = d[j];
                d[j] = temp;
            }
        }
    }
    
    
    for(int i=0; i<5; i++){
        cout << d[i] << endl;
    }
}
