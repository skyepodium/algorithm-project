#include <iostream>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    int n;
    char problem_kind;
    while(t--){

        cin >> n >> problem_kind;
        
        if(problem_kind == 'C'){
            
            char ch;
            for(int i=0; i<n; i++){
                cin >> ch;
                printf("%d ", ch-64);
            }
            
        }else{
            
            int num;
            for(int i=0; i<n; i++){
                cin >> num;
                printf("%c ", num+64);
            }
            
        }
        cout<<endl;
    }
}
