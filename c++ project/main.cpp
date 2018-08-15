#include <iostream>

using namespace std;

//시간 복잡도: O(??)
//공간 복잡도: O(10)
//사용한 알고리즘: 반복문
//사용한 자료구조: 1차원 배열

bool d[10];
bool is_complete = false;
int mul_num = 1;
int num;

void check_num(int a){
    
    while(a>0){
        d[a%10] = true;
        a = a/10;
    }
}

void check_complete(){
    bool check_complete = true;
    for(int i=0; i<10; i++){
        if(d[i] == false) check_complete = false;
    }
    
    if(check_complete) is_complete = true;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i=0; i<10; i++) d[i] = false;
        is_complete = false;
        mul_num = 1;
        cin >> num;
        
        while(is_complete == false){
            check_num(num*mul_num);
            mul_num++;
            check_complete();
        }
        
        cout << "#" << test_case << " "  << num * (mul_num-1) << endl;
    }
    return 0;
}
