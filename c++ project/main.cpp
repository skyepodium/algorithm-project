#include <iostream>
#include <string>

using namespace std;

void eratos(int a){
  
    bool *check = new bool[a+1];
    for(int i=1; i<=a; i++){
        check[i] = true;
    }
    
    for(int i=2; i*i<=a; i++){
        for(int j=i*i; j<=a; j=j+i){
            check[j] = false;
        }
    }
    
    if(check[a]){
        cout<<"It is a prime word."<<endl;
    }else{
        cout<<"It is not a prime word."<<endl;
    }
}


int main() {
    
    string word;
    cin >> word;
    
    int sum =0 ;
    
    for(int i=0; i<word.size(); i++){
        if((int)word[i] >= 97){
            sum = sum + (int)word[i] - 96;
        }else{
            sum = sum + (int)word[i] - 38;
        }
    }
    eratos(sum);
}



