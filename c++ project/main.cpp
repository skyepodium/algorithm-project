#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    while(n--){
        string word;
        cin >> word;
        
        int size = (int)word.size();
        cout<<word[0]<<word[size-1]<<endl;
    }
}
