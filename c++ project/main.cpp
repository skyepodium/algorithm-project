#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int t;
    string word1, word2;
    cin >> t;
    
    while(t--){
        cin >> word1 >> word2;
        
        cout <<"Distances: ";
        for(int i=0; i < word1.size(); i++){

            if(word1[i] < word2[i]){
                
                printf("%d ", word2[i] - word1[i]);
                
            }else if(word1[i] > word2[i]){
                
                printf("%d ", (word2[i] + 26) - word1[i]);
                
            }else{
                printf("%d ", word2[i] - word1[i]);
                
            }
            
        }
        cout<<endl;
        
    }
}
