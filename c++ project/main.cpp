#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, n, q;
char base[8][8];
vector<int> result;
vector<vector<string>> question;
vector<vector<string>> v;
void rotate(int idx){
    char temp[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            temp[j][7-i] = v[idx][i][j];
        }
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            v[idx][i][j] = temp[i][j];
        }
    }
}


bool do_test(int q_idx, int f_idx){
    memset(base, '.', sizeof(base));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) {
            if (v[f_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[f_idx][i][j];
        }
    }

    bool flag = true;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(base[i][j] == '.') base[i][j] ='W';
            if(question[q_idx][i][j] != base[i][j]){
                flag = false;
                break;
            }
        }
    }

    return flag;
}

bool do_test2(int q_idx, int f_idx, int s_idx){
    memset(base, '.', sizeof(base));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) {
            if (v[f_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[f_idx][i][j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (v[s_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[s_idx][i][j];
        }
    }

    bool flag = true;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(base[i][j] == '.') base[i][j] ='W';
            if(question[q_idx][i][j] != base[i][j]){
                flag = false;
                break;
            }
        }
    }

    return flag;
}

bool do_test3(int q_idx, int f_idx, int s_idx, int t_idx){
    memset(base, '.', sizeof(base));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) {
            if (v[f_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[f_idx][i][j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (v[s_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[s_idx][i][j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (v[t_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[t_idx][i][j];
        }
    }



    bool flag = true;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(base[i][j] == '.') base[i][j] ='W';
            if(question[q_idx][i][j] != base[i][j]){
                flag = false;
                break;
            }
        }
    }

//    if(flag){
//        for(int i=0; i<8; i++){
//            for(int j=0; j<8; j++){
//                printf("%c", base[i][j]);
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }

    return flag;
}

bool do_test4(int q_idx, int f_idx, int s_idx, int t_idx, int w_idx){
    memset(base, '.', sizeof(base));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) {
            if (v[f_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[f_idx][i][j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (v[s_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[s_idx][i][j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (v[t_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[t_idx][i][j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (v[w_idx][i][j] == '.' && base[i][j] != '.') continue;
            base[i][j] = v[w_idx][i][j];
        }
    }

    bool flag = true;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(base[i][j] == '.') base[i][j] ='W';
            if(question[q_idx][i][j] != base[i][j]){
                flag = false;
                break;
            }
        }
    }

    return flag;
}

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        // 1. 도형판 입력
        scanf("%d", &n);
        for(int idx=0; idx<n; idx++){
            vector<string> tmp;
            for(int i=0; i<8; i++){
                string word;
                cin >> word;
                tmp.push_back(word);
            }
            v.push_back(tmp);
        }

        // 2. 문제 입력
        scanf("%d", &q);
        for(int idx = 0; idx<q; idx++){
            vector<string> tmp;
            for(int i=0; i<8; i++){
                string word;
                cin >> word;
                tmp.push_back(word);
            }
            question.push_back(tmp);
        }


        // 3. 문제 하나씩 검토
        for(int idx=0; idx<question.size(); idx++){
            bool find = false;

            for(int i=0; i<n; i++){
                for(int a=0; a<4; a++){
                    rotate(i);
                    if(do_test(idx, i)){
                        if(!find){
                            find = true;
                            result.push_back(1);
                            result.push_back(i+1);
                        }
                    }
                }
            }

            // 3) 2개 사용 시작
            if(find) continue;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) continue;

                        for(int a=0; a<4; a++){
                            rotate(i);
                            for(int b=0; b<4; b++){
                                rotate(j);
                                    if(do_test2(idx, i, j)){
                                        if(!find){
                                            find = true;
                                            result.push_back(2);
                                            result.push_back(i+1);
                                            result.push_back(j+1);
                                        }
                                    }
                            }
                        }
                }
            }
            // 3) 2개 사용 끝

            // 3) 3개 사용 시작
            if(find) continue;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) continue;
                    for(int k=0; k<n; k++){
                        if(i==k || j==k ) continue;

                        for(int a=0; a<4; a++){
                            rotate(i);
                            for(int b=0; b<4; b++){
                                rotate(j);
                                for(int c=0; c<4; c++){
                                    rotate(k);
                                    if(do_test3(idx, i, j, k)){
                                        if(!find){
                                            find = true;
                                            result.push_back(3);
                                            result.push_back(i+1);
                                            result.push_back(j+1);
                                            result.push_back(k+1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            // 3) 3개 사용 끝

            // 3) 4개 사용 시작
            if(find) continue;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) continue;
                    for(int k=0; k<n; k++){
                        if(i==k || j==k ) continue;
                        for(int l=0; l<n; l++){
                            if(i==l || j==l || k==l ) continue;

                            for(int a=0; a<4; a++){
                                rotate(i);
                                for(int b=0; b<4; b++){
                                    rotate(j);
                                    for(int c=0; c<4; c++){
                                        rotate(k);
                                        for(int d=0; d<4; d++){

                                            if(do_test4(idx, i, j, k, l)){
                                                if(!find){
                                                    find = true;
                                                    result.push_back(3);
                                                    result.push_back(i+1);
                                                    result.push_back(j+1);
                                                    result.push_back(k+1);
                                                    result.push_back(l+1);

                                                }
                                            }

                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }
            // 3) 4개 사용 끝
        }
    printf("#%d ", test_case);
    for(int i=0; i<result.size(); i++){
        printf("%d ", result[i]);
    }
    printf("\n");

    }
}