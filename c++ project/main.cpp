#include <iostream>

using namespace std;

int main(){
    int chang = 100, sang = 100;
    int n;
    int a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a>b){
            sang = sang - a;
        }else if(a<b){
            chang = chang - b;
        }
    }
    
    cout<<chang<<endl;
    cout<<sang<<endl;
}

