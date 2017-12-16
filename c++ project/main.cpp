#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector<int> v;
    
    int a, b, c, d;
    int sum = 0;
    for(int i=0; i<5; i++){
        cin >> a >> b >> c >> d;
        sum = a+b+c+d;
        v.push_back(sum);
    }
    
    int max = v[0];
    int index = 0;
    for(int i=1; i<v.size(); i++){
        if(max<v[i]){
            max = v[i];
            index = i;
        }
    }
    cout<<index+1<<" "<<max<<endl;
    
}
