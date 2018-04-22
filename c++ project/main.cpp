#include <iostream>
#include <algorithm>

using namespace std;

int d[100];

int person = 1;
int score = -1;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> d[i];
    }
    
    for(int k=0; k<m; k++){
        int sum = 0;
        int num = 0;
        cin >> num;
        
        for(int i=0; i<n; i++){
            char c;
            cin >> c;
            
            if(c== 'O'){
                sum = sum + d[i];
            }
        }
        
        if(sum > score){
            person = num;
            score = sum;
        }else if(sum == score){
            person = min(person, num);
        }
        
    }
    
    cout << person << " " << score << endl;
    
}
