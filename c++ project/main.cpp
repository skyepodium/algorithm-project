#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int d[9][9];
bool check[10];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cin >> d[i][j];
            }
        }
        
        bool is_true = true;
        
        //가로 검사
        for(int i=0; i<9; i++){
            memset(check, false, sizeof(check));
            for(int j=0; j<9; j++){
                if(check[d[i][j]] == false) check[d[i][j]] = true;
                else{
                    is_true = false;
                    break;
                }
            }
        }

        //세로 검사
        if(is_true){
            for(int j=0; j<9; j++){
                memset(check, false, sizeof(check));
                for(int i=0; i<9; i++){
                    if(check[d[i][j]] == false) check[d[i][j]] = true;
                    else{
                        is_true = false;
                        break;
                    }
                }
            }
        }

        vector<pair<int, int>> v;
        v.push_back(make_pair(0, 0));
        v.push_back(make_pair(0, 3));
        v.push_back(make_pair(0, 6));
        v.push_back(make_pair(3, 0));
        v.push_back(make_pair(3, 3));
        v.push_back(make_pair(3, 6));
        v.push_back(make_pair(6, 0));
        v.push_back(make_pair(6, 3));
        v.push_back(make_pair(6, 6));

        //네모 검사
        if(is_true){
            
            for(int k=0; k<9; k++){
                
                int x = v[k].first;
                int y = v[k].second;
                
                memset(check, false, sizeof(check));
                for(int i=x; i<x+3; i++){
                    for(int j=y; j<y+3; j++){
                        if(check[d[i][j]] == false) check[d[i][j]] = true;
                        else{
                            is_true = false;
                            break;
                        }
                    }
                }
            }
        }
        
        cout << "#" << test_case << " ";
        if(is_true) cout << 1 << endl;
        else cout << 0 << endl;
        
        
    }
    return 0;
}
