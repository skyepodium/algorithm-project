#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    
    vector<string> word_first(n);
    vector<string> word_second(n);
    
    for(int i=0; i<n; i++){
        cin >> word_first[i];
    }

    for(int i=0; i<n; i++){
        cin >> word_second[i];
    }

    
    bool is_result = true;
    for(int i=0; i<n; i++){
        int origin_index = 0;
        for(int j=0; j<2*m; j++){
            if(word_first[i][origin_index] != word_second[i][j]){
                is_result = false;
                break;
            }
            
            if(j%2 == 1){
                origin_index++;
            }
        }
    }
    
    if(is_result) cout << "Eyfa" << endl;
    else cout << "Not Eyfa" << endl;
    
}
