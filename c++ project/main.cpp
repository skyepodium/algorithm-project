#include <iostream>

using namespace std;

int sum = 0;
int min_number = 0;


int main() {

    int a, b;
    cin >> a >> b;

    bool *check;
    check = new bool[b+1];
    check[1] = false;
    for(int i=2; i<=b; i++){
        check[i] = true;
    }
    
    for(int i=2; i*i<=b; i++){
        for(int j=i*i; j<=b; j=j+i){
            check[j] = false;
        }
    }

    for(int i=a; i<=b; i++){
        if(check[i] == true && sum == 0){
            min_number = i;
        }
        
        if(check[i]){
            sum = sum + i;
        }
    }
    
    if(sum == 0){
        cout<<-1<<endl;
    }else{
        cout<<sum<<endl;
        cout<<min_number<<endl;
    }
}
