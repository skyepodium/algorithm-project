#include <iostream>
#include <algorithm>

int arr[9];

using namespace std;

void print_arr(int a, int b){
    
    for(int i=0; i<9; i++){
        if(i == a || i == b){
            continue;
        }else{
            cout << arr[i] << endl;
        }
    }
}

int main(){
    
    int sum = 0 ;
    for(int i=0; i<9; i++){
        cin >> arr[i];
        sum = sum + arr[i];
    }
    
    sort(arr, arr+9);
    
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sum - arr[i] - arr[j] == 100){
                print_arr(i, j);
                break;
            }
        }
    }
}

