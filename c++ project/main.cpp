#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int d[101][101];
bool check[101][101];
int n, l;
int cnt = 0;

int main(){

    cin >> n >> l;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
        }
    }
    
    
    // 가로 검사
    for(int i=0; i<n; i++){
        int current_height = d[i][0];
        int start_index = 0;
        int change_index = 0;
        int is_possible = true;
        for(int j=1; j<n; j++){
            
            // 높이 차이가 1인지 검사
            if(d[i][j] != current_height){
                int diff = abs(d[i][j] - current_height);
                if(diff != 1){
                    is_possible = false;
                    break;
                }
            }
            
            // 올라가자
            if(current_height < d[i][j]){
                change_index = j;
                
                //길이 계산
                if(change_index - start_index < l){
                    is_possible = false;
                    break;
                }
                
                //활주로 건설되어 있는지 검사
                for(int k=0; k<l; k++){
                    if(check[i][change_index-1-k] != false){
                        is_possible = false;
                        break;
                    }else{
                        check[i][change_index-1-k] = true;
                    }

                }
                
                start_index = j;
                current_height = d[i][j];
            }
            
            //내려가자
            else if( current_height > d[i][j]){
                change_index = j;
                for(int k=0; k<l; k++){

                    if(check[i][change_index+k] != false){
                        is_possible = false;
                        break;
                    }else{
                        check[i][change_index+k] = true;
                    }
                    
                    if(d[i][change_index] != d[i][change_index+k]){
                        is_possible = false;
                        break;
                    }
                }
                start_index = j;
                current_height = d[i][j];
            }
            
            
            if(j==n-1){
                if(is_possible == true){
//                    cout << "가로 검사 " << i << endl;
                    cnt++;
                }
            }
        }
    }

    memset(check, false, sizeof(check));
    //세로 검사
    for(int j=0; j<n; j++){
        int current_height = d[0][j];
        int start_index = 0;
        int change_index = 0;
        int is_possible = true;
        for(int i=1; i<n; i++){
            
            // 높이 차이가 1인지 검사
            if(d[i][j] != current_height){
                int diff = abs(d[i][j] - current_height);
                if(diff != 1){
                    is_possible = false;
                    break;
                }
            }
            
            // 올라가자
            if(current_height < d[i][j]){
                change_index = i;
                
                //길이 계산
                if(change_index - start_index < l){
                    is_possible = false;
                    break;
                }
                
                //활주로 건설되어 있는지 검사
                for(int k=0; k<l; k++){
                    if(check[change_index-1-k][j] != false){
                        is_possible = false;
                        break;
                    }else{
                        check[change_index-1-k][j] = true;
                    }
                    
                }
                
                start_index = i;
                current_height = d[i][j];
            }
            
            //내려가자
            else if( current_height > d[i][j]){
                change_index = i;
                for(int k=0; k<l; k++){
                    
                    if(check[change_index+k][j] != false){
                        is_possible = false;
                        break;
                    }else{
                        check[change_index+k][j] = true;
                    }
                    
                    if(d[change_index][j] != d[change_index+k][j]){
                        is_possible = false;
                        break;
                    }
                }
                start_index = i;
                current_height = d[i][j];
            }
            
            
            if(i==n-1){
                if(is_possible == true){
//                    cout << "세로 검사 " << j << endl;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    
}
