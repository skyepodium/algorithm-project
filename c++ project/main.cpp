#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(1)
//사용한 알고리즘: 선형 탐색
//사용한 자료구조: 1차원 배열

void cal_clap(int a){

    int origin_num = a;
    int clap_num = 0;
    
    while(a>0){
        //각 자릿수 검사
        int b = a%10;
        
        //만약 숫자가 3또는 6또는 9이면 박수횟수 증가
        if(b==3 || b==6 || b==9) clap_num++;
        
        a = a/10;
    }
    
    if(clap_num == 1) cout << "- ";
    else if(clap_num == 0) cout << origin_num << " ";
    else{
        for(int i=0; i<clap_num; i++){
            cout << "-";
        }
        cout << " ";
    }
    
}

int main(){
    
    int n;
    cin >> n;
    
    //for문으로 n번까지 검사
    for(int i=1; i<=n; i++){
        
        //박수횟수 검사
        cal_clap(i);
    }
    cout << endl;
}
