#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    stack<int> s;
    while(n>0){
        s.push(n%2);
        n = n/2;
    }

    vector<int> d;
    while(!s.empty()){
        d.push_back(s.top());
        s.pop();
    }
    
    
    do{
        
        for(int i=0; i<d.size(); i++){
            cout << d[i] << " ";
        }
        cout << endl;
        
        
    }while(next_permutation(d.begin(), d.end()));
}
