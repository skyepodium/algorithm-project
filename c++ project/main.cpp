#include <iostream>

using namespace std;

void cal_clap(int a){

    int origin_num = a;
    int clap_num = 0;
    
    while(a>0){
        int b = a%10;
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
    
    for(int i=1; i<=n; i++){
        cal_clap(i);
    }
    cout << endl;
}
