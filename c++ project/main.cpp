#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);

    cout << arr[0] <<" ";
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
           cout << arr[i] <<" ";
        }
    }
    cout << endl;

}
