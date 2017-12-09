#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v;
    
    while(n>0){
        v.push_back(n%2);
        n = n/2;
    }
    
    int result = 0;
    int mul_num = 1;
    int size = (int)v.size();
    for(int i= size-1; i>=0; i--){
        result = result + v[i]*mul_num;
        mul_num = mul_num*2;
    }
    cout << result << endl;
}
